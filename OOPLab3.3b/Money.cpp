#include "Money.h"
#include <iostream>
#include <sstream>

Money::Money() : grivnas(0), kopecks(0) {}

Money::Money(long gr, unsigned char kop) {
    if (kop >= 100) {
        throw std::invalid_argument("Kopecks should be less than 100.");
    }
    grivnas = gr;
    kopecks = kop;
}

long Money::getGrivnas() const {
    return grivnas;
}

unsigned char Money::getKopecks() const {
    return kopecks;
}

void Money::init(long gr, unsigned char kop) {
    if (kop >= 100) {
        throw std::invalid_argument("Kopecks should be less than 100.");
    }
    grivnas = gr;
    kopecks = kop;
}

void Money::read() {
    std::cout << "Enter grivnas: ";
    std::cin >> grivnas;
    std::cout << "Enter kopecks: ";
    std::cin >> kopecks;
    if (kopecks >= 100) {
        throw std::invalid_argument("Kopecks should be less than 100.");
    }
}

void Money::display() const {
    std::cout << "Grivnas: " << grivnas << ", Kopecks: " << static_cast<int>(kopecks) << std::endl;
}

Money Money::operator+(const Money& other) const {
    long totalGrivnas = grivnas + other.grivnas;
    unsigned char totalKopecks = kopecks + other.kopecks;
    if (totalKopecks >= 100) {
        totalKopecks -= 100;
        totalGrivnas++;
    }
    return Money(totalGrivnas, totalKopecks);
}

Money Money::operator/(double divisor) const {
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    double totalAmount = grivnas + kopecks / 100.0;
    totalAmount /= divisor;
    long newGrivnas = static_cast<long>(totalAmount);
    unsigned char newKopecks = static_cast<unsigned char>((totalAmount - newGrivnas) * 100);
    return Money(newGrivnas, newKopecks);
}

std::istream& operator>>(std::istream& in, Money& money) {
    in >> money.grivnas >> money.kopecks;
    if (money.kopecks >= 100) {
        throw std::invalid_argument("Kopecks should be less than 100.");
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Money& money) {
    out << money.grivnas << " grn " << static_cast<int>(money.kopecks) << " kop";
    return out;
}

std::string Money::toString() const {
    std::stringstream ss;
    ss << grivnas << " grn " << static_cast<int>(kopecks) << " kop";
    return ss.str();
}

Money makeMoney(long gr, unsigned char kop) {
    try {
        return Money(gr, kop);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
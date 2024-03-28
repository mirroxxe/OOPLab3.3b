#ifndef MONEY_H
#define MONEY_H

#include <stdexcept>
#include <string>

class Money {
private:
    long grivnas;
    unsigned char kopecks;

public:
    Money();
    Money(long gr, unsigned char kop);
    long getGrivnas() const;
    unsigned char getKopecks() const;
    void init(long gr, unsigned char kop);
    void read();
    void display() const;
    Money operator+(const Money& other) const;
    Money operator/(double divisor) const;

    friend std::istream& operator>>(std::istream& in, Money& money);
    friend std::ostream& operator<<(std::ostream& out, const Money& money);
    std::string toString() const;
};

Money makeMoney(long gr, unsigned char kop);

#endif 
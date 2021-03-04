#ifndef RATIONAL_H
#define RATIONAL_H
#include<iostream>
#include<cmath>
using namespace std;
class rational
{
    int a,b;
public:
    rational();
    rational(const int);
    rational(const rational&);
    int _gcd(int,int);
    void Compact();
    friend istream& operator >> (istream&,rational&);
    friend ostream& operator << (ostream&,rational);
    friend rational sqrt(rational);
    friend rational operator*(rational,rational);
    bool operator ==(rational);
    bool operator >=(rational);
    bool operator <(rational);
    rational operator+(rational);  
    rational operator/(rational);
    rational operator-();
    rational operator-(rational);

};

#endif // RATIONAL_H

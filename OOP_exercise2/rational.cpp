#include "rational.h"

rational::rational(){

}
rational::rational(const int k){
    a = k; b = 1;
}
rational::rational(const rational& r){
    a = r.a; b =r.b;
}
int rational::_gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return _gcd(b, a % b);
}
void rational::Compact(){
    int g = _gcd(a,b);
    a = a/g;
    b =b/g;
    if(b < 0){
        a *= -1; b *=-1;
    }
}
istream& operator >>(istream& is,rational& r){
    is >> r.a >> r.b;
    r.Compact();
    return is;
}
ostream& operator <<(ostream& os,rational r){
    os << r.a <<"/" << r.b;
    return os;
}
rational sqrt(rational r){
    rational tmp;
    tmp.a = sqrt(r.a);
    tmp.b = sqrt(r.b);
    tmp.Compact();
    return tmp;
}
bool rational::operator==(rational r){
    return (a == r.a) && (b == r.b);
}
bool rational::operator >=(rational r){
    rational tmp = (*this) - r;
    return (tmp.a * tmp.b >= 0);
}
bool rational::operator<(rational r){
    return (r >= (*this));
}
rational rational::operator+(rational r){
    rational tmp;
    tmp.a = a* r.b + b * r.a;
    tmp.b = b * r.b;
    tmp.Compact();
    return tmp;
}
rational operator*(rational r,rational p){
    rational tmp;
    tmp.a = r.a * p.a;
    tmp.b = r.b * p.b;
    tmp.Compact();
    return tmp;
}
rational rational::operator/(rational r){
    rational tmp;
    tmp.a = a * r.b;
    tmp.b = b * r.a;
    tmp.Compact();
    return tmp;
}
rational rational::operator-(){
    rational tmp;
    tmp.a = -a;
    tmp.b =b;
    return tmp;
}
rational rational::operator-(rational r){
    rational tmp;
    tmp.a = a* r.b - b * r.a;
    tmp.b = b * r.b;
    tmp.Compact();
    return tmp;
}

















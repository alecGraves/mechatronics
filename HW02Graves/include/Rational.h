#include <cstdio>
class Rational{
    int n, d; //numerator, denominator
public:
    Rational operator+(Rational R){return Rational(n*R.d+d*R.n, d*R.d);}
    Rational operator-(Rational R){return Rational(n*R.d-d*R.n, d*R.d);}
    Rational operator*(Rational R){return Rational(n*R.n, d*R.d);}
    Rational operator/(Rational R){return Rational(n*R.d, d*R.n);}
    Rational operator+(int i){return Rational(n+d*i, d);}
    Rational operator-(int i){return Rational(n-d*i, d);}
    Rational operator*(int i){return Rational(n*i, d);}
    Rational operator/(int i){return Rational(n, d*i);}
    int getNumer(){return n;}
    int getDenom(){return d;}
    void print(){printf("%d/%d\n", n, d);}
    Rational() :n(0),d(1) {}
    Rational(int N, int D) :n(N), d(D) {}
};
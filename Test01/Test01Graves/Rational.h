/**
Rational.h

contains a class for rational numbers with operations

Created by Alec Graves
*/
#include <iostream>
class Rational {
	int n, d; //numerator, denominator
	int gcf(int x, int y, int z) { return y && (z = x%y) ? gcf(y, z, 0) : y; }
	void reduce() { int f = gcf(n, d, 0); n /= f; d /= f; } //reduce
public:
	Rational operator+(Rational R) { return Rational(n*R.d + d*R.n, d*R.d); }
	Rational operator-(Rational R) { return Rational(n*R.d - d*R.n, d*R.d); }
	Rational operator*(Rational R) { return Rational(n*R.n, d*R.d); }
	Rational operator/(Rational R) { return Rational(n*R.d, d*R.n); }
	Rational operator+(int i) { return Rational(n + d*i, d); }
	Rational operator-(int i) { return Rational(n - d*i, d); }
	Rational operator*(int i) { return Rational(n*i, d); }
	Rational operator/(int i) { return Rational(n, d*i); }
	int getNumer() { return n; }
	int getDenom() { return d; }
	void print() { printf("%d/%d\n", n, d); }
	friend std::ostream& operator<<(std::ostream&, Rational);
	Rational() :n(0), d(1) {}
	Rational(int N, int D) :n(N), d(D) {}
};
std::ostream& operator<< (std::ostream& o, Rational t) {
	t.reduce();
	o << t.n << '/' << t.d;
	return o;
}
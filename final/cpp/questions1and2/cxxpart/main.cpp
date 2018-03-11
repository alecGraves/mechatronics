/**
cxxpart of the final
Author: Team Red
*/
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Polynomial {
public:
	vector<double> coeffs;
	friend ostream& operator<<(ostream& os, const Polynomial& dt);
	Polynomial operator+(Polynomial &g) {
		vector<double> c;
		int s1(coeffs.size()), s2(g.coeffs.size());
		for (int i(0); i < max(s1, s2); ++i) {
			c.push_back(0.0);
		}
		for (int i(0); i < s1; ++i) {
			c[i + max(s1, s2) - s1] += coeffs[i];
		}
		for (int i(0); i < s2; ++i) {
			c[i + max(s1, s2) - s2] += g.coeffs[i];
		}
		return Polynomial(c);
	}
	Polynomial(vector<double> c) {
		coeffs = c;
	}
	Polynomial(double c1, double c2, double c3) {
		coeffs.push_back(c1);
		coeffs.push_back(c2);
		coeffs.push_back(c3);
	}
	Polynomial(double c1, double c2) {
		coeffs.push_back(c1);
		coeffs.push_back(c2);
	}
	Polynomial(double c1) {
		coeffs.push_back(c1);
	}
};


ostream& operator<<(ostream& os, const Polynomial& p)
{
	for (int i(0); i < p.coeffs.size(); ++i) {
		if (i > 0)
			os << " + ";
		os << p.coeffs[i] << "x^" << (p.coeffs.size()-1)-i;
	}
	return os;
}

void problem_one() {
	cout << "This is problem 1:" << endl;
	string name;
	vector<string> names;
	while(true) {
		cout << "(type exit to end) Enter name " << names.size()+1 << ": ";
		cin >> name;
		if (name == "exit")
			break;
		names.push_back(name);
	}
	int numwinners(4);
	if (names.size() < 4)
		numwinners = names.size();
	for (int i(0); i < numwinners; ++i) {
		int choice(rand() % names.size());
		cout << "Number " << i + 1 << " winner: " << names[choice] << endl;
		names.erase(names.begin() + choice);
	}
}

void problem_two() {
	cout << "\nThis is problem 2:" << endl;
	Polynomial  p1(4, -2, 1), p2(4, 2);
	cout << p1 << " added to " << p2 << " gives " << p1 + p2 << endl;
	cout << p2 << " added to " << p1 << " gives " << p2 + p1 << endl;
}

int main(int argc, char **argv) {
	problem_one();
	system("pause");
	problem_two();
	system("pause");
}
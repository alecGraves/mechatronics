#include <iostream>
#include "Complex.h"

using namespace std;
// using namespace numbers;

int main(int argc, char **argv)
{
    numbers::Complex z1(1.4, 2.1), z2(-3.2, 4.6);

    numbers::Complex solution = z1*z2 + z1 / (z2 - z1);

    cout << solution.getReal() << " + " << solution.getImag() << "i" << endl;
}
#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;
using namespace numbers;

void TestComplex()
{
    Complex z1(1.4, 2.1), z2(-3.2, 4.6);

    cout << z1*z2 + z1 / (z2 - z1) << endl;
}

// struct to initialize and store an array of complex nums
struct ComplexArray
{
    Complex **array;
    const int r, j; // number of reals and imaginaries in map
    ComplexArray(double rStart, double rStop, double iStart, double iStop, int RealSamples=20, ImaginarySamples=24) //note: start/stop inclusive
        : r(RealSamples), i(ImaginarySamples)
    {
        array = new *Complex[j];
        for (int i(0); i < j; ++i)
        {
            array[i] = new Complex[r]
        }
        double Mr = (rStop - rStart) / (n - 1) //slope for linear mapping reals
        double Mi = 
        for (int i(0); i < n; ++i)
        {
            array[i].setVals() = m * i + start;
        }
    }
    ~ComplexArray()
    {
        delete[] array;
    }
};

int main(int argc, char **argv)
{
    TestComplex();

    ComplexArray c(-2, 18, 5);

    for (int i(0); i < c.n; ++i)
    {
        cout << c.array[i] << endl;
    }

}
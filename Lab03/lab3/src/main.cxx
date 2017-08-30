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
struct ComplexArray2D
{
    Complex **array;
    const int r, j; // number of reals and imaginaries in map
    void Display()
    {
        for(int i(0); i < j; ++i)
        {
            for (int k(0); k < r; ++k)
            {
                cout << array[i][k] << '\t';
            }
            cout << endl;
        }
    }
    ComplexArray2D(double iStart, double iStop, double rStart, double rStop, int ImaginarySamples, int RealSamples) //note: start/stop inclusive
        : r(RealSamples), j(ImaginarySamples)
        //first index: imaginary
        //second index: real
    {
        array = new Complex*[j];
        for (int i(0); i < j; ++i)
        {
            array[i] = new Complex[r];
        }
        double Mr = (rStop - rStart) / (r - 1); //slope for linear mapping reals
        double Mi = (iStop - iStart) / (j - 1) ;//slope for linear mapping imaginaries
        double imaginary;
        double real;
        for (int i(0); i < j; ++i)
        {
            imaginary = Mi * i + iStart;
            for (int k(0); k < r; ++k)
            {
                real = Mr * k + rStart;
                array[i][k].setVals(real, imaginary);
            }
        }
    }
    ~ComplexArray2D()
    {
        for (int i(0); i < j; ++i)
        {
            delete[] array[i];
        }
    }
};

int main(int argc, char **argv)
{
    TestComplex();

    ComplexArray2D c(-1.2, 1.2, -1.2, 1.2, 5, 5);

    c.Display();

}
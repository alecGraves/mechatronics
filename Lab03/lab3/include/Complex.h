#include <cmath>

namespace numbers
{

    class Complex
    {
        double r, i;//real and imaginary components of complex number

        public:
            //set the value of real and imaginary components of the complex number
            void setVals(double R, double I)
            {
                r = R; i = I;
            }

            //returns real component
            double getReal() const
            {
                return r;
            }
            
            //return simaginary component
            double getImag() const
            {
                return i;
            }

            //returns magnitude of the complex number
            double getMag() const
            {
                return sqrt(r*r + i*i);
            }

            //add 2 complex numbers
            inline Complex operator+(const Complex& C) const
            {
                return Complex(r + C.r, i + C.i);
            }

            //subtract two complex numbers
            inline Complex operator-(const Complex& C) const
            {
                return Complex(r - C.r, i - C.i);
            }

            //multiply two complex numbers
            inline Complex operator*(const Complex& C) const
            {
                return Complex(r*C.r - i*C.i, r*C.i + i*C.r);
            }

            //divide two complex numbers. computes recripical of second and multiplies
            inline Complex operator/(const Complex& C) const
            {
                double d(C.r*C.r + C.i*C.i); //denominator, time optimization
                return *this * Complex(C.r/d, -1*C.i/d);
            }

            friend inline std::ostream& operator<<(std::ostream&, const Complex&); //write C to output stram out

            friend inline Complex operator/(const double& X, const Complex C);// return recripical of C multiplied by scalar x

        Complex(double R=0, double I=0) : r(R), i(I) {}
    };

    inline std::ostream& operator<<(std::ostream& out, const Complex& C)
    {
        out << C.r << " + " << C.i << 'i';
        return out;
    }

    inline Complex operator/(double X, Complex C)
    {
        return Complex(X) / C;
    }

} // numbers namespace
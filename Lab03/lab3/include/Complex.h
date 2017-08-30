#include <cmath>

namespace numbers{

    class Complex{
        double r, i;//real and imaginary components of complex number

        public:
            //set the value of real and imaginary components of the complex number
            void setVals(double R, double I){
                r = R; i = I;
            }

            //returns real component
            const double getReal(){
                return r;
            }
            
            //return simaginary component
            const double getImag(){
                return i;
            }

            //returns magnitude of the complex number
            const double getMag(){
                return sqrt(r*r + i*i);
            }

            //add 2 complex numbers
            Complex operator+(Complex C){
                return Complex(r + C.r, i + C.i);
            }

            //subtract two complex numbers
            Complex operator-(Complex C){
                return Complex(r - C.r, i - C.i);
            }

            //multiply two complex numbers
            Complex operator*(Complex C){
                return Complex(r*C.r - i*C.i, r*C.i + i*C.r);
            }

            //divide two complex numbers. computes recripical of second and multiplies
            Complex operator/(Complex C){
                double d(C.r*C.r + C.i*C.i); //denominator, time optimization
                return *this * Complex(C.r/d, -1*C.i/d);
            }

            friend std::ostream& operator<<(std::ostream&, Complex&); //write C to output stram out

            friend Complex operator/(double X, Complex C);// return recripical of C multiplied by scalar x
        // Complex() : r(0), i(0) {}
        Complex(double R=0, double I=0) : r(R), i(I) {}
    };

    std::ostream& operator<<(std::ostream& out, Complex& C){
        out << C.r << " + " << C.i << 'i';
        return out;
    }

    Complex operator/(double X, Complex C){
        return Complex(X) / C;
    }

} // numbers namespace
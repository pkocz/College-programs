#ifndef COMPLEXNUMBERS
#define COMPLEXNUMBERS

#include <cmath>
#include <iostream>

namespace comp{
class Complex
{
private:
    double r;
    double imag;
public:
    Complex(double x = 0, double y = 0) { r = x; imag = y; }

    double re(void) const { return r; }
    double im(void) const { return imag; }
    double mod(void) const { return sqrt(r*r + imag*imag); }
    const Complex conj(void) const { return Complex(r, -imag); }
    double arg(void) const;

    //Overloading operators
    Complex operator-() const { return Complex(-r, -imag); }
    Complex operator+() const { return *this; }
    Complex operator++() { return Complex(++r, ++imag); }
    Complex operator++(int) { return Complex(r++, imag++); }
    Complex operator--() { return Complex(--r, --imag); }
    Complex operator--(int) { return Complex(r--, imag--); }

    Complex operator+=(const Complex& z) { return Complex(r + z.r, imag + z.imag); }
    Complex operator-=(const Complex& z) { return Complex(r - z.r, imag - z.imag); }
    Complex operator*=(const Complex& z) { return Complex(r*z.r - imag*z.imag, r*z.imag + imag*z.r);}
    Complex operator/=(const Complex& z) { return Complex((r*z.r + imag*z.imag)/(z.r*z.r + z.imag*z.imag), (imag*z.r - r*z.imag)/(z.r*z.r + z.imag*z.imag)); }

    friend Complex operator+(const Complex&, const Complex&);
    friend Complex operator-(const Complex&, const Complex&);
    friend Complex operator*(const Complex&, const Complex&);
    friend Complex operator/(const Complex&, const Complex&);

    friend bool operator==(const Complex&, const Complex&);
    friend bool operator!=(const Complex&, const Complex&);

    friend std::ostream& operator<<(std::ostream&, const Complex&);
    friend std::istream& operator>>(std::istream&, Complex&);
};


inline double Complex::arg() const
{
    if(Complex(r, imag).mod() == 0) return 0;
    if (imag >= 0.0)
       return acos(r/mod());
    else
        return 2*M_PI - acos(r/mod());
}


inline Complex operator+(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.r = z1.r + z2.r;
    result.imag = z1.imag + z2.imag;
    return result;
}

inline Complex operator-(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.r = z1.r - z2.r;
    result.imag = z1.imag - z2.imag;
    return result;
}

inline Complex operator*(const Complex& z1, const Complex& z2)
{
    Complex result;
    result.r = z1.r*z2.r - z1.imag*z2.imag;
    result.imag = z1.r*z2.imag + z1.imag*z2.r;
    return result;
}

inline Complex operator/(const Complex& z1, const Complex& z2)
{
    Complex result;

    if((z2.r*z2.r + z2.imag*z2.imag) == 0) return 0;
    result.r = (z1.r*z2.r + z1.imag*z2.imag)/(z2.r*z2.r + z2.imag*z2.imag);
    result.imag = (z1.imag*z2.r - z1.r*z2.imag)/(z2.r*z2.r + z2.imag*z2.imag);
    return result;
}

inline bool operator==(const Complex& z1, const Complex& z2)
{
    return (z1.r == z2.r && z1.imag == z2.imag);
}
inline bool operator!=(const Complex& z1, const Complex& z2)
{
    return (z1.r != z2.r && z1.imag != z2.imag);
}

inline std::ostream& operator<<(std::ostream& output, const Complex& z)
{
    output << "(" << z.r << " ";
    if (z.imag >= 0)
        output << "+ " << z.imag << "i)";
    else
        output << "- " << -z.imag << "i)";
    
    return output; 
}

inline std::istream& operator>>(std::istream& input, Complex& z)
{
    char c;

    input >> c >> z.r >> c >> z.imag >> c;
    if(!input)
        {std::cerr << "Error loading file: " << std::endl; exit(3);}
    return input;
}
}
#endif
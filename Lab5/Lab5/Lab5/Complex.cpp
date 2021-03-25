#include "complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
	real_data = real;
	imag_data = imag;
}

bool Complex::is_real() const {
	return imag() == 0;
}

double Complex::real() const {
	return real_data;
}

double Complex::imag() const {
	return imag_data;
}

double Complex::abs() const {
	return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
	return { real(), -imag() };
}


Complex& Complex::operator++()
{
	this->real_data++;
	return (*this);

}

Complex Complex::operator++(int)
{
	Complex copy(*this);
	++(*this);
	return copy;
}

Complex& Complex::operator--()
{
	this->real_data--;
	return (*this);
}

Complex Complex::operator--(int)
{
	Complex copy(*this);
	--(*this);
	return copy;
}

Complex operator+(const Complex& l, const Complex& r)
{
	Complex p{ l.real() + r.real(), l.imag() + r.imag() };
	return p;
}

Complex operator+(const Complex& l, double r)
{
	return Complex(l.real()+r,l.imag());
}


Complex operator*(const Complex& l, const Complex& r)
{
	Complex p{ l.real() * r.real() - l.imag() * r.imag() , l.real() * r.imag() + r.real() * l.imag() };

	return p;
}

Complex operator*(const Complex& l, double r)
{
	return Complex(l.real()*r,l.imag()*r);
}

Complex operator-(const Complex& l, const Complex& r)
{
	Complex p{ l.real() - r.real(), l.imag() - r.imag() };
	return p;
}

Complex operator-(const Complex& l, double r)
{
	return Complex(l.real() - r, l.imag());
}

Complex operator-(const Complex& obj)
{
	return Complex(-obj.real(),-obj.imag());
}

Complex& Complex::operator()(double r, double i)
{
	Complex x(r, i);
	return x;
}

bool operator==(const Complex& l, const Complex& r)
{
	return (l.real() == r.real()) && (l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
	return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
	if (complex.real() == 0 && complex.imag() != 0)
		out << complex.imag() << "i";
	else if (complex.real() != 0 && complex.imag() == 0)
		out << complex.real();
	else if (complex.real() != 0 && complex.imag() != 0)
	{ 
		if(complex.real() > 0 && complex.imag() > 0)
			out << complex.real() << " + " << complex.imag()<<"i";
		if (complex.real() < 0 && complex.imag() > 0)
			out <<complex.real() << " + " << complex.imag() << "i";
		if (complex.real() > 0 && complex.imag() < 0)
			out << complex.real() << " " << complex.imag() << "i";
		if (complex.real() < 0 && complex.imag() < 0)
			out << complex.real() << " " << complex.imag() << "i";
	}
	//out << complex.real() << ' ' << complex.imag();
	return out;
}

#include "Complex.h"

Complex::Complex()
{
	this->real = 0;
	this->imaginary = 0;
}

Complex::Complex(double newReal, double newImaginary)
{
	this->real = newReal;
	this->imaginary = newImaginary;
}

void Complex::print()
{
	if (imaginary >= 0)
	{
		std::cout << real << "+" << imaginary << "i" << std::endl;
	}
	else
	{
		std::cout << real << imaginary << "i" << std::endl;
	}
}

void Complex::setReal(double newReal)
{
	this->real = newReal;
}
double Complex::getReal() const
{
	return this->real;
}

void Complex::setImaginary(double newImaginary)
{
	this->imaginary = newImaginary;
}
double Complex::getImaginary() const
{
	return this->imaginary;
}

Complex Complex::operator+(const Complex& other)
{
	return Complex(this->real + other.real, this->imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other)
{
	return Complex(this->real - other.real, this->imaginary - other.imaginary);
}

Complex Complex::operator*(const Complex& other)
{
	return Complex(this->real * other.real - this->imaginary * other.imaginary, this->imaginary * other.real + this->real * other.imaginary);
}

Complex Complex::operator/(const Complex& other)
{
	Complex newComplex;
	if (other.real != 0 && other.imaginary != 0)
	{		
		newComplex.real = (this->real * other.real + this->imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
		newComplex.imaginary = (this->imaginary * other.real - this->real * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	}
	return newComplex;
}

Complex& Complex::operator=(const Complex& other)
{
	this->real = other.real;
	this->imaginary = other.imaginary;
	return *this;
}

Complex& Complex :: operator+=(const Complex& other)
{
	this->real += other.real;
	this->imaginary += other.imaginary;
	return *this;
}

Complex& Complex :: operator-=(const Complex& other)
{
	this->real -= other.real;
	this->imaginary -= other.imaginary;
	return *this;
}

Complex& Complex :: operator*=(const Complex& other)
{
	double rememberReal = this->real;
	this->real = this->real * other.real - this->imaginary * other.imaginary;
	this->imaginary = this->imaginary * other.real + rememberReal * other.imaginary;
	return *this;
}

Complex& Complex :: operator/=(const Complex& other)
{
	if (other.real != 0 && other.imaginary != 0)
	{
		double rememberReal = this->real;
		this->real = (this->real * other.real + this->imaginary * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
		this->imaginary = (this->imaginary * other.real - rememberReal * other.imaginary) / (other.real * other.real + other.imaginary * other.imaginary);
	}
	return *this;
}

bool Complex::operator==(Complex& other)
{
	return(this->real == other.real && this->imaginary == other.imaginary);
}

bool Complex::operator!=(Complex& other)
{
	return !(this->real == other.real && this->imaginary == other.imaginary);
}

double Complex::complexModulus()
{
	return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}

bool Complex::operator>=(Complex& other)
{
	Complex current = *this;
	return(current.complexModulus() >= other.complexModulus());
}

bool Complex::operator<=(Complex& other)
{
	Complex current = *this;
	return(current.complexModulus() <= other.complexModulus());
}

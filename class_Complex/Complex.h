#pragma once
#include <iostream>
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double newReal, double newImaginary);
	void print();
	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	Complex operator*(const Complex& other);
	Complex operator/(const Complex& other);
	Complex& operator=(const Complex& other);

	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);

	double complexModulus(); // if  z = a + bi is a complex number, this function calculates |z|
	bool operator>=(Complex& other); //comaparing 2 complex numbers by their modulus
	bool operator<=(Complex& other);
	bool operator==(Complex& other);
	bool operator!=(Complex& other);

	void setReal(double newReal);
	double getReal() const;
	void setImaginary(double newImaginary);
	double getImaginary() const;
};


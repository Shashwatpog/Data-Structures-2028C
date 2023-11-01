#include "ComplexNumber.h"
#include <iostream>
#include <cmath>
using namespace std;

ComplexNumber::ComplexNumber() : real(0.0), imaginary(0.0) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

double ComplexNumber::getReal() const {
    return real;
}

void ComplexNumber::setReal(double real) {
    this->real = real;
}

double ComplexNumber::getImaginary() const {
    return imaginary;
}

void ComplexNumber::setImaginary(double imaginary) {
    this->imaginary = imaginary;
}

void ComplexNumber::print() const {
    cout << real << (imaginary >= 0 ? " + " : " - ") << abs(imaginary) << "i" << endl;
}

void ComplexNumber::operator+=(const ComplexNumber& other) {
    this->real += other.real;
    this->imaginary += other.imaginary;
}

void ComplexNumber::operator-=(const ComplexNumber& other) {
    this->real -= other.real;
    this->imaginary -= other.imaginary;
}

void ComplexNumber::operator*=(double scalar) {
    this->real *= scalar;
        this->imaginary *= scalar;
}

 void ComplexNumber::operator/=(double scalar) {
    if (scalar != 0) {
        this->real /= scalar;
        this->imaginary /= scalar;
    }
    else {
        cout << "Division by zero error" << endl;
    }
}

bool ComplexNumber::operator==(const ComplexNumber& other) const {
    return (this->real == other.real) && (this->imaginary == other.imaginary);
}


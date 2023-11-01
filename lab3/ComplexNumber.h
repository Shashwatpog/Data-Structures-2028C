#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber {
private:
    double real;        // real part of complex num
    double imaginary;   // imaginary part of complex num

public:
    // Constructors
    ComplexNumber();  
    ComplexNumber(double real, double imaginary);  

    // Getters
    double getReal() const;  
    double getImaginary() const;
      
    //Setters  
    void setImaginary(double imaginary);  
    void setReal(double real);

    void print() const;  

    // overloading the operatorrs
    void operator+=(const ComplexNumber& other);  
    void operator-=(const ComplexNumber& other);  
    void operator*=(double scalar);  
    void operator/=(double scalar);  
    bool operator==(const ComplexNumber& other) const;  
};

#endif  // COMPLEXNUMBER_H



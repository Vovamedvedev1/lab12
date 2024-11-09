#include <iostream>
#include <fstream>
#include <cmath>
#include "lab12.h"

const Complex& Complex::_assign_operator(const Complex& other, type_operator t)
{
    double x;
    double y;
    switch (t)
    {
    case (iadd_operator):
        this->real+=other.real;
        this->im += other.im;
        break;
    case (ipop_operator):
        this->real-=other.real;
        this->im-= other.im;
        break;
    case (imul_operator):
        x = this->real*other.real-this->im*other.im;
        y = this->real*other.im+this->im*other.real;
        this->real = x;
        this->im = y;
        break;
    case (iddiv_operator):
        if (other.real==0 && other.im==0)
            throw "It cannot be divided by 0";
        x = (this->real*other.real + this->im * other.im)/(other.real*other.real+other.im*other.im);
        y = (this->im*other.real-this->real*other.im)/(other.real*other.real+other.im*other.im);
        this->real = x;
        this->im = y;
        break;
    }
    return *this;
}

Complex::Complex(double real, double im)
{
    this->real = real;
    this->im = im;
}
Complex::Complex(double a)
{
    this->real = a;
    this->im = a;
}
Complex::Complex(const Complex& other)
{
    if (this != &other)
    {
        this->real = other.real;
        this->im = other.im;
    }
}
double Complex::get_module() const
{
    return sqrt(pow(this->real,2)+pow(this->im,2));
}
Complex Complex::operator + (const Complex& other)
{
    return Complex(this->real + other.real, this->im + other.im);
}
Complex Complex::operator - (const Complex& other)
{
    return Complex(this->real - other.real, this->im - other.im);
}
Complex Complex::operator * (const Complex& other)
{
    return Complex(this->real*other.real-this->im*other.im, this->real*other.im + this->im*other.real);
}
Complex Complex::operator / (const Complex& other)
{
    if (other.real==0 && other.im==0)
        throw "It cannot be divided by 0";
    double real_a = (this->real*other.real + this->im * other.im)/(other.real*other.real+other.im*other.im);
    double im_b = (this->im*other.real-this->real*other.im)/(other.real*other.real+other.im*other.im);
    return Complex(real_a,im_b);
}
const Complex& Complex::operator = (const Complex& other)
{
    if (this!=&other)
    {
        this->real = other.real;
        this->im = other.im;
    }
    return *this;
}
const Complex& Complex::operator+= (const Complex& other)
{
    return this->_assign_operator(other, iadd_operator);
}
const Complex& Complex::operator-= (const Complex& other)
{
    return this->_assign_operator(other, ipop_operator);
}
const Complex& Complex::operator*= (const Complex& other)
{
    return this->_assign_operator(other, imul_operator);
}
const Complex& Complex::operator/= (const Complex& other)
{
    if (other.real==0 && other.im==0)
        throw "It cannot be divided by 0";
    return this->_assign_operator(other, iddiv_operator);
}
//Префиксная форма ин/(де)еримента
const Complex& Complex::operator++()
{
    return this->_assign_operator(1,iadd_operator);
}
const Complex& Complex::operator--()
{
    return this->_assign_operator(1,ipop_operator);
}
//Постфиксная форма ин/(де)еримента
Complex Complex::operator++(int)
{
    Complex temp(*this);
    this->_assign_operator(1,iadd_operator);
    return temp;
}
Complex Complex::operator--(int)
{
    Complex temp(*this);
    this->_assign_operator(1,ipop_operator);
    return temp;
}
bool Complex::operator > (const Complex& other)
{
    if (this->get_module() > other.get_module())
        return true;
    else
        return false;
}
bool Complex::operator < (const Complex& other)
{
    if (this->get_module() < other.get_module())
        return true;
    else
        return false;
}
bool Complex::operator==(const Complex& other)
{
    if (this->get_module() == other.get_module())
        return true;
    else
        return false;
}
bool Complex::operator!=(const Complex& other)
{
    if (this->get_module() != other.get_module())
        return true;
    else
        return false;
}

std::ostream& operator << (std::ostream &os, const Complex& c)
{
    if (c.im >= 0)
        os <<c.real<<"+"<<c.im<<"i";
    else
        os <<c.real<<c.im<<"i";
    return os;
}
std::istream& operator >> (std::istream &in, Complex& c)
{
    std::cout << "---------------------Complex Enter------------------------------------" << std::endl;
    std::cout << "Enter real:   "; in >> c.real;
    std::cout << "Enter im:   "; in >> c.im;
    return in;
}

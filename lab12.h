#ifndef LAB12_H_INCLUDED
#define LAB12_H_INCLUDED

enum type_operator {iadd_operator, ipop_operator, imul_operator, iddiv_operator};
class Complex
{
private:
    double real {0};
    double im {0};
    const Complex& _assign_operator(const Complex& other, type_operator t);
public:
    Complex() = default;
    Complex(double real, double im);
    Complex(double a);
    Complex(const Complex& other);
    double get_module() const;
    Complex operator + (const Complex& other);
    Complex operator - (const Complex& other);
    Complex operator * (const Complex& other);
    Complex operator / (const Complex& other);
    const Complex& operator = (const Complex& other);
    const Complex& operator+= (const Complex& other);
    const Complex& operator-= (const Complex& other);
    const Complex& operator*= (const Complex& other);
    const Complex& operator/= (const Complex& other);
    //Префиксная форма ин/(де)еримента
    const Complex& operator++();
    const Complex& operator--();
    //Постфиксная форма ин/(де)еримента
    Complex operator++(int);
    Complex operator--(int);
    bool operator > (const Complex& other);
    bool operator < (const Complex& other);
    bool operator==(const Complex& other);
    bool operator!=(const Complex& other);
    friend std::ostream& operator << (std::ostream &, const Complex &);
    friend std::istream& operator >> (std::istream &in, Complex &);
};


#endif // LAB12_H_INCLUDED

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <vector>

class Complex{
	private:
		double abs;
		double img;
	public:
		Complex(double = 0, double = 0);
		Complex operator +(const Complex &other);
		Complex operator -(const Complex &other);
		Complex operator *(const Complex &other);
		Complex operator *(double abs_value);
		double absolute_value();
		friend std::ostream &operator <<(std::ostream &os, const Complex &number);
		friend std::istream &operator >>(std::istream &is, Complex &number);
};
void sort(std::vector <Complex>& arr);

#endif	

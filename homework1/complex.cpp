#include "complex.h"
#include <cmath>
Complex::Complex(double abs, double img) : abs(abs), img(img) {};
double Complex::absolute_value(){
	double res = sqrt(abs*abs + img*img);
	return res;
}
Complex Complex::operator +(const Complex &other)
{
	Complex sum;
	sum.abs = abs + other.abs;
	sum.img = img + other.img;
	return sum;
}
Complex Complex::operator -(const Complex &other){
	Complex diff;
	diff.abs = abs - other.abs;
	diff.img = img - other.img;
	return diff;
}
Complex Complex::operator *(const Complex &other){
	Complex mult;
	mult.abs = abs * other.abs - img * other.img;
	mult.img = abs * other.img + img * other.abs;
	return mult;
}
Complex Complex::operator *(double abs_value){
	Complex mult;
	mult.abs = abs_value * abs;
	mult.img = abs_value * img;
	return mult;
}
std::ostream& operator <<(std::ostream& os, const Complex &number){
	if(number.img < 0)
		os << number.abs << " " << number.img << "i";
	else if(number.img == 0 && number.abs != 0)
		os << number.abs << " ";
	else if(number.abs == 0 && number.img != 0)
		os << number.img << "i";
	else
		os << number.abs << " + " << number.img << "i";
	return os;
}
std::istream& operator >>(std::istream& is, Complex &number){
	std::cout << "Insert the absolute value\n";
	is >> number.abs;
	std::cout << "Enter the imaginary value";
	is >> number.img;
	return is;
}
void sort(std::vector <Complex>& arr){
	for(std::size_t i = 0; i < arr.size() - 1; i++){
		for(std::size_t j = 0; j < arr.size() - i - 1; j++){
			if(arr[j].absolute_value() > arr[j + 1].absolute_value())
				std::swap(arr[j], arr[j + 1]);
		}
	}
}

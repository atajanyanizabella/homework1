#include "complex.h"
#include <vector>
int main(){
	Complex num1;
	std::cin >> num1;
	Complex num2;
	std::cin >> num2;
	Complex num3;
	std::cin >> num3;
	std::vector <Complex> array;
	array.push_back(num1);
	array.push_back(num2);
	array.push_back(num3);
	sort(array);
	for(std::size_t i = 0; i < array.size(); ++i)
		std::cout << array[i] << "\n";
	return 0;
}

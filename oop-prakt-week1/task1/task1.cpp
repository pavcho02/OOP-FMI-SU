#include <iostream>
using namespace std;

struct ComplexNumber
{
	double realPart;
	double imPart;
};

ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2)
{
	return ComplexNumber{ (num1.realPart + num2.realPart), (num1.imPart, num2.imPart) };
}

void print(const ComplexNumber& number)
{
	cout << number.realPart << " + " << number.imPart << "i";
}

int main()
{
	ComplexNumber num1;
	num1.realPart = 10;
	num1.imPart = 2;
	ComplexNumber num2;
	num2.realPart = 5;
	num2.imPart = 4;
	ComplexNumber result = sum(num1, num2);
	print(num1);
	cout << endl;
	print(num2);
	cout << endl;
	print(result);
	cout << endl;
	return 0;
}
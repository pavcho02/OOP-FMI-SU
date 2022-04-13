#include"Rational.h"
#include<iostream>

int Rational::nok(const int a, const int b) const
{
	return (a * b) / nod(a, b);
}

int Rational::nod(int a, int b) const
{
	if (b == 0)
		return a;
	return nod(b, a % b);
}

Rational::Rational()
{
	numerator = 0;
	denumerator = 0;
}

Rational::Rational(const int num, const int denum)
{
	numerator = num;
	denumerator = denum;
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenumerator() const
{
	return denumerator;
}

void Rational::setNumerator(const int num)
{
	numerator = num;
}

void Rational::setDenumerator(const int denum)
{
	denumerator = denum;
}

void Rational::canonisation()
{
	int x = nod(numerator, denumerator);
	setNumerator(numerator / x);
	setDenumerator(denumerator / x);
}

void Rational::addition(const Rational& r)
{
	int x = nok(r.denumerator, denumerator);
	setNumerator(numerator * (x / denumerator) + r.numerator * (x / r.denumerator));
	setDenumerator(x);
}

void Rational::substraction(const Rational& r)
{
	int x = nok(r.denumerator, denumerator);
	setNumerator(numerator * (x / denumerator) - r.numerator * (x / r.denumerator));
	setDenumerator(x);
}

void Rational::multiplication(const Rational& r)
{
	setNumerator(r.numerator * this->numerator);
	setDenumerator(r.denumerator * this->denumerator);
}

void Rational::devision(const Rational& r)
{
	setNumerator(r.denumerator * this->numerator);
	setDenumerator(r.numerator * this->denumerator);
}

int Rational::numcmp(const Rational& arg) const
{
	int x = nok(numerator, denumerator);
	int res = (numerator * (x / denumerator)) - (arg.numerator * (x / arg.denumerator));
	if (res < 0)
		return -1;
	else
		return !!res;
}

void Rational::print() const
{
	std::cout << numerator << "/" << denumerator;
}
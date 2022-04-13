#pragma once
#ifndef RATIONAL_H

class Rational
{
	int numerator;
	int denumerator;

	int nok(const int a, const int b) const;
	

public:
	int nod(const int a, const int b) const;
	Rational();
	Rational(const int num, const int denum);
	int getNumerator() const;
	int getDenumerator() const;
	void setNumerator(const int num);
	void setDenumerator(const int denum);
	void canonisation();
	void addition(const Rational& r);
	void substraction(const Rational& r);
	void multiplication(const Rational& r);
	void devision(const Rational& r);
	int numcmp(const Rational& arg) const;
	void print() const;
};

#endif
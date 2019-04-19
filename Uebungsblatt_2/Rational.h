/*
 * Rational.h
 *
 *  Created on: 19.04.2019
 *      Author: kamdoum
 */

#include <iostream>

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational {

public:
	//Konstruktoren
	Rational();
	Rational(int);
	Rational(int, int);

	//Destruktor
	virtual~ Rational();

	//Methoden
	int numerator();
	int denominator();
	void print();

	//Operatoren
	Rational &operator*=(const Rational &);
	Rational &operator+=(const Rational &);
	Rational &operator-=(const Rational &);
	Rational &operator/=(const Rational &);


	//Vergleichsoperatoren
	friend bool operator==(const Rational &, const Rational &);
	friend bool operator!=(const Rational &, const Rational &);
	friend bool operator<=(const Rational &, const Rational &);
	friend bool operator>=(const Rational &, const Rational &);
	friend bool operator<(const Rational &, const Rational &);
	friend bool operator>(const Rational &, const Rational &);

	//Operatoren
	friend Rational operator*(const Rational &, const Rational &);
	friend Rational operator+(const Rational &, const Rational &);
	friend Rational operator-(const Rational &, const Rational &);
	friend Rational operator/(const Rational &, const Rational &);

private:
	int zaehler;
	int nenner;

};



#endif /* RATIONAL_H_ */

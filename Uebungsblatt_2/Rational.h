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
	int numerator() const;
	int denominator() const;
	void print();

	//Operatoren
	Rational &operator*=(const Rational &);
	Rational &operator+=(const Rational &);
	Rational &operator-=(const Rational &);
	Rational &operator/=(const Rational &);


	
private:
	int zaehler;
	int nenner;

};

//Vergleichsoperatoren
bool operator==(const Rational &, const Rational &);
bool operator!=(const Rational &, const Rational &);
bool operator<=(const Rational &, const Rational &);
bool operator>=(const Rational &, const Rational &);
bool operator<(const Rational &, const Rational &);
bool operator>(const Rational &, const Rational &);

//Operatoren
Rational operator*(const Rational &, const Rational &);
Rational operator+(const Rational &, const Rational &);
Rational operator-(const Rational &, const Rational &);
Rational operator/(const Rational &, const Rational &);

#endif /* RATIONAL_H_ */

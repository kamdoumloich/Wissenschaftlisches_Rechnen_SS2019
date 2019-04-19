/*
 * Ueberprufung.cpp
 *
 *  Created on: 19.04.2019
 *      Author: kamdoum
 */

#include <iostream>
#include "Rational.h"

using namespace std;

int main ( int argc, char *argv[] );
static double toDouble(int);
static int gcd(int, int);

static int gcd(int zaehler_, int nenner_){
	if (nenner_ == 0)
	   return zaehler_;
	return gcd(nenner_, zaehler_ % nenner_);
}

static double toDouble(int zahl_){
	return (double) zahl_;
}

int main ( int argc, char *argv[] ){

	//Initialisierung
	int gcd_ = 0;
	Rational f1 = Rational(-3, 12);
	Rational f2 = Rational(4, 3);
	Rational f3 = Rational(0, 1);

	/********************************************/
	//Testen
	cout <<'\n'<<"Testen"<<'\n';
	f3 = f1+f2;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "f1+f2 = ";
	f3.print();
	cout << '\n';

	f3 = f1*f2;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "f1*f2 = ";
	f3.print();
	cout << '\n';

	f3 = 4+f2;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "4+f2 = ";
	f3.print();
	cout << '\n';

	f3 = f2+5;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "f2+5 = ";
	f3.print();
	cout << '\n';

	f3 = 12*f1;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "12*f1 = ";
	f3.print();
	cout << '\n';

	f3 = f1*6;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "f1*6 = ";
	f3.print();
	cout << '\n';

	f3 = f1/f2;
	gcd_ = gcd(f3.numerator(), f3.denominator());
	f3 = Rational(f3.numerator()/gcd_, f3.denominator()/gcd_);
	cout << "f1/f2 = ";
	f3.print();
	cout << '\n';

	/*************************************************/
	//Test von Vergleichsoperatoren
	cout <<'\n'<<"Test von Vergleichsoperatoren"<<'\n';
	f1 = Rational(2, 12);
	f2 = Rational(1, 4);

	gcd_ = gcd(f1.numerator(), f1.denominator());
	f1 = Rational(f1.numerator()/gcd_, f1.denominator()/gcd_);
	gcd_ = gcd(f2.numerator(), f2.denominator());
	f2 = Rational(f2.numerator()/gcd_, f2.denominator()/gcd_);

	f1.print();
	cout << " (";

	if(f1 == f2)
		cout <<" == ";
	if(f1 != f2)
		cout <<" != ";
	if(f1 <= f2)
		cout <<" <= ";
	if(f1 >= f2)
		cout <<" >= ";
	if(f1 < f2)
		cout <<" < ";
	if(f1 > f2)
		cout <<" > ";

	cout << ") ";
	f2.print();
	cout << '\n';

	/**************************************************/
	cout << toDouble(f2.numerator());


	cout << '\n'<<"Ende";

}



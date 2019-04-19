//============================================================================
// Name        : Rational.cpp
// Author      : loich kamdoum deameni
// Version     :
// Copyright   : Your copyright notice
// Description : Programm in C++, Ansi-style
//============================================================================
#include "Rational.h"

using namespace std;

Rational::Rational(){
	zaehler = 1;
	nenner = 1;
}

Rational::Rational(int zaehler_){
	zaehler = zaehler_;
	nenner = 1;
}

Rational::Rational(int zaehler_, int nenner_){
	zaehler = zaehler_;
	nenner = nenner_;
}

Rational::~Rational(){
}

int Rational::numerator(){
	return zaehler;
}

int Rational::denominator(){
	return nenner;
}

void Rational::print(){
	cout << zaehler<< " / "<< nenner;
}

Rational &Rational::operator*=(const Rational &rational_){
	zaehler *= rational_.zaehler;
	nenner *= rational_.nenner;
	return *this;
}

Rational &Rational::operator/=(const Rational &rational_){
	zaehler *= rational_.nenner;
	nenner *= rational_.zaehler;
	return *this;
}

Rational &Rational::operator+=(const Rational &rational_){
	zaehler = this->numerator()*rational_.nenner + rational_.zaehler*this->denominator();
	nenner = this->denominator()*rational_.nenner;
	return *this;
}

Rational &Rational::operator-=(const Rational &rational_){
	zaehler = this->numerator()*rational_.nenner - rational_.zaehler*this->denominator();
	nenner = this->denominator()*rational_.nenner;
	return *this;
}

Rational operator+(const Rational &rational_links, const Rational &rational_rechts){
	Rational tmp = rational_links;
	return tmp+=rational_rechts;
}

Rational operator-(const Rational &rational_links, const Rational &rational_rechts){
	Rational tmp = rational_links;
	return tmp-=rational_rechts;
}

Rational operator*(const Rational &rational_links, const Rational &rational_rechts){
	Rational tmp = rational_links;
	return tmp*=rational_rechts;
}

Rational operator/(const Rational &rational_links, const Rational &rational_rechts){
	Rational tmp = rational_links;
	return tmp/=rational_rechts;
}

bool operator==(const Rational &rational_links, const Rational &rational_rechts){
	return ((rational_links.zaehler == rational_rechts.zaehler)
			&& (rational_links.nenner == rational_rechts.nenner));
}

bool operator!=(const Rational &rational_links, const Rational &rational_rechts){
	return !(rational_links == rational_rechts);
}

bool operator<=(const Rational &rational_links, const Rational &rational_rechts){
	return ((rational_links < rational_rechts) || (rational_links == rational_rechts));
}

bool operator>=(const Rational &rational_links, const Rational &rational_rechts){
	return ((rational_links > rational_rechts) || (rational_links == rational_rechts));
}

bool operator<(const Rational &rational_links, const Rational &rational_rechts){
	int links =  rational_links.zaehler*rational_rechts.nenner;
	int rechts =  rational_links.nenner*rational_rechts.zaehler;
	return (links < rechts);
}

bool operator>(const Rational &rational_links, const Rational &rational_rechts){
	int links =  rational_links.zaehler*rational_rechts.nenner;
	int rechts =  rational_links.nenner*rational_rechts.zaehler;
	return (links > rechts);
}

// Name : Niloy Talukder Date: 07/28/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Polynomial Class Polynomial_NiloyTalukder.h

#include <iostream>

using std::ostream;
using std::istream;

#ifndef POLYNOMIAL_NILOYTALUKDER_H
#define POLYNOMIAL_NILOYTALUKDER_H

class Polynomial{

	friend ostream &operator<<( ostream&, const Polynomial & );  

public:
	//function definition
	Polynomial(); //constructor
	~Polynomial(); //destructor
	void set(double poly[]); //set function to pass coefficient and exponent of polynomial to class object as an array
	const Polynomial get(); //get function
	const Polynomial operator+( const Polynomial & ); //addition 
	const Polynomial operator-( const Polynomial & ); //subtraction
	const Polynomial &operator=( const Polynomial & ); //assignment
	const Polynomial operator*( const Polynomial & ); //multiplication
	const Polynomial &operator+=( const Polynomial & ); //addition assignment
	const Polynomial &operator-=( const Polynomial & ); //subtraction assignment
	const Polynomial &operator*=( const Polynomial & ); //multiplication assignment


private:
	int size; //maximum size of array
	double poly1[13]; //double array to store coefficient, array index represents exponent
};

#endif
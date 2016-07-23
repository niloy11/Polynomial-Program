// Name : Niloy Talukder Date: 07/28/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Polynomial Class Polynomial_NiloyTalukder.cpp

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include <iomanip>

using std::setw;


#include "Polynomial_NiloyTalukder.h"

//constructor
Polynomial::Polynomial() 
{
	size=13; //size declaration
	//initializing all array elements to zero
	for(int i=0; i<size; i++)
	      poly1[i]=0;	
}

//destructor
Polynomial::~Polynomial() 
{
	//empty function
}

//set function to pass coefficient and exponent of polynomial to class object as an array
void Polynomial::set(double poly[])
{
	for(int i=0; i<size; i++)
		poly1[i]=poly[i]; //elementwise copy to the array of object
}

//get function
const Polynomial Polynomial::get()
{
	return *this; //return object
}

//addition
const Polynomial Polynomial::operator+( const Polynomial &poly)
{
	Polynomial temp; //declare temporary object

	for(int i=0; i<size; i++)
		temp.poly1[i]=poly1[i]+poly.poly1[i]; //elementwise addition

	return temp; //return temporary object by value
}

//subtraction
const Polynomial Polynomial::operator-( const Polynomial &poly)
{
	Polynomial temp; //declare temporary object
	for(int i=0; i<size; i++)
		temp.poly1[i]=poly1[i]-poly.poly1[i]; //elementwise subtraction

	return temp; //return temporary object by value
}

//multiplication
const Polynomial Polynomial::operator*( const Polynomial &poly )
{
	Polynomial temp;
	for(int i=0; i<size; i++){
		for(int j=0; j<=i; j++)
			temp.poly1[i]+=poly1[j]*poly.poly1[i-j]; //finding all possible multiplication and then adding to get coefficient for each exponent
	}

	return temp;
}

//addition assignment
const Polynomial &Polynomial::operator+=( const Polynomial &poly )
{
	for(int i=0; i<size; i++)
		poly1[i]+=poly.poly1[i]; //addition then assignment

	return *this;
}

//subtraction assignment
const Polynomial &Polynomial::operator-=( const Polynomial &poly )
{
	for(int i=0; i<size; i++)
		poly1[i]-=poly.poly1[i]; //subtraction then assignment

	return *this;
}

//multiplication assignment
const Polynomial &Polynomial::operator*=( const Polynomial &poly )
{
	Polynomial temp;
	for(int i=0; i<size; i++){
		for(int j=0; j<=i; j++)
			temp.poly1[i]+=poly1[j]*poly.poly1[i-j]; //multiplication then assignment
	}
	*this=temp;

	return *this;
}

//assignment
const Polynomial &Polynomial::operator=( const Polynomial &poly)
{
	for(int i=0; i<size; i++)
		poly1[i]=poly.poly1[i];

	return *this;
}

//display function
ostream &operator<<( ostream &output, const Polynomial &num )
{
	if(num.poly1[0]!=0)
		output<<num.poly1[0]; //printing 0 exponent coefficient
	else output<<"0"; //else add 0

	for(int i=0; i<13; i++)   
	{
		if(num.poly1[i]!=0){
			if(num.poly1[i]>0)
			     output<<" + "; //printing "+" sign
			else output<<" ";

			if(i==1) output<<num.poly1[i]<<"x"; //to avoid printing x^1 and print x instead
			else output<<num.poly1[i]<<"x^"<<i;	//print in coefficient*x^exponent format
		}
		
	}

    return output;     // enables cout << a << b << c;                                                                          

}


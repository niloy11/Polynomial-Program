// Name : Niloy Talukder Date: 07/28/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Polynomial Class main_NiloyTalukder.h

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

#include "Polynomial_NiloyTalukder.h" //including header file

int main()
{
	int choice, n, exponent; //variable to store choice, number of coefficient in each polynomial and exponent
	const int size=13; //maximum size to array multiplation of two 6 order polynomial 
	double coefficient; //variable to store double coefficient
	double poly1[size]={0}, poly2[size]={0}, poly3[size]={0}; //array declaration to store input

	cout<<"Welcome to Polynomial program\n\n";

	cout<<"\n\nEnter the number of first polynomial terms:"; //prompt for first polynomial number of terms
	cin>>n; //store number of terms

	for(int i=0; i<n; i++)
	{
		cout<<"\n\nEnter coefficient and exponent: ";
		cin>>coefficient>>exponent; //store coefficient and exponent

		poly1[exponent]=coefficient; //store coefficient in array as exponenent is same to index
	}

	cout<<"\n\nEnter the number of second polynomial terms: "; //prompt for first polynomial number of terms
	cin>>n; //store number of terms

	for(int i=0; i<n; i++)
	{
		cout<<"\n\nEnter coefficient and exponent:";
		cin>>coefficient>>exponent; //store coefficient and exponent

		poly2[exponent]=coefficient; //store coefficient in array as exponenent is same to index
	}

	Polynomial Polynomial1, Polynomial2, Polynomial3; //declaring three polynomial object
	//using set function to pass coefficient and exponent of polynomial to class object as an array
	Polynomial1.set(poly1); 
	Polynomial2.set(poly2);

	do{
		//choice
		cout<<"\n\nWhat would you like to do?\n\n";
		cout<<setw(9)<<"1.  add two polynomial\n"
			<<setw(9)<<"2.  subtract second polynomial from the first polynomial\n"
			<<setw(9)<<"3.  assign second polynomial to first polynomial\n"
			<<setw(9)<<"4.  multiply two polynomial\n"
			<<setw(9)<<"5.  += operation on two polynomial\n"
			<<setw(9)<<"6.  -= operation on two polynomial\n"
			<<setw(9)<<"7.  *= operation on two polynomial\n"
			<<setw(9)<<"8.  display both polynomial\n"
			<<setw(9)<<"0.  exit\n\n";

	    cout<<"Your choice--";
	    cin>>choice;

	    switch(choice)
	    {
	    case(0): //exit
	        cout<<"\nEnd of polynomial program\n\n";
	        break;

	    case(1): //add two polynomial
		    Polynomial3=Polynomial1+Polynomial2;
		    cout<<"\nSum of two polynomial is: "<<Polynomial3;
		    continue;

	    case(2): //subtract second polynomial from the first polynomial
		    Polynomial3=Polynomial1-Polynomial2;
		    cout<<"\nSubtraction of two polynomial is: "<<Polynomial3;
		    continue;

	    case(3): //assign second polynomial to first polynomial
		    Polynomial1=Polynomial2;
		    cout<<"\nAssignment of second polynomial to first polynomial is: "<<Polynomial1;
		    continue;

	    case(4): //multiply two polynomial
		    Polynomial3=Polynomial1*Polynomial2;
		    cout<<"\nMultiplication of two polynomial is: "<<Polynomial3;
		    continue;

	    case(5): //+= operation on two polynomial
		    Polynomial1+=Polynomial2;
		    cout<<"\nAddition assignment of second polynomial to first polynomial is: "<<Polynomial1;
		    continue;

	    case(6): //-= operation on two polynomial
		    Polynomial1-=Polynomial2;
		    cout<<"\nSubtraction assignment of second polynomial to first polynomial is: "<<Polynomial1;
		    continue;

	    case(7): //*= operation on two polynomial
		    Polynomial1*=Polynomial2;
		    cout<<"\nMultiplication assignment of second polynomial to first polynomial is: "<<Polynomial1;
		    continue;

        case(8): //display both polynomial
		    cout<<"\n\nFirst polynomial is: "<<Polynomial1<<endl;
	        cout<<"\n\nSecond polynomial is: "<<Polynomial2<<endl;
		    continue;
	    }

	}while(choice!=0); //if choice not 0 then continue

	return 0; //successful program termination
}
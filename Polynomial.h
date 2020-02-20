/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.h

DESCRIPTION:       Specificatiion file for the Polynomial.cpp and poly_class.cpp files

USAGE:             Used with Polynomial.cpp, poly_class.cpp and test2.sh files (#include "Polynomial.h")

COMPILER:          GNU g++ compiler on Linux

NOTES:             

MODIFICATION HISTORY:

Author                           Date               Version
---------------               ----------         --------------
Conner Fissell		          2019-10-25		 1.0  Basic Version adapted from Lab 5 material.

Conner Fissell	              2019-10-28		 1.1  Added some of the function Prototypes (overloaded *, =, ==, ()...).

Conner Fissell		          2019-10-30		 1.2  Added the overloaded << and >> operator prototypes by making them friends
                                                      of the class.

Conner Fissell		          2019-11-01		 1.3  Added the Constructor and Destructor prototypes.

Conner Fissell		          2019-11-06		 1.4  Added #define TEST constructor/destructor switch.

----------------------------------------------------------------------------- */
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

//#define TEST              // Constructor/Destructor switch

#include <iostream>
#include <cmath>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial
{
	private:
		int degree;
		double coef[9];
		
	public:
		Polynomial();                                           // Default constructor
		Polynomial(int deg, double co[]);                       // Overloaded constructor
        Polynomial(const Polynomial &p1);                       // Copy constructor
		~Polynomial();                                          // Destructor
		
        // Overloaded functions
		Polynomial operator + (const Polynomial	&);             // Overloaded + Operator Function
		Polynomial operator - (const Polynomial &);             // Overloaded - Operator Function
		Polynomial operator * (const Polynomial &);             // Overloaded * Operator Function
		Polynomial& operator = (const Polynomial &);            // Overloaded = Operator Function
        bool operator == (const Polynomial &);                  // Overloaded == Operator Function 
		double operator () (double x);                          // Overloaded () Operator (Regular Evaluation)
		double operator () (double x, double y);                // Overloaded () Operator (Definite Integtration)
        Polynomial& operator -- ();                             // Overloaded -- Operator (Prefix - Differentiation)
		Polynomial& operator ++ ();                             // Overloaded ++ Operator (Prefix - Anti Differentiation)
		Polynomial operator ++ (int);                           // Overloaded ++ Operator (Postfix - Definite Integration)
		                                 
        // Friends
		friend ostream &operator << (ostream &output, const Polynomial &); 
		friend istream &operator >> (istream &input, Polynomial &);
		
};

// Global Constant
const char PROGRAMMER_NAME[] = "Conner Fissell";

#endif
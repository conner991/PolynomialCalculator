/*------------------------------------------------------------------------------------
FILE NAME:		   Polynomial.cpp

DESCRIPTION:	   Implementation file for Polynomial.h

USAGE:			   Used with Polynomial.h, poly_class.cpp and ./test2.sh files

COMPILER:		   GNU g++ compiler on Linux

NOTES:          

MODIFICATION HISTORY:
Author				             Date		      Version
---------------               ----------		-----------
Conner Fissell		          2019-10-25		 1.0  Basic Version adapted from Lab 5 material

Conner Fissell	              2019-10-27		 1.1  Started working on overloaded * operator function

Conner Fissell		          2019-10-28		 1.2  Added the overloaded << and >> operator functions. Started 
                                                      working on the overloaded = operator.

Conner Fissell		          2019-10-30		 1.3  Got the overloaded = operator function to work. 

Conner Fissell                2019-11-01         1.4  Started working on the Constructor/Destructor functions.Started 
                                                      working on the overloaded == operator function.

Conner Fissell		          2019-11-03		 1.5  Got the overloaded == operator function to work. Started organizing
                                                      the main() function. Started working on the overloaded () operator 
                                                      function. 

Conner Fissell                2019-11-04         1.6  Got previous functions to work. Started working on the Calculus
                                                      functions.

Conner Fissell                2019-11-05         1.7  Got the derivative and indefinite integral functions to work. Started
                                                      fleshing out more of the comments. 

Conner Fissell                2019-11-06         1.8  Added #define TEST constructor/destructor switch. Added a for loop to 
                                                      the overloaded constructor to initialize values to 0.

------------------------------------------------------------------------------------*/

#include "Polynomial.h"


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial()
DESCRIPTION:       Default constructor
RETURNS:           Nothing (void)
NOTES:             Initializes the degree and coef array to 0.
------------------------------------------------------------------------------- */
Polynomial::Polynomial()
{   
    #ifdef TEST
    cout << "Default Constructor\n";
    #endif

	degree = 0; 

	for (int i = 0; i < ARRAY_SIZE(coef); ++i)
	{
		coef[i] = 0;
	}

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial(int deg, int co[])
DESCRIPTION:       Overloaded Constructor
RETURNS:           Nothing (void)
NOTES:             Accepts argument parameters to initialize variables.
------------------------------------------------------------------------------- */
Polynomial::Polynomial(int deg, double co[])
{   
    #ifdef TEST
    cout << "Overloaded Constructor\n";
    #endif

    degree = 0;

    for(int i = 0; i < ARRAY_SIZE(coef); i++)
    {
        coef[i] = 0;
    }

	degree = deg;

	for (int i = 0; i <= deg; ++i)
	{
		coef[i] = co[i];
	}

}

/* -----------------------------------------------------------------------------
FUNCTION:		   Polynomial(const Polynomial &p1)          
DESCRIPTION:       Copy Constructor 
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial &p1)
{
	#ifdef TEST
    cout << "Copy Constructor\n";
    #endif

	degree = p1.degree;

	for (int i = 0; i <= degree; ++i)
	{
		coef[i] = p1.coef[i];
	}

}

/* -----------------------------------------------------------------------------
FUNCTION:          ~Polynomial()
DESCRIPTION:       Destructor
RETURNS:           Nothing (void)
NOTES:             
------------------------------------------------------------------------------- */
Polynomial::~Polynomial()
{   
    #ifdef TEST
	cout << "\nDestructor\n";
    #endif
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator = (const Polynomial &p1)
DESCRIPTION:       Assigns the polynomial object on the right to the one on the left.
RETURNS:           *this
NOTES:             
------------------------------------------------------------------------------- */
Polynomial& Polynomial::operator = (const Polynomial &p1)
{
	degree = p1.degree;

	for (int i = degree; i >= 0; --i)
	{
		coef[i] = p1.coef[i];
	}

	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator << (ostream &strm, const Polynomial &p1)
DESCRIPTION:       Overloads the << operator
RETURNS:           strm
NOTES:             
------------------------------------------------------------------------------- */
ostream &operator << (ostream &strm, const Polynomial &p1)
{
	for (int i = p1.degree; i >= 0; --i)
	{
		if (i < p1.degree)
		{
			if (p1.coef[i] >= 0) strm << " + ";
			else  strm << " ";
		}

		strm << p1.coef[i];

		if (i > 1) strm << "x^" << i;
		if (i == 1) strm << "x";
		
	}

	return strm;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator >> (istream &strm, Polynomial &p1)
DESCRIPTION:       Overloads the >> operator.
RETURNS:           strm
NOTES:             
------------------------------------------------------------------------------- */

istream &operator >> (istream &strm, Polynomial &p1)
{
	cout << "\nDegree of Polynomial: ";
    strm >> p1.degree;
    cout << "\nInput " << p1.degree + 1 << " Coefficients: \n";

	for (int i = p1.degree; i >= 0; --i)
	{
		strm >> p1.coef[i];
	}
	return strm;
}


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator + (const Polynomial &p1)
DESCRIPTION:       Adds two polynomial objects together.
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; --i)
	{
		p2.coef[i] = coef[i] + p1.coef[i];
	}

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator - (const Polynomial &p1)
DESCRIPTION:       Subtracts the polynomial object on the right from the one on
                   the left.
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; --i)
	{
		p2.coef[i] = coef[i] - p1.coef[i];
	}

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator * (const Polynomial &p1)
DESCRIPTION:       Multiplies two polynomial objects.
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator * (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = degree + p1.degree;

	for (int i = degree; i >= 0; --i)
    {
		for(int x = p1.degree; x >= 0; --x)
        {
            p2.coef[i+x] = (coef[i] * p1.coef[x]) + p2.coef[i+x];
		}
	}

	return p2;
}



/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator == (const Polynomial &p1)
DESCRIPTION:       Tests whether a polynomial is equal to another polynomial. 
RETURNS:           Boolean True or False
NOTES:             
------------------------------------------------------------------------------- */

bool Polynomial::operator == (const Polynomial &p1)
{
	if(degree == p1.degree)
	{
		for(int i = degree; i >= 0; --i)
		{
			if(coef[i] != p1.coef[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}


/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator () (double x)
DESCRIPTION:       Evaluates a polynomial for a given value of x.
RETURNS:           double d
NOTES:             
------------------------------------------------------------------------------- */
double Polynomial::operator () (double x)
{
	double d = 0.0;

	for (int i = degree; i >=0; --i)
    {
		d += (pow (x , i) * coef[i]);
	}

	return d;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator -- ()
DESCRIPTION:       Takes the derivative of a polynomial.
RETURNS:           *this
NOTES:             
------------------------------------------------------------------------------- */
Polynomial& Polynomial::operator -- ()
{
	double tmp = coef[degree];
	double pwr_rule;
	for (int i = degree; i >= 1; --i)
	{
		pwr_rule = tmp * i;
		tmp = coef[i - 1];
		coef[i - 1] = pwr_rule;
	}
	--degree;

    return *this;
	 
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator ++ ()
DESCRIPTION:       Overloaded prefix ++ operator function used for Anti-Differentiating.
                   a polynomial.
RETURNS:           *this 
NOTES:             
------------------------------------------------------------------------------- */
Polynomial& Polynomial::operator ++ ()
{
	double tmp = coef[degree];
	double pwr_rule;
	for (int i = 0; i <= degree; ++i)
	{
		pwr_rule = tmp / (i + 1);
		tmp = coef[i + 1];
		coef[i + 1] = pwr_rule;
	}
	coef[1] = coef[0];
	coef[0] = 0;
	++degree;

    return *this;

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator ++ (int)
DESCRIPTION:       Overloaded postfix ++ operator function used for Definite Integration. 
RETURNS:           
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator ++ (int)
{

	double tmp = coef[degree];
	double pwr_rule;
	for (int i = 0; i <= degree; ++i)
	{
		pwr_rule = tmp / (i + 1);
		tmp = coef[i + 1];
		coef[i + 1] = pwr_rule;
	}
	coef[1] = coef[0];
	coef[0] = 0;
	++degree;

    

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator () (double x, double y)
DESCRIPTION:       Overloaded () operator function used to evalute the definite
                   integral of a polynomial. 
RETURNS:           double u - l
NOTES:             
------------------------------------------------------------------------------- */
double Polynomial::operator () (double x, double y)
{
	double u = 0.0, l = 0.0;

	for (int i = degree; i >=0; --i)
    {
		u += (pow (x , i) * coef[i]);
	}

	for (int i = degree; i >=0; --i)
    {
		l += (pow (y , i) * coef[i]);
	}

	return u - l;
}







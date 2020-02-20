/*------------------------------------------------------------------------------------
FILE NAME:		   Polynomial.h

DESCRIPTION:	   Driver file for Polynomial.h and Polynomial.cpp files

USAGE:			   Used with Polynomial.h Polynomial.cpp (./poly_class or ./test2.sh)

COMPILER:		   GNU g++ compiler on Linux

NOTES:              

MODIFICATION HISTORY:

Author				             Date			    Version
---------------               ----------		 -------------
Conner Fissell		          2019-10-25		 1.0  Basic Version adapted from Lab 5 material

Conner Fissell	              2019-10-27		 1.1  Added overloaded * operator code to display multiplied 
                                                      polynomials.

Conner Fissell		          2019-10-28		 1.2  Added the overloaded << and >> operator code to simply using
                                                      cout << and cin >>. 

Conner Fissell		          2019-11-01		 1.3  Added overloaded =, == and new Polynomial objects to work with 
                                                      the overloaded constructor. Added variables for the overloaded 
                                                      constructor objects.

Conner Fissell		          2019-11-03		 1.4  Started organizing the main(). Added overloaded () operator code.
                                                       

Conner Fissell                2019-11-05         1.5  Added Calculus code. 

Conner Fissell                2019-11-06         1.6  Put finishing touches on layout of main() code. 
 
------------------------------------------------------------------------------------*/
#include "Polynomial.h"



/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Tests and shows the functions of the Polynomial class
RETURNS:           int 0
NOTES:             
------------------------------------------------------------------------------- */

int main()
{
	int degree = 3, x = 0, a, b;
	double COEF[4] = {9.0, 9.0, 9.0, 9.0};

	Polynomial poly[3], h;
    Polynomial f(degree, COEF), g(degree, COEF);
   

	for (int n = 0; n < 2; ++n)
	{
		cin >> poly[n];
		cout << poly[n] << endl;
	}

    cout << "\n\n*****BASIC ARITHMETIC*****\n\n";
    cout << "Addition:\n";
    cout << "  " << poly[0] << endl;
    cout << "+ " << poly[1] << endl;
    cout << "---------------------------------------\n";
	poly[2] = poly[0] + poly[1];
    cout << "  " << poly[2] << endl << endl;

    cout << "Subtraction:\n";
    cout << "  " << poly[0] << endl;
    cout << "- " << poly[1] << endl;
    cout << "---------------------------------------\n";
	poly[2] = poly[0] - poly[1];
    cout << "  " << poly[2] << endl << endl;

    cout << "Multiplication:\n";
    cout << "  " << poly[0] << endl;
    cout << "* " << poly[1] << endl;
    cout << "---------------------------------------\n";
	poly[2] = poly[0] * poly[1];
    cout << "  " << poly[2] << endl; 

	
	cout << "\n\n*****ASSIGNMENT OPERATION*****\n\n";
    cout << "Let's say:\n";
    cout << "i(x) = " << poly[1] << endl;
    cout << "j(x) = " << g << endl;
    cout << "h(x) = " << poly[0] << endl;
    cout << "Now h(x) = j(x) = i(x)\n";
	h = g = poly[1];
    cout << "h(x) = " << h << endl;


    cout << "\n\n*****EQUALITY TEST*****\n\n";
	cout << "f(x) = " << f << endl;
	cout << "g(x) = " << g << endl;
	cout << "h(x) = " << h << endl;

	cout << "\nDoes f(x) equal g(x)?\n"; 
    if(f == g) 
        cout << "YES\n"; 
    else 
        cout << "NO\n";

	cout << "\nDoes f(x) equal h(x)?\n"; 
    if(f == h) 
        cout << "YES\n"; 
    else 
        cout << "NO\n";

	cout << "\nDoes g(x) equal h(x)?\n"; 
    if(g == h) 
        cout << "YES\n"; 
    else 
        cout << "NO\n";


    cout << "\n\n*****POLYNOMIAL EVALUATION*****\n\n";
	cout << "What x value do you want to evaluate f(x) at?\n";
    cout << "NOTE: If using test2.sh then x = 2\n";
    cout << "x = ";
	cin >> x;
    cout << "\nThe value of f(" << x << ") is: " << f(x) << endl;
	

    cout << "\n\n*****POLYNOMIAL CALCULUS*****\n\n";
    cout << "The first derivative of f(x) = " << f << endl;
	--f;
    cout << "f'(x) = " << f << endl << endl;

    cout << "The Anti-Derivative of g(x) = " << g << endl;
	++g;
    cout << "G(x) = " << g << " + C" << endl;

    cout << "\nEnter bounds to Integrate g(x) = " << h << " over:\n";
    cout << "NOTE: If using test2.sh then upper bound = 3 and lower bound = 2\n";
    ++h;
    cout << "Upper: ";
    cin >> a;
    cout << "Lower: ";
    cin >> b;
    cout << "Answer: " << h(a, b) << endl;


	cout << endl << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
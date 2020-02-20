# ---------------------------------------------------------------------------------------
# FILE NAME:	Makefile
# 
# DESCRIPTION: 	Makefile for a C++ Program
#
# PURPOSE:		Build a program executable on Linux
# 
# MODIFICATION HISTORY: 
#
# Author		 	Date			Modifications(s)
# ---------		 	----------		------------------
# Conner Fissell		2019-09-18		Version 1
#					    2019-09-23		Version 2 modified for .h files		
# ________________________________________________________________________________________

#		This is our original generic makefile command that will build
#		any stand alone ".cpp" source file
#		Usage: e.g. make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

#		Next, these will build the executables that have dependencies on .h files
#		Usage: e.g. make -f Makefile2 sales_struct_v14 

#cust_ports_v1 : cust_ports_v1.h
 
#This will build two object files required for "poly_class_v2"
#and link the  into a sinlge executable 
#Usage: make -f Makefile2 poly_class_v2

#poly_class_v2: Polynomial.o poly_class_v2.o
#	g++ -o $@ $@.o Polynomial.o -std=c++11


#usage: make -f Makefile4 poly_class_v3 (same as above)

poly_class: Polynomial.o poly_class.o
	g++ -o $@ $@.o Polynomial.o -std=c++11


%.o : %.cpp Polynomial.h
	g++ -c $< -std=c++11

#poly_class_v2.o : Polynomial.h
#poly_class.o    : Polynomial.h
#Polynomial.o    : Polynomial.h





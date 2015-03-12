LU Decomposition Engine
Tom Diehl
tom.diehl@email.wsu.edu



This module provided the interface to solve a matrix via 
LU Decomposition.  It contains the
methods with the signatures as follows:



LUdecomp *LUdecompose(int N, const double **A){...}
void LUdestroy(LUdecomp*){...}  


void LUsolve(LUdecomp *decomp, const double *b, double *x){...}



where: 


typedef struct{...} LUdecomp;



This code uses the c99 version of C and also uses functions from math.h, stdio.h, and stdlib.h. 
It also includes its own header file "LUdecomp.h" and a makefile.
 



To compile code from linux terminal make sure the makefile and
 all supporting files are located 
in the same directory and type
 "make" in the command line. 


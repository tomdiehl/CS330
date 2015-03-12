Durand-Kerner Method

Tom Diehl
tom.diehl@email.wsu.edu



This program takes in the coeffiecient values of a polynomial 
equationin ascending order with regard to the to the powers of 
the polynomial with the leading coefficient implied as 1.  
ie  (x^3 - 4x^2 + 3x + 1)would be ( 1 , 3 , -4).  It then finds 
the roots of the polynomial and returns them in an array and the
number of iterations it took to find the roots within a certain
degree of accuracy. 

This code compiles with the c99 version of C and also uses functions 
from math.h, complex.h, stdio.h, and stdlib.h. 


To compile code from linix terminal:

gcc -Wall -std=c99 -D_GNU_SOURCE -DREGURGITATE proj2.c -o proj2 -lm




To run:


./proj2 < (coefficients to pass in)

Estimating pi via Numerical Integration

Tom Diehl
tom.diehl@email.wsu.edu



This program give an estimationg of Pi via numerical integration.  The integration 
is preformed
by four different methods (Simpsons, Simpsons 3/8th, Booles, and 
the trapazoid rule. The output 
from the program is the tabulated error between
each of the four methods and M_PI from the math.h 
library for the values of n for
n = 12*2^i. 


This code uses the c99 version of C and also uses functions from math.h,
assert.h,stdio.h, and stdlib.h.

To compile code from linix terminal:

gcc -Wall -std=c99 -D_GNU_SOURCE  pi.c -o pi -lm



To run:

./pi

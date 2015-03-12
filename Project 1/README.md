Tom Diehl
11149105
Tom.Diehl@email.wsu.edu

Files included in Archive:

README.md
relerror.c
exp.c

The included file relerror.c calculates the required degree of the polynomial
needed to achieve results below the desired relative error.  The results obtained
indicate that a 7th order polynomial is required.

The file exp.c calculates and approximation of the exponential function using a 
combination of calculating a power of two and a Taylor series approximation.  The 
Degree of the polynomial is dictated by the results from relerror.c.

The some of the results obtained from exp.c indicate a relative error outside of the 
initial bounds while most are within the bounds.  This is indicative of rounding and 
approximation error compounding through the numerous calculation required.  
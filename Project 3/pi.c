
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

long double f(long double x){
  return 4.0/(1.0+x*x);
}

//From Class
long double trap(long double (*f) (long double), 
            long double a, long double b, int n) {
  assert(a < b);
  const long double h = (b - a)/n;
  long double sum = 0.0;
  long double x = a + h;
  for (int i = 1; i < n; i++, x += h)
    sum += f(x);
  return h*((f(a) + f(b))/2 + sum);
}


//From Class
long double simpsons(long double (*f) (long double), 
                long double a, long double b, int n) {
  assert(n % 2 == 0);
  assert(a < b);
  const long double h = (b - a)/n;
  long double sum1 = 0.0;
  for (int i = 1; i < n; i += 2)
    sum1 += f(a + i*h);
  long double sum2 = 0.0;
  for (int i = 2; i < n; i += 2)
    sum2 += f(a + i*h);
  return h/3*((f(a) + f(b)) + 4*sum1 + 2*sum2);
}

// Modified Simpson from Class
long double simpsons38(long double (*f) (long double), 
                long double a, long double b, int n) {
  assert(n % 3 == 0);//must be evenly divisable by 3
  assert(a < b);
  const long double h = (b - a)/n;
  long double sum1 = 0.0;
  for (int i = 1; i < n; i += 3)// x1,x4....
    sum1 += f(a + i*h);
  long double sum2 = 0.0;
  for (int i = 2; i < n; i += 3)// x2,x5....
    sum2 += f(a + i*h);
  long double sum3 = 0.0;
  for (int i = 3; i < n; i += 3)// x3,x6....
    sum3 += f(a + i*h);
  return ((3*h)/8)*((f(a) + f(b)) + 3*sum1 + 3*sum2 + 2*sum3);
}

//New code- Booles
//Booles(function, start pt, stop pt, size){...}
long double booles(long double(*f)(long double),long double a,
	      long double b, int n){
  assert(n % 4 == 0);//must be evenly divisable by 4
  assert(a < b);
  const long double h = (b - a)/n;
  long double sum1 = 0.0;
  // 14 times x4,x8,x12....
  for(int i = 4; i<n; i +=4){
    sum1 += f(a +i*h);
  }
  // 32 times x1,x3,x5....
  long double sum2 = 0.0;
 for (int i = 1; i<n ; i +=2){
    sum2 += f(a +i*h);
  }
  // 12 times x2,x6,x10....
  long double sum3 = 0.0;
  for ( int i = 2 ; i < n ; i +=4){
    sum3 += f(a +i*h);
  }
  return ((2.0*h)/45.0)*((7.0*(f(a)+f(b)))+14.0*sum1 + 32.0*sum2 + 12.0*sum3);
}

int main(void) {
  const unsigned maxn = 800000;
  for (unsigned n = 12; n <= maxn; n *= 2) {
    const long double I_trap = trap(f, 0, 1, n);
    const long double error_trap = fabsl(M_PI - I_trap);
    const long double I_simp = simpsons(f, 0, 1, n);
    const long double error_simp = fabsl(M_PI - I_simp);
    const long double I_simp38 = simpsons38(f, 0, 1, n);
    const long double error_simp38 = fabsl(M_PI - I_simp38);
    const long double I_booles = booles(f, 0, 1, n);
    const long double error_booles = fabsl(M_PI - I_booles);
    printf("%5d %0.10Le %0.10Le %0.10Le %0.10Le\n", n, 
	   error_trap, error_simp, error_simp38, error_booles);
  }
  return 0;
}






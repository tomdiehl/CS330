//Worked with ben bachelder
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAXN 25 // max degree

/*
complex double f(complex double z){
  complex double equation = z*z*z - 3*z*z + 3*z - 5;
  return equation;
}
*/

complex double f(complex double z, complex double c[],int n){
complex double f;
f = cpow(z,n);
	for(int i =0; i<n; i++){
	f+=c[i]*cpow(z,i);
	}
return f;
}

int main(void) {
  double epsilon = 10E-6;
  int sizeOfArray = 0;
  int n = 0;  // polynomial degree
  complex double c[MAXN+1];
  double a, b;
  while (scanf("%lf %lf", &a, &b) == 2){
    c[n++] = a + b*I;
    sizeOfArray++;
  }
  c[n] = 1;  // leading coeff implied

#ifdef REGURGITATE  // test input
  for (int i = 0; i < n; i++) {
    a = creal(c[i]);
    b = cimag(c[i]);
    printf("%0.10f + %0.10f i\n", a, b);
  }

#endif
  // Calculate Radius
  printf(" %d\n",sizeOfArray);
  int R = 0;
  for(int i = 0; i < n; i++){
    if( R < cabs(c[i])){
      R =cabs(c[i]) +1;
      printf("R = %d , C[i] = %e  %e \n", R,creal(c[i]),cimag(c[i]));
    }
  }
  //Obtain and store initial guesses
  complex double z[sizeOfArray];
  for(int k = 0; k < sizeOfArray; k++){ 
    double theta = ((2 * (M_PI))*k / n );
    complex double  zi = ((cos(theta) + sin(theta)*I) * R);
    z[k] = zi;
  }
 
  complex double dz[sizeOfArray+1];
  int iter = 1;
  printf(" z[0] = %.10f %.10f i\n",creal(z[0]), cimag(z[0])); 
  printf(" z[1] = %.10f %.10f i\n",creal(z[1]), cimag(z[1]));
  printf(" z[2] = %.10f %.10f i\n",creal(z[2]), cimag(z[2]));
 
  for( int k = 0 ; k < 100; k++){
    complex double zmax = 0;
    iter++;
    printf("iter %d \n", iter);
    for(int j = 0; j < n;j++){
    complex double Q = 1;
      for(int i = 0; i < n; i++){
	if(i!=j){
	  Q*= (z[j]-z[i]);
	}
      }
	dz[j]=-1*f(z[j],c,n)/Q;
	complex d = cabs(dz[j]);
	if(cabs(d) > cabs(zmax)) zmax = d;

    }
    for(int j = 0; j < sizeOfArray; j++){
      z[j] += dz[j];
      printf(" z[%d] = %.10f %.10f i\n",j,creal(z[j]), cimag(z[j])); 
    }
    printf("zmax =  %e\n",zmax);
    if (cabs(zmax) <= epsilon) break;
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fact(int);

int main(){

  for(int n=1; n<16; n++){

    double lnOv2 = (M_LN2/2);
    int y = n+1;

    double factor = fact(y);
    double secTerm = pow(lnOv2, (double)y);
    double err =(2/factor)*secTerm;

    printf("n =%d , error percent = %0.15e \n",n,err);
        if(err<1.19209e-7){
	  printf("n =%d; give required relative error \n",n);
	}
  }

  return 0;
}

double fact(int j){

  double number = 1;

  for(int k = 1 ;k <= j; k++){
    number = number*k;
  }
  return number;
}

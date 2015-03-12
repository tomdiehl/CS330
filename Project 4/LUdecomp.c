#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LUdecomp.h"


LUdecomp *LUdecompose (int N, const double **A){
  
  /*  printf("Input Matrix %d x %d  \n\n",N,N); 
  if(N<11){
    for(int i= 0; i < N; i++){
      for(int j =0 ; j < N; j++){
	printf("% .3f ", A[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }*/
 
//Allocation and Cloning-- Code from guass.c

  LUdecomp *myStruct = (LUdecomp*)malloc(sizeof(LUdecomp));

  double **clone = (double **) calloc(N, sizeof(double*));
  for(int i = 0; i <N; i++)
    clone[i] = (double *) calloc(N, sizeof(double));
  for(int i = 0; i <N; i++)
    for(int j = 0; j<N; j++)
      clone[i][j] = A[i][j];

  //Put something in d and mutate
  myStruct->N = N;
  myStruct->d = 1;
  myStruct->mutate = (short*)calloc(N, sizeof(short));
  for(int i=0; i < N;i++){
    myStruct->mutate[i] = i;
  }

  /*  With out Pivot Test. 
  //LU-Algorithm
  for(int j = 0; j < N ; j++){
    for(int i = 0; i <= j ; i++){
      double sum1 = 0.0; 
      for(int k = 0; k < i ;k++) {
	sum1 += (clone[i][k] * clone[k][j]);  
      }
      clone[i][j] = clone[i][j] - sum1;
    } 
    for(int i = j + 1; i < N; i++){
      double sum2 = 0.0; 
      for(int k = 0; k < j; k++){
	sum2 += (clone[i][k] * clone[k][j]);
      } 
      clone[i][j] = (clone[i][j]-sum2)/clone[j][j]; 
    }
  }
  myStruct->LU = clone;
  return myStruct;
  }*/

  //With pivoting

 for(int j = 0; j < N ; j++){
    for(int i = 0; i <= j ; i++){
      double sum1 = 0.0; 
      for(int k = 0; k < i ;k++) {
	sum1 += (clone[i][k] * clone[k][j]);  
      }
      clone[i][j] = clone[i][j] - sum1;
    }
    double  p = fabs(clone[j][j]);
    int  n = j;
    for(int i = j + 1; i < N; i++){
      double sum2 = 0.0; 
      for(int k = 0; k < j; k++){
	sum2 += (clone[i][k] * clone[k][j]);
      } 
      clone[i][j] = (clone[i][j]-sum2); 
      if(fabs(clone[i][j])>p){
	p = fabs(clone[i][j]);
	n = i;
      }
   }
    if(p ==0.0)
      return NULL;
    if(n != j){

      double* tempRow = clone[n];
      clone[n] = clone[j];
      clone[j] = tempRow;

      short tempMute = myStruct->mutate[n];
      myStruct->mutate[n] = myStruct->mutate[j];
      myStruct->mutate[j] = tempMute;

      myStruct->d = (-1)*myStruct->d;
    }
    for(int i = (j+1); i < N; i++)
      clone[i][j] = clone[i][j]/clone[j][j]; 
 }
  myStruct->LU = clone;
  return myStruct;
}

void LUdestroy(LUdecomp* myStruct){
  for (int i = ((myStruct->N) -1) ; i >= 0; i--) 
    free(myStruct->LU[i]);
  free(myStruct->LU);
  free(myStruct->mutate);
  free(myStruct);
}

void LUsolve(LUdecomp *decomp, const double *b, double *x){
  
  //Ly=b
  double y[decomp->N]; 

  //initial value
  y[0] = b[decomp->mutate[0]];
  for (int i = 1; i < (decomp->N); i++){
    double sum1 = 0.0;
    for (int j = 0; j < i; j++){
      sum1 += decomp->LU[i][j]*y[j];
    }
    y[i] =( b[decomp->mutate[i]] - sum1);
  }
  //Ux=y
  // initial value Xi=Yi/Bii; i = n-1
  x[decomp->N-1] = y[decomp->N-1]/decomp->LU[decomp->N-1][decomp->N-1];

  for (int i = ((decomp->N) - 2); i>=0; i--){
    double sum2 = 0.0;
    for (int j = i + 1;  j < (decomp->N); j++){
      sum2 += decomp->LU[i][j] * x[j];
    }
    x[i] = (1/decomp->LU[i][i]) * (y[i] - sum2);
   }
  return; 
}

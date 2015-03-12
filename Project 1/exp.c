#include <stdio.h>
#include <math.h>

int fact(int x){
  int fact = 1;
  for(int i = 1; i <= x;i++){
    fact = fact*i;
  }
  return fact;
}

float myexp(float x){
  //f(x)=(2^m)(e^u)
  
  double z,w,u,tmp;
  int m,abs;

  //Seperate whole and fraction
  z = x/M_LN2;
  m = trunc(z);
  w = z - m;
  u = w*M_LN2;

  //2^m

    if(m<0){
      abs = -m;
    }
    else abs = m;
    tmp = 1 << abs;

    if(m<=0){
      tmp = 1/tmp;
    }
  printf("whole part = %e\n",tmp);

    //e^w 
    int iter = 7;
    const float a[] = {1.0,1.0,1.0/2.0,1.0/6.0,1.0/24.0,1.0/120.0,1.0/720.0,1.0/5040.0};
    // const float a[] = {1.0,1.0,.5,.16666666666666667,.0416666666666667,.0083333333333333333,.001388888888888889,.0001984126984126984};
    float r = a[7];
    for(int i = (iter -1); i >= 0; --i){
      r = fma(u,r,a[i]);
    }
    return r*tmp;
}

int main(){
  // From main off Class Site
  long double x0 = -20.0;
  long double x1 = 20.0;
  int N = 30;
  long double dx = (x1 - x0)/(N-1);
  int i;
  long double x;

  for(i = 0, x = x0; i < N; i++, x+=dx){
    float y1 = myexp((float)x);
    long double y2 = expl(x);
    long double rerr = fabsl((y2 - y1)/y2);
    printf("%+0.9Le %0.9e %0.9Le %0.15Le\n", x, y1,y2, rerr);
   } 
  return 0;
}

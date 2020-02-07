#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.c"


int main (int argc, char argv[])
  {
    double x,y,z,b,a;
    logo();
    
    printf("\nВ данной программе выполняются следующие арифметические действия:");
    printf("\ny=(arctgx^3+cosvx)^2x/e^x+ln|2,4x^2| \n");
    
    printf("\nz=(a*y^5) +b*cos|y|+arctg(y^x)\n");
    
    printf("\nВведите переменную x=");
    scanf("%lf", &x);
    
    y=pow(atan(pow(x, 3)) + cos(sqrt(x)), 2*x)/pow(2.71, x)+log(abs(2.4*pow(x,2)));
    printf("\nВаш y=%lf\n", y);
    
    printf("\nВведите переменную a=");
    scanf("%lf", &a);
    printf("\nВведите переменную b=");
    scanf("%lf", &b);
    
    z=a*pow(y,5)+b*cos(abs(y))+atan(pow(y,x));
    
    printf("\nВаш z=%lf\n", z);
    
    getchar();
    exit(0);
  }
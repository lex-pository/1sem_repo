#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Logo.c"
int main (int argc, char argv[])
  {
    double x,y,a,b;
    logo();
    printf("\nВ данной программе выполняются следующие арифметические действия:");
    printf("\nx=(a+b)/(1+a)^(0.25)) \n");
    printf("\ny=2sin(x)+cos(x/2))/(3+(cos*cos(x))) \n");
    printf("\nВведите переменную а=");
    scanf("%lf", &a);
    printf("\nВведите переменную b=");
    scanf("%lf", &b);
    x= pow(((a+b)/(1+a)), 0.25);
    printf("\nВаш x=%lf\n", x);
    y=(2*sin(x)+cos(x/2))/(3+(cos(x)*cos(x)));
    printf("\nВаш y=%lf\n", y);
    getchar();
    exit(0);
  }
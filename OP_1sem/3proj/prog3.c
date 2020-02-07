#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "logo.c"


int main (int argc, char argv[])
  {
    double m,s,a,v,q,w;
    
    int x,y,z,ms;
    
    logo();
    
    s = 2.1336;
    a = 71.12;
    v = 4.45;
    
    printf("\nВ данной программе переводятся единицы Метров в следующие единицы");
    printf("\nСажень= %lf m\nАршин= %lf cm\nВершок= %lf cm\n", s, a, v);
    
    printf("\nВведите количество метров=");
    scanf("%lf", &m);
    ms= m*100;
    printf("%lf m, %d cm \n", m,ms);
    
    //x это Сажень    
    x= m/s;
    printf("%d   ", x);
    
    //a это Аршин
    y= (((m*100)-(x*(s*100)))/a);
    printf("%d   ", y);
    
    //z это Варшок
    z= ((m*100)-(y*a)-(x*(s*100)))/v;
    printf("%d   \n", z);
    
    printf("\nВаш ответ:\n\nСажень= %d \nАршин= %d \nВершок= %d \n", x, y, z);
    
    getchar();
    printf("\nНажмите Enter для завершения!");
    getchar();
    exit(0);
  }
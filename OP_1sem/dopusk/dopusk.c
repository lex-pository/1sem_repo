#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "logo.c"

int main (int argc, char *argv[])
  {
     system("clear");
     //logo();
     //пояснили за переменные
     int n;
     double f,fstart,x,fn,stop;
     f=0;
     stop=0.0001;
     printf("Данная программа составляет таблицу функций, заданную конечной суммой.\n Условие окончания: последний член разряда должен быть меньше E, т.е. меньше |a(n)<E\n");
     
     if (argc<1)
     {
	printf("\nНе хватает аргументов при вызове программы! \n");
	printf("Для использования программы введите:\n Например: ./prog5 in.txt 4 \nГде ./prog5 in.txt(название считываемого файла) 4(длина слова для замены, не меньше 0) \n\n");
	printf("Нажмите [ENTER] для завершения!\n");
	getchar();
	exit(0);
     }
     n=1;
     x=0;
     
     //printf("%lf\n",f);
     
     //printf("\n%f\n",fstart);
     printf(" --------------------------------------------------\n");
     while (f<= 0.0001 || f>=(-0.0001))
     {
       fstart=((pow(x,2)/2)-((pow(x,4))/12));
       
       fn=(pow(-1,n+1))*(pow(x,2*n))/(((2*n)-1)*(2*n));
       
       f=fstart+fn;
       
       printf("| Шаг n=%2d | X=%3.1f | Функция принимает вид: %4.4f |\n", n,x,f);
       printf(" --------------------------------------------------\n");
       n++;
       x=x+0.1;
       
       if (x>=1)
       {
	 printf("Переменная X вышла из области допустимых значений [0;1]");
	 break;
	}
     }
     printf("\n\nНажмите [Enter] для заверщения!");
     getchar();
     exit(0);
  }
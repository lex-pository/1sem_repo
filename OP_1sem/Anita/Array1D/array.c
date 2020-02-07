#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "labs.h"
#include "logo.c"


int main (int argc, char* argv[])
  {
    int m,choice;
    system("clear");
    logo();
    
    if (argc < 3)
      {
	printf ("\nНе хватает аргументов при вызове программы! \n");
	printf ("Для использования программы введите:\n\n Например: %s 2 2 \n\nГде %s (2) 2 - длина одномерного массива (максимум 40)\n%s 2 (2) - способ заполнения массива (1ручной, 2автоматический)\n", argv[0], argv[0],argv[0]);
	printf("\nНажмите [Enter], для завершения!");
	getchar();
	exit(0);
      }
      
      printf("\nПрограмма в целочисленном массиве положительные числа перемещаются в 1й массив, отрицательные во 2й массив\n");
      printf("\nНажмите [Enter], для продолжения!\n");
      getchar();
      
      m = atoi(argv[1]);
      choice = atoi(argv[2]);
      
      if ( m<1 || m>40 )
      {
	printf("Пожалуйста введите длину массива не менее 1го и не более 40ка элементов");
	printf("\nНажмите [Enter], для завершения!");
	getchar();
	exit(0);
      }
      if (choice>2 || choice<1)
      {
	printf("\nПожалуйста выберете правильный способ заполнения массива: 1- ручной, 2-автоматический(рандомный)\n");
	printf("\nНажмите [Enter], для завершения!");
	getchar();
	exit(0);
      }
      
      int Array[m];
      int Plus[m];
      int Minus[m];
      
      printf("Ваш массив длинной %d элемента \n\n", m);
      
      if (choice == 1)
      {
	Get_Array_Hand(m, Array);
      }
      if (choice == 2)
      {
	Get_Array_Rand(m, Array);
      }
      printf("Ваш не распределенный массив:\n\n");
      Put_Array1D(m, Array);
      //printf("\n");
      getchar();
      
      int count,min,max;
      count=0;
      min=0;
      max=0;
      
      while(1)
      {
	if(Array[count]>0 || Array[count]==0 )
	{
	  Plus[max]=Array[count];
	  max++;
	}
	
	else if(Array[count]<0)
	{
	  Minus[min]=Array[count];
	  min++;
	}
	
	if(count==(m))
	{
	  Minus[min]='\0';
	  Plus[max]='\0';
	  break;
	}
	count++;
      }
      printf("\n\nМассив положительных значений:\n");
      Put_Array1D((max-1), Plus);
      
      printf("\n\nМассив отрицательных значений:\n");
      Put_Array1D(min, Minus);
      
      getchar();
      printf("\nНажмите [Enter] для завершения!\n\n");
  }
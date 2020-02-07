//программа принимает аргументы в SCANF Глоз не примет!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "labs.h"
#include "logo.c"

int main (int argc, char * argv[])
  {
    //Пояснили за переменные
    int m,n,choice;
    //char choise;    
    
    system("clear");
    logo();
    
    //Пососем со сторки
    if (argc < 4)  
      {
	printf ("Не хватает аргументов при вызове программы! \n");
	printf ("Для использования программы введите:\n Например: ./prog4 2 2 2 \nГде ./prog4 2(количество строк массива) 2(количество столбцов массива) 2(способ заполнения массива: 1-ручной, 2-автоматический\n");
      }
    
    //Описание программы
    printf("\nПрограмма отсортировывает двухмерный массив MxN по знаку.\n Т.е. Все положительные числа переносятся в начало с сохранением исходного порядка следования\n");
    printf("\nНажмите [Enter], для продолжения!\n");
    getchar();
    
    //Ввод длины массива
    //printf("Введите количество строк массива M=");
    //scanf("%d", &m);
    //printf("\nВведите количество столбцов массива N=");
    //scanf("%d", &n);
    
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    choice = atoi(argv[3]);
    
    if (m>20 || n>20 || m<1 || n<1)
    {
      printf("\nПожалуйста, задавайте длинну массива не менее 2 строк/столбцов и не более 20 строк/столбцов");
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
    
    
    printf("\n");
    int Array2D[m][n];
    printf("Ваш массив %d х %d \n\n", m,n);
    int Array1D[m*n];
    
    //Ввод значений в массив или рандом
    //printf("Выберите способ заполнения массива:\n");
    
    //printf("1. Вручную.\n");
    //printf("2. Автоматически.\n");
    
    
    
    if (choice == 1)
    {
    Get_Array2D_Hand(m, n, Array2D);
    }
    if (choice == 2)
    {
    Get_Array2D_Rand(m, n, Array2D);
    }

    //Вывод массива
    printf("\n");
    printf("Массив:\n");
    Put_Array2D(m, n, Array2D);
    printf("\nНажмите [Enter], для продолжения!\n");
    getchar();
    //getchar();
    
    //Перевод в одномерный
    int CountR,CountC;
  
    for (CountR=0;CountR<m;CountR++)
      {
	for(CountC=0;CountC<n;CountC++)
	{
	  Array1D[(CountR*m)+CountC]=Array2D[CountR][CountC];
	}
      }
    //Put_Array1D(m*n, Array1D);
    
    //Сортировка
    int i,perestanovki;
    int temp;
    do 
    {
      perestanovki=0;
    for(i=0; i<(m*n)-1;i++)
      {
	if (Array1D[i]<0 && Array1D[i+1]>=0)
	  {
	    temp = Array1D[i+1];
	    Array1D[i+1] = Array1D[i];
	    Array1D[i] = temp;
	    temp = 0;
	    perestanovki++;
	  }
      }
    }
    while (perestanovki);
    //Перевод в двумерный массив
    
    for (CountR=0;CountR<m;CountR++)
      {
	for(CountC=0;CountC<n;CountC++)
	{
	  Array2D[CountR][CountC]=Array1D[(CountR*m)+CountC];
	}
      }
    
    //Вывод отсортированного двумерного массива
    printf("Отсотированный массив:\n");
    Put_Array2D(m, n, Array2D);
    printf("\n\nНажмите [Enter], для завершения!");
    getchar();
    
  }
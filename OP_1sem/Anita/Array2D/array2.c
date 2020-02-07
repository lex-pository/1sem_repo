#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "labs.h"
#include "logo.c"


int main (int argc, char* argv[])
  {
    int m,n,choice;
    system("clear");
    logo();
    
    if (argc < 4)  
      {
	printf ("\nНе хватает аргументов при вызове программы! \n");
	printf ("Для использования программы введите:\n\n Например: %s 2 2 2 \n\nГде %s 2(количество строк массива, максимум 20) 2(количество столбцов массива, максимум 20) 2(способ заполнения массива: 1-ручной, 2-автоматический)\n",argv[0],argv[0],argv[0]);
	printf("\nНажмите [Enter], для завершения!");
	getchar();
	exit(0);
      }
      
      //Описание программы
      printf("\nПрограмма в массиве MxN меняет местави строки в которых находится Max и Min элементы массива\n");
      printf("\nНажмите [Enter], для продолжения!\n");
      getchar();
      
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
      
      //Если не правильно выбран способ заполнения
      if (choice>2 || choice<1)
      {
	printf("\nПожалуйста выберете правильный способ заполнения массива: 1- ручной, 2-автоматический(рандомный)\n");
	printf("\nНажмите [Enter], для завершения!");
	getchar();
	exit(0);
      }
      
      int Array2D[m][n];
      printf("Ваш массив %d х %d \n", m,n);
      int Array1D[m*n];
      
      if (choice == 1)
      {
	Get_Array2D_Hand(m, n, Array2D);
      }
      if (choice == 2)
      {
	Get_Array2D_Rand(m, n, Array2D);
      }
      
      //Вывод не отсортированного массива
      printf("\n");
      printf("Не отсортированный массив:\n");
      Put_Array2D(m, n, Array2D);
      //printf("\nНажмите [Enter], для продолжения!\n");
      //getchar();
      
      
      int CountR,CountC;
  
      for (CountR=0;CountR<m;CountR++)
	{
	  for(CountC=0;CountC<n;CountC++)
	  {
	    Array1D[(CountR*n)+CountC]=Array2D[CountR][CountC];
	  }
	}
      //Array1D[(CountR*n)+CountC+1]='\n';
      //Put_Array1D(m*n, Array1D);
      
      int max,min,count,minpos,maxpos,mn;
      int Zam[n];
      count=0;
      
      min=Array1D[count];
      max=Array1D[count];
      maxpos,minpos=0;
      //printf("\n\n%d   %d\n",min,max);
      mn=(m*n)-2;
      while(1)
      {
	//поиск максимума
	if(max<Array1D[count+1])
	{
	  max=Array1D[count+1];
	  maxpos=((count+1)/n);
	  //printf("\nMax element now: %d position: %d  maxpos: %d\n",max,count, maxpos);
	}
	
	//поиск минимума
	if(min>Array1D[count+1])
	{
	  min=Array1D[count+1];
	  minpos=((count+1)/n);
	  //printf("\nMin element now: %d\n",min);
	}
	
	//ломает цикл
	if(count==mn)
	{
	  break;
	}
	count++;
      }
      printf("\nMax элемент: %d, в %d строке\n",max, maxpos+1);
      printf("\nMin элемент: %d, в %d строке\n",min, minpos+1);
      
      //Zam[1][n]=Array2D[maxpos][n];
      printf("\nМассив с замененными строками:\n\n");
      //Put_Array2D(maxpos+1,n, Array2D);
      //printf("\n%d\n",Zam[maxpos][n]);
      
	//запись максимума в кэш
	for(CountC=0;CountC<n;CountC++)
	{
	  Zam[CountC]=Array2D[maxpos][CountC];
	}
	
	//замена максимума на минимум
	for(CountC=0;CountC<n;CountC++)
	{
	  Array2D[maxpos][CountC]=Array2D[minpos][CountC];
	}
	
	//замена минимум на кэш
	for(CountC=0;CountC<n;CountC++)
	{
	  Array2D[minpos][CountC]=Zam[CountC];
	}
	
      //Put_Array1D(n, Zam);
      Put_Array2D(m,n, Array2D);
      
      printf("\nНажмите [Enter], для завершения!");
      getchar();
      
  }
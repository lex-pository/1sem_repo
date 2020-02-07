#include <stdio.h>
#include <stdlib.h>
#include "Logo.c"
main (int argc, char *argv [])
{
  logo();
  if(argc < 2)
  {
  printf ("Не хватает аргументов при вызове программы! \n");
  printf ("Используйте %S [ENG/RUS] \n", argv [0]);
  printf("Нажимте Enter!\n");
  getchar();
  exit (0);
  }
  if(!strcmp(argv [1], "ENG"))
  {
    printf ("Hello there!\n");
    printf("Press Enter!\n");
    getchar();
    exit(0);
  }
  if(!strcmp(argv [1], "RUS"))
  {
    printf ("Привет друг!\n");
    printf("Нажимте Enter!\n");
    getchar();
    exit(0);
  }
   printf("Ты кто? / Who are you?\n");
   printf("Нажмите Enter!\n");
   getchar();
   exit(0);
} 

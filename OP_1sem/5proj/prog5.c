#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logo.c"
#include "log.h"

int main (int argc, char *argv[])
  {
     system("clear");
     logo();
    //поясняем за переменные
    FILE *in, *out, *log;
    log = fopen("log.txt", "a");
    int n;
    char namef;
    printf("\n Программа работает с текстовым файлом, все слова длиннее чем задаваемая длина N, заменяются на: *** \n");
    //TimeSt(stdout);
    
    if (argc < 3)  
      {
	printf ("\nНе хватает аргументов при вызове программы! \n");
	printf ("Для использования программы введите:\n Например: ./prog5 in.txt 4 \nГде ./prog5 in.txt(название считываемого файла) 4(длина слова для замены, не меньше 0) \n\n");
	TimeSt(log);
	
	fputs("ERROR! Программа была не правильно вызвана\n\n",log);
	printf("Нажмите ENTER для завершения!\n");
	getchar();
	exit(0);
      }
    TimeSt(log);
    fputs("DONE. Программа запущена верно, выведено лого, привествие и описание\n\n",log);

    n=atoi(argv[2]);
    //проверяем есть ли файл и длину
    //printf("\n%d\n", n);
    if((in=fopen(argv[1], "r")) == NULL)
    {
      printf("Не удалось открыть файл с данным именем\n\n");
      printf("Нажмите ENTER, для завершения!\n");
      
      TimeSt(log);
      fputs("ERROR! Входной файл не может быть открыт\n\n",log);
      getchar();
      exit(0);
    }
    
    if(n<0)
    {
      printf("Переменная N длины замены меньше 0\n\n");
      printf("Нажмите ENTER, для завершения!\n");
      
      TimeSt(log);
      fputs("ERROR! Переменная N меньше 0\n\n",log);
      getchar();
      exit(0);
    }
    
    //TimeSt(stdout);
    TimeSt(log);
    fprintf(log ,"DONE. Пройдена проверка на открытие входного файла: %s, длина переменной N устраивает условиям задачи\n\n", argv[2]);
    
    //dlina
    //printf("Вами выбрана длина: %d\n\n",n);
    //TimeSt(stdout);
    
    //проверяем длину символов и меняем
    in = fopen(argv[1], "rt");
    out = fopen("out.txt", "w");
    
    TimeSt(log);
    fputs("DONE. Открыты входной и выходной файл для чтения и записи соответственно\n\n",log);
    
    int len,m;
    char r,alphabet[]="qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    char output[m];
    
    TimeSt(log);
    fputs("DONE. Программа начала цикл чтения символов со входного файла\n\n",log);
    
    while (1) //(r=fgetc(in)) !=EOF )		//циклим чтение символов
    {
      r=fgetc(in);	//считываем элемент в переменную
      if (feof(in))
      {
	TimeSt(log);
	fputs("DONE. Программа выполнила цикл по чтению символов во входном файле\n\n",log);
	break;
      }  //останавливаем чтение если файл прочитан
      output[len]=r;		//добавляем в массив считанного символа
      len++;			//счетчик ++
      
      if(!strchr(alphabet,r))	//проверка на не текстовый символ(тобишь окончание слова)
      {
	output[len]='\0';	//ограничиваем строку как только у нас влово заканчивается
	len=len-1;		//уменьшаем счетчик для корректного счета длины слова
	//printf("Хоба, пробел!\n");
	if (len>=n)			// Проверка на длиннее ли нужного слово
	{
	  fputs("*** ", out);		//выводим звезды в файл
	  //printf("Записали звезды, длина %d",len);
	  //printf("%s\n\n", output);
	}
	else if (len<<n)//if (Len<<n)	//Проверка на меньше ли нужного слово
	{
	  fputs(output, out);		//выводим слово в файл
	  //printf("Тут мы должны записать слово: ");
	  //printf("%s, длина %d\n\n", output,len);
	}
	
	memset(output, 0, sizeof(len));		//очищаем массив
	output[len]='\0';
	len=0;					//обнуляем счетчик
      }
    }
    printf("\nПрограмма выполнила необходимые действия. Вывод произведен в файл out.txt\n");
    
    TimeSt(log);
    fputs("DONE. Программа закрылась, ответ выведен в out.txt\n\n",log);
    
    printf("\nНажмите ENTER, для завершения!\n");
    getchar();
    exit(0);
  }
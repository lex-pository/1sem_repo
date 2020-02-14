#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logo.c"
//#include "log.h"

void TimeSt(FILE *log)
{
  time_t T;
  T=time(NULL);
  fprintf(log,"%s",ctime(&T));
  
}

int main (int argc, char *argv[])
  {
	  system("clear");
    logo();
    //поясняем за переменные
    FILE *in, *out, *log;
    log = fopen("log.txt", "a");
    char* namef;
    printf("\n Программа работает с текстовым файлом, считает сумму чисел встретившихся в текстовом файле.\n");
    //TimeSt(stdout);
    
    if (argc < 2)  
    {
	  printf ("\nНе хватает аргументов при вызове программы! \n");
	  printf ("\nДля использования программы введите:\n Например: %s in.txt \nГде %s in.txt(название считываемого файла)\n\n", argv[0],argv[0]);
    
    TimeSt(log);
	  fputs("ERROR! Программа была не правильно вызвана\n\n",log);
      
	  printf("Нажмите ENTER для завершения!\n");
  	getchar();
	  exit(0);
    }
  
    TimeSt(log);
    fputs("DONE. Программа запущена верно, выведено лого, привествие и описание\n\n",log);

    if((in=fopen(argv[1], "r")) == NULL)
    {
      printf("\n!!!ERROR!!!Не удалось открыть файл с данным именем, проверьте введенное вами имя файла! Не забывайте про расширение файла\n\n");
      printf("Нажмите ENTER, для завершения!\n");
      
      TimeSt(log);
      fputs("ERROR! Входной файл не может быть открыт\n\n",log);
      
      getchar();
      exit(0);
    }
  namef=argv[1];
    
    //TimeSt(stdout);
    TimeSt(log);
    fprintf(log ,"DONE. Пройдена проверка на открытие входного файла: %s\n\n", argv[1]);
    
    
    //начинаем чтение файла и работу с ним
    in = fopen(argv[1], "rt");
    //out = fopen("out.txt", "w");
    
    TimeSt(log);
    fputs("DONE. Открыты входной файл для чтения\n\n",log);
    
    int len=0,m,arg=0,sum=0;
    char r,alphabet[]="1234567890",minus[]="-";
    char output[m];
    
    TimeSt(log);
    fputs("DONE. Программа начала цикл чтения символов со входного файла\n\n",log);
	
	  while (1)	        //циклим чтение символов
    {
      r=fgetc(in);	  //считываем элемент в переменную
      
      if (feof(in))   //останавливаем чтение если файл прочитан
      {
	     TimeSt(log);
       fprintf(log ,"DONE. Программа выполнила цикл по чтению символов во входном файле %s \n\n", namef);
	     //fputs("DONE. Программа выполнила цикл по чтению символов во входном файле\n\n",log);
	     break;
      }  
      
      /*if(!strchr(alphabet,r))
      {
        continue;
      }*/
      if(strchr(minus,r)&&len>0) //нахождение по среди числа
      {
        output[len]='\0';
        arg=atoi(output);
        printf("\nВот число: %d\n",arg);
        sum+=arg;
        len=0;
        arg=0;
        output[0]='\0';
        output[len]=r;
        len++;
      }
      
      if(strchr(minus,r) && len==0)
      {
        output[len]='-';
        len++;
      } 
      //-7 -------------------------------------------------------------------------------------------------------------------------------- тут минус семь
      if(strchr(alphabet,r))  //нахождение цифры
      { 
        output[len]=r;
        len++; 
      }
      
      if(!strchr(alphabet,r) && len>0 && !strchr(minus,r)) //окончане числа
      {
       
        output[len]='\0';
        arg=atoi(output);
        printf("\nВот число: %d\n",arg);
        sum+=arg;
        len=0;
        arg=0;
        output[0]='\0';
        //memset(output, 0, sizeof(len));
      }
        
    }
  
    printf("\nСумма чисел во входном файле=%d \n",sum);
  
    TimeSt(log);
    fprintf(log ,"Программа выполнила все необходимые действия. Выведен ответ на экран. Сумма чисел в файле= %d\n\n", sum);
	  
	  printf("\nПрограмма выполнила необходимые действия. Всю информацию о ходе работы можно увидеть в файле log.txt\n");
  
  
    //если вдруг Моисеевич попросит благодарность!!! убери "//" в следующей строке.
    //printf("\nОсобая благодарность в помощи при выполнении данной программе Lexar_alex (Алексей Я.) По всем вопросам обращатся по lexarialx@gmail.com\n");
  
  
    printf("\nНажмите ENTER, для завершения!\n");
    getchar();
    exit(0);
}
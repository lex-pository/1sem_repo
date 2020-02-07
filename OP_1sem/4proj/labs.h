//void Sort_Arr(int i; 


void Get_Array_Hand (int Amount,int Array[Amount])
{
  int Count;
  
  for (Count=0;Count<Amount;Count++)
  {
    printf("Array[%d]=",Count);
    scanf("%d",&Array[Count]);
  }
  getchar();
} 

void Put_Array (int Amount,int Array[Amount])
{
  int Count;
  
  for (Count=0;Count<Amount;Count++)
  {
    printf("%d ",Array[Count]);
  }
  printf("\n");
}

void Get_Array_Rand(int Amount,int Array[Amount])
{
  int Count;
  
  srandom(time(NULL));
  for (Count=0;Count<Amount;Count++)
  Array[Count]=rand()%200-100;
}

int N_Divisors(int Num)
{
  int Count,Num_Div;
  
  Num_Div=0;
  for(Count=2;Count<=Num/2;Count++)
  if(Num%Count==0)Num_Div++;
  return Num_Div;
}

void Put_Array1D (int me, int Array1D[me])
{
  int CountR;
  
  for (CountR=0;CountR<me;CountR++)
  {
    printf("%4d ",Array1D[CountR]); 
  }	
}

void Put_Array2D (int m,int n,int Array2D[m][n])
{
  int CountR,CountC;
  
  for (CountR=0;CountR<m;CountR++)
  {
    for(CountC=0;CountC<n;CountC++)
    {
      printf("%4d ",Array2D[CountR][CountC]);
    }
    printf("\n");
  }	
}

void Get_Array2D_Rand (int m,int n,int Array2D[m][n])
{
  int CountR,CountC;srandom(time(NULL));
  
  for (CountR=0;CountR<m;CountR++)
  {
    for(CountC=0;CountC<n;CountC++)
    {
      Array2D[CountR][CountC]=random()%200-100;
    }
  }
}

void Get_Array2D_Hand (int m,int n,int Array2D[m][n])
{
  int CountR,CountC;
  
  for (CountR=0;CountR<m;CountR++)
  {
    for(CountC=0;CountC<n;CountC++)
    {
      printf("Array2D[%d][%d]=",CountR,CountC);
      scanf("%d",&Array2D[CountR][CountC]);
    }
  }
  getchar();
}

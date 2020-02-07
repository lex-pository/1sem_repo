void TimeSt(FILE *log)
{
  time_t T;
  T=time(NULL);
  fprintf(log,"%s",ctime(&T));
  
}
#include "process.h"
#include<string.h>
#define SIZE 101
#define STYLE '='

void FlushProcess(double total,double curr)//更新进度,按照下载进度，进行更新进度条
{
  if(curr>total)
    curr = total;
  double rate = curr/total*100;
  int cnt = (int)rate;  
  char processbuff[SIZE];
  memset(processbuff,'\0',sizeof(processbuff));
  int i =0;
  for(;i<cnt;i++)
  {
    processbuff[i] = STYLE;
  }
  static char *lable = "|/-\\";
  static int index = 0;

  //刷新
  printf("[%-100s][%.2lf%%][%c]\r",processbuff,rate,lable[index++]);
  index%=strlen(lable);
  fflush(stdout);
  if(curr>=total)
  {
    printf("\n");
  }
}

//version1:不能使用，仅能说明原理。
void Process()
{
  const char *lable = "|/-\\";
  int len = strlen(lable);
  char processbuff[SIZE];
  memset(processbuff,'\0',sizeof(processbuff));
  int cnt =0;
  while(cnt<=100)
  {
//    printf("[%-100s] [%d%%][%c]\r",processbuff,cnt,lable[cnt%len]);
    fflush(stdout);
    processbuff[cnt++] = STYLE;
    usleep(30000);
  }
  printf("\n");
}


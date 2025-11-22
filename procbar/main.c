#include "process.h"
#include<time.h>
#include<stdlib.h>

double total =1024.0;
double speed = 1.0;

//函数指针
typedef void (*callback_t)(double,double);

double SpeedFloat(double start,double range)
{
  int int_rang = (int)range;
  return start + rand()%int_rang+(range-int_rang);
}

//cb:回调函数
void DownLoad(int total,callback_t cb)
{
  srand(time(NULL));
  double curr = 0.0;
  while(1)
  {
    if(curr>total)
    {
     curr=total;
    cb(total,curr);//更新进度,按照下载进度，进行更新进度条
     break;
    }
    cb(total,curr);//更新进度,按照下载进度，进行更新进度条
    curr += SpeedFloat(speed,20.3);//模拟下载行为
    usleep(30000);
  }
  
}

int main()
{
  printf("DownLoad:20MB");
  DownLoad(20.0,FlushProcess);
  printf("DownLoad:200MB");
  DownLoad(200.0,FlushProcess);
  printf("DownLoad:20000MB");
  DownLoad(20000.0,FlushProcess);
  return 0;
}

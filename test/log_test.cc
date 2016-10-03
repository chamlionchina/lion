#include <lion/base/log.h>
#include<iostream>
#include <chrono>
#include<thread>
using namespace lion;
LogInit();
void output(const std::string msg)
{ 
  static  FILE* g_file = fopen("log_file", "w");//只会第一次调用的时候初始化
  fwrite(msg.c_str(), 1,  msg.length() , g_file);
}

void fun()
{
  for (int i=0;i<10000;i++)
  {
 LOG_DEBUG("hello  every body");
  }
}
int main()
{   SETLOGOUT(output);
    std::thread t1(fun);
    std::thread t2(fun);
    std::thread t3(fun);
    std::thread t4(fun);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
 return 0;
}
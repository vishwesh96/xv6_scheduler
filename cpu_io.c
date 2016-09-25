#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

#define N 1000000000

int main(int argc, char *argv[]) 

{
  int start = uptime();
  int i=2;
  // int n=1;
  setprio(20);
  if(printf(1,"forked child 2 \n"),fork()==0){
    printf(1,"in child 2\n");
    int m = setprio(1*i);
    printf(1,"prioriy of child 2 set \n");
    sleep(1);
    printf(1,"Runnig child with priority : %d and return value : %d\n",getprio(),m);
    char buf[2048];
    int j = 0;
    for(; j<200000; j++){
      int fd = open("data.txt", O_RDONLY);
      int n  = 0;
      do{
        n = read(fd,buf,2048);
      }while(n>0);
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
    exit();
  }
  // else{i999 
  //   if(printf(1,"forked child 4 \n"),fork()==0){
  //     printf(1,"in child 4\n");
  //     int m = setprio(2*i);
  //     printf(1,"prioriy of child 4 set \n");
  //     sleep(1);
  //     printf(1,"Runnig child with priority : %d and return value : %d\n",getprio(),m);
  //     volatile long int k=0;
  //     while(k<N){
  //       k=k+1;
  //     }
  //     printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  //     exit();
  //   }
  // }
  wait();
  exit();
}



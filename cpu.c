#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"



int main(int argc, char *argv[]) 

{

  int start = uptime();
  int i=2;
  // int n=1;
  if(fork()==0){
    int m = setprio(1*i);
    printf(1,"In child with priority : %d and return value : %d\n",getprio(),m);
    volatile long int k=0;
    while(k<1000000000){
      k=k+1;
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  }
  if(fork()==0){
    int m = setprio(2*i);
    printf(1,"In child with priority : %d and return value : %d\n",getprio(),m);
    volatile long int k=0;
    while(k<1000000000){
      k=k+1;
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  }
  if(fork()==0){
    int m = setprio(3*i);
    printf(1,"In child with priority : %d and return value : %d\n",getprio(),m);
    volatile long int k=0;
    while(k<1000000000){
      k=k+1;
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  }
  if(fork()==0){
    int m = setprio(4*i);
    printf(1,"In child with priority : %d and return value : %d\n",getprio(),m);
    volatile long int k=0;
    while(k<1000000000){
      k=k+1;
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  }
  if(fork()==0){
    int m = setprio(5*i);
    printf(1,"In child with priority : %d and return value : %d\n",getprio(),m);
    volatile long int k=0;
    while(k<1000000000){
      k=k+1;
    }
    printf(1,"child finished with time : %d and priority : %d\n",uptime()-start,getprio());
  }

  wait();
  wait();
  wait();
  wait();
  wait();

  exit();
}



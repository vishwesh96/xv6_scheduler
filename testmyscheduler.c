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

  int start =  uptime();  
  setprio(20);                    //set priority of parent to high value to fork all child process first
  if(printf(1,"forked child 1 \n"),fork()==0){
    printf(1,"in child 1\n");
    setprio(2);
    printf(1,"prioriy of child 1 set to %d\n",getprio());
    sleep(1);
    printf(1,"running child 1\n");
    volatile long int k=0;
    while(k<N){
      k=k+1;
    }
    printf(1,"child 1 finished with at time : %d\n",uptime()-start);
    exit();
  }
  else{
    if(printf(1,"forked child 2 \n"),fork()==0){
      printf(1,"in child 2\n");
      setprio(6);
      printf(1,"prioriy of child 2 set to %d\n",getprio());
      sleep(1);
      printf(1,"running child 2\n");
      volatile long int k=0;
      while(k<N){
        k=k+1;
      }
      printf(1,"child 2 finished at time : %d\n",uptime()-start);
      exit();
    }
    else{
      if(printf(1,"forked child 3 \n"),fork()==0){
        printf(1,"in child 3\n");
        setprio(4);
        printf(1,"prioriy of child 3 set to %d\n",getprio());
        sleep(1);
        printf(1,"running child 3\n");
        volatile long int k=0;
        while(k<N){
          k=k+1;
        }
        printf(1,"child 3 finished at time : %d\n",uptime()-start);
        exit();
      }
    }
  }
  wait();
  wait();
  wait();

  start = uptime();
  
  if(printf(1,"forked child 4 \n"),fork()==0){
    printf(1,"in child 4\n");
    setprio(8);
    printf(1,"prioriy of child 4 set to %d\n",getprio());
    sleep(1);
    printf(1,"running child 4\n");

    char buff[2048];
    volatile long int j;
    for(j=0;j<100000;j++)
    {
      int fd = open("data.txt", O_RDONLY);
      int n = 0;
      do
      {
        n = read(fd, buff, 2048);
      }
      while(n>0);
    }

    printf(1,"child 4 finished with at time : %d\n",uptime()-start);
    exit();
  }
  else{
    if(printf(1,"forked child 5 \n"),fork()==0){
      printf(1,"in child 5\n");
      setprio(6);
      printf(1,"prioriy of child 5 set to %d\n",getprio());
      sleep(1);
      printf(1,"running child 5\n");
      char buff[2048];
      volatile long int j;
      for(j=0;j<20000;j++)
      {
        int fd = open("data.txt", O_RDONLY);
        int n = 0;
        do
        {
          n = read(fd, buff, 2048);
        }
        while(n>0);
      }
      printf(1,"child 5 finished at time : %d\n",uptime()-start);
      exit();
    }
    else{
      if(printf(1,"forked child 6 \n"),fork()==0){
        printf(1,"in child 6\n");
        setprio(10);
        printf(1,"prioriy of child 6 set to %d\n",getprio());
        sleep(1);
        printf(1,"running child 6\n");

        char buff[2048];
        volatile long int j;
        for(j=0;j<20000;j++)
        {
          int fd = open("data.txt", O_RDONLY);
          int n = 0;
          do
          {
            n = read(fd, buff, 2048);
          }
          while(n>0);
        }

        printf(1,"child 6 finished at time : %d\n",uptime()-start);
        exit();
      }
    }
  }
  wait();
  wait();
  wait();


  exit();
}



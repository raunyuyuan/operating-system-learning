#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* 
  fork创建了子进程, 其他情况子进程可能会先运行
 */
int main(int argc, char *argv[]) {
  // 当前进程
  printf("hello world (pid: %d) \n", (int) getpid());
  /* 
    创建子进程，子进程不会重头执行，而是接着fork的语句往下执行
    子进程不是完全拷贝了父进程，虽然它拥有自己的地址空间（私有内存），寄存器，程序技数器等，父进程获得rc
    的值为子进程pid，而子进程获得的rc值为0
  */
  int a = 0;
  a = 100;
  int rc = fork();
  
  
  // 父进程获得rc值为子进程pid，而子进程获得的rc值为0
  printf("rc value: %d\n", rc);
  if (rc < 0) {
    fprintf(stderr, "fork failed");
    exit(1);
  } else if (rc == 0) {
    // 打印获取子进程id
    
    printf("%d \n", a);
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } else {
    a = 20;
    printf("%d \n", a);
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
  return 0;
}
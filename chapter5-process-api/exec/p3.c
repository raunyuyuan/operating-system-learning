#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;
    // 没有创建新的进程，但是直接将当前运行的程序替换为wc接下去 exec调用不会返回
    execvp(myargs[0], myargs);
    printf("this shouldn't print out");
  } else {
    int wc = wait(NULL);
    printf("hello, I am parent of %d (wc:%d) (pid:%d) \n", rc, wc, (int) getpid());
  }
  return 0;
}

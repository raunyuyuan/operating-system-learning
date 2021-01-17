#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int fd = open("./file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
  int rc = fork();
  assert(fd > -1);
  if (rc < 0) {
    fprintf(stderr, "fork failed");
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    
  } else {
    printf("hello, I am parent (pid:%d)\n", (int) getpid());
    wait(NULL);
    
  }
  int res = write(fd, "hello world3456789099876543234567890\n", 50);
  assert(res == 50);
  close(fd);
  return 0;
}
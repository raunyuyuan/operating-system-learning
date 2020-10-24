#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

int main(int argc, char *argv[]) {
  int *p = malloc(sizeof(int));
  assert(p != NULL);
  // %08x 以16进制方式输出的格式字符串，输出的16进制值占8位，不足部分左侧补0
  printf("(%d) memory address of p: %08x\n", getpid(), (unsigned) p);
  *p = 0;
  while(1) {
    Spin(1);
    *p = *p + 1;
    printf("(%d) p: %d\n", getpid(), *p);
  }
  return 0;
}
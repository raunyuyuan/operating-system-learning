#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "for failed\n");
    // exit(0) indicates successful program termination & it is fully portable, While
    // exit(1) (usually) indicates unsucessful termination. However, it's usage is non-portable.
    exit(1);
  } else if (rc == 0) { // child: redirect standard output to a file
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

    // now exec "wc"...
    char *myargs[3];
    myargs[0] = strdup("wc"); // program: "wc" (word count)
    myargs[1] = strdup("p4.c");
    myargs[2] = NULL;
    execvp(myargs[0], myargs);
  } else { // parent go down this path
    // If you call wait(NULL) (wait(2)), you only wait for any child to terminate. 
    // With wait(&status) you wait for a child to terminate but you want to know some information about it's termination.
    int wc = wait(NULL);
  }
  return 0;
}

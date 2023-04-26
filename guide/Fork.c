#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  int pid = fork(); // hacer un fork. 0: es el hijo, pid del hijo, -1: error

  printf("Hola mundo, valor del PID: %d (Qué proceso soy?) \n", pid);

  if (pid == 0)
  {
    printf("PID(%d): Soy el hijo. Mi padre es %d \n", getpid(), getppid());
  }
  else
  {
    printf("PID(%d): Soy el padre. Mi padre es %d. Mi hijo es %d \n", getpid(), getppid(), pid);
  }

  while (1); // si no se pone esto, el proceso padre morira y el hijo sera adoptado.
}

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/* Muestra los valores devueltos por el fork para el padre y el hijo */
int main(){
  int pid = fork();
  printf("Hola mundo, valor del PID: %d (Qué proceso soy?) \n",pid);
  return 0;
}

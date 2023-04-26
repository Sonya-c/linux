#include <stdio.h>
#include <unistd.h>
/* Creación de proceso hijo y cada uno crea un espacio donde se aumenta una variable x */

int main(void) {
   int x;

   x = 0;
   fork();
   printf("Proceso %ld y valor de x inicial es %d\n", (long)getpid(), x);
   x = 1;
   printf("Proceso %ld y valor de x final es %d\n", (long)getpid(), x);
   return 0;
}

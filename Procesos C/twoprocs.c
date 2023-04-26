#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/* Identifica los procesos padre e hijo directamente en el código o posiblemente un error */
int main(void) {
   pid_t childpid;

   childpid = fork();
   if (childpid == -1) {
      perror("Falla en el fork");
      return 1;
   }
   if (childpid == 0)                             /* Código del hijo */
      printf("Soy un hijo %ld\n", (long)getpid());
   else                                          /* Código del padre */
      printf("Soy el padre %ld\n", (long)getpid());
   return 0;
}

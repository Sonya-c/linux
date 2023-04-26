#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
/* Muestra el identificador del padre */
int main() 
{ 
	pid_t pidC;
	printf("Cuál es el valor del proceso padre y el del hijo?\n\n");
    /* fork a process */
	printf("** Identificador del padre creador = %d **\n", getpid());
    pidC = fork(); 
    /* el hijo y el padre ejecutarán cada línea de código después del fork(de forma separada) */
    printf("pidC = %d , Hola Mundo!\n", pidC);
    return 0; 
} 
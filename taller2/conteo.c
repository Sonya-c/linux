/*
Escribir un programa usando wait() y exit() llamado conteo.c, tal que un proceso padre cree 
un hijo. Entre ambos procesos deben generar los números entre 0 y 19, no importa que no 
se generen en la misma secuencia ordenada. El proceso hijo debe generar de 0 a 8 y el padre 
de 9 hasta 19. Cada proceso debe imprimir en pantalla los números generados. Cuando el 
proceso padre llegue a un número n ( 10 < n < 18), el cual se pasa como parámetro durante 
la ejecución del programa, debe detenerse y esperar a que el hijo genere e imprima sus 
números. Luego, el proceso padre puede continuar la generación e impresión de números de 
n+1 en adelante. Cada listado de números impresos, debe estar encabezado por el nombre 
del proceso que lo ejecuta y su pid. El proceso hijo debe devolver 0 en el status y padre debe 
mostrarlo al retomar su impresión.
Entrada:
./conteo 14
Salida posible:
Proceso padre y pid 48670
9
10
11
12
13
14
Proceso hijo y pid 48671
0
1
2
3
4
5
6
7
8
Hijo terminado y valor status 0
15
16
17
18
19
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    pid_t pid, wait;
    int wstatus;

    pid = fork();

    if (pid > 0) {  // el padre
        printf("Proceso padre y pid %d \n", getpid());
        
        for (int i = 9; i <= 19; i = i + 1) {
            printf("%d \n", i);

            if (i == n) {
                wait = waitpid(pid, &wstatus, 0);
                printf("Hijo terminado y valor status %d", wstatus);
                printf("%d \n", i);
            }
        }

    } else if (pid == 0) {// el hijo
        printf("Proceso hijo y pid %d \n", getpid());

        for (int i = 0; i <= 8; i = i + 1) {
            printf("%d \n", i);
        }

        exit(EXIT_SUCCESS);
    } else { // el espiruto santo
        printf("Algo salió mal");
    }

    return 0;
}
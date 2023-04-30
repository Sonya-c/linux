/*
Modificar el programa anterior y llamarlo sumapid.c de tal forma que los números enteros 
aleatorios generados en cada hijo y pasados al padre, sean mostrados en orden de procesos 
hijos creados y luego se obtenga la suma.
Entrada:
./sumapid 4

Salida posible:
Hijo: PID = 49244, valor aleatorio calculado 6 
Hijo: PID = 49245, valor aleatorio calculado 3 
Hijo: PID = 49246, valor aleatorio calculado 5 
Hijo: PID = 49243, valor aleatorio calculado 8 
PADRE de PID = 49242, HIJO de PID = 49243 terminado, st = 8 
PADRE de PID = 49242, HIJO de PID = 49244 terminado, st = 6 
PADRE de PID = 49242, HIJO de PID = 49245 terminado, st = 3 
PADRE de PID = 49242, HIJO de PID = 49246 terminado, st = 5 
La suma es 22
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>   

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int s = 0;

    // https://stackoverflow.com/questions/8623131/why-is-rand-not-so-random-after-fork
    

    for (int i = 0; i < n; i = i + 1){
        pid_t pid = fork();
        
        if (pid == 0) {
            srand(time(NULL) ^ getpid());
            // Cada hijo debe mostrar en la terminal su pid y un número entero entre 0 y 9 generado aleatoriamente
            // Este número debe ser pasado al padre
            
            int num = (rand() % (10));

            printf("Hijo: PID = %d, valor aleatorio calculado %d\n", getpid(), num);

            exit(num);

        } else if (pid > 0) {
            int num;
            waitpid(pid, &num, WUNTRACED);
            num = num / 255;
            
            s = s + num;
            printf("PADRE de PID = %d, HIJO de PID = %d terminado, st = %d\n", getpid(), pid, num);
            

        } else {
            printf("Error fork\n");
        }
    }
    printf("La suma es %d\n", s);
    return 0;
}
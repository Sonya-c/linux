/*
Debe recibir como parámetro el entero arg1. 
Este parámetro significa que debe generar 
los arg1 primeros números de Fibonacci e 
imprimirlos. Debe imprimir un mensaje donde
anuncie que entró a Fibo con su PID y el del
padre. Comparar con los valores impresos
cuando estaba en el hijo creado dentro del padre.
En total debe recibir dos parámetros (¿por qué?),
de no ser así, debe imprimir un mensaje de uso,
parecido al del padre, pero con su formato.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Entra a fibonacci %d de padre %d\n", getpid(), getppid());

    if (argc != 2) {
        printf("Uso: fibo lim-fibo\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int f0 = 0, f1 = 1; 
    for (int i = 1; i < n; i++) {
        printf("Fibo %d = %d\n", i, f0);

        int temp = f1;
        f1 = f0 + f1;
        f0 = temp;
    }
    return 0;
}
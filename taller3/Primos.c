/**
Debe recibir como parámetro el entero arg1.
Este parámetro significa que debe generar 
los arg1 primeros números de primos e imprimirlos.
Debe imprimir un mensaje donde anuncie que entró
a Primo con su PID y el del padre. Comparar con
los valores impresos cuando estaba en el hijo
creado dentro del padre. En total debe recibir
dos parámetros (¿por qué?), de no ser así, debe
imprimir un mensaje de uso, parecido al del padre,
pero con su formato.
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Entra a primos %d de padre %d\n", getpid(), getppid());

    if (argc != 2) {
        printf("Uso: primos lim-primos\n");
        return 1;
    }
    int n = atoi(argv[1]);
    int num = 2;
    int count = 1;

    while (count <= n) {
        int div = 0; 

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                div++;
                break;
            }
        }

        if (div == 0) {
            printf("Primo %d es %d\n", count, num);
            count++;
        }
        
        num++;
    }
    return 0;
}
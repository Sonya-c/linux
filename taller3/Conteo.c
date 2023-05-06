/**
Debe recibir como parámetros los números enteros arg1, arg2. 
Estos parámetros corresponden a los valores iniciales de un
conteo entre arg1 y arg2. Debe imprimir un mensaje donde anuncie
que entró a Conteo con su PID y el del padre. Comparar con los
valores impresos cuando estaba en el hijo creado dentro del padre.
En total debe recibir tres parámetros (¿por qué?), de no ser así,
debe imprimir un mensaje de uso, parecido al del padre, pero con
su formato. Si recibe sus parámetros correctamente, debe contar e
imprimir los números entre arg1 y arg2, sumarlos y promediarlos.
Al final, debe imprimir suma y promedio.
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Entra a conteo %d de padre %d\n", getpid(), getppid());

    if (argc != 3) {
        printf("Uso: conteo ini_cont fin_cont\n");
        return 1;
    }

    int ini = atoi(argv[1]);
    int fin = atoi(argv[2]);
    int suma = 0;
    
    for (int i = ini; i <= fin; i++) {
        suma = suma + i;
        printf("Conteo en el hijo %d\n", i);
    }

    float promedio = suma / (fin - ini + 1);
    printf("La suma = %d y el promedio = %.2f\n", suma, promedio);
    return 0;
}
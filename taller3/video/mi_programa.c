#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc == 3) {
        char* nombre = argv[1];
        char* apellido = argv[2];
        printf("Nombre: %s\n", nombre);
        printf("Apellido: %s\n", apellido);
    } else {
        printf("Se requieren dos argumentos: nombre y apellido.\n");
    }
    return 0;
}
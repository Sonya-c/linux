# Marco teorico 
La función exec() en C se utiliza para reemplazar el proceso actual con un nuevo proceso. Cuando se llama a una función exec(), el proceso actual deja de existir y es reemplazado por el nuevo proceso. Esto se utiliza comúnmente en sistemas operativos tipo Unix para ejecutar un programa desde otro programa.

Existen varias variantes de la función exec() en C, cada una con ligeras diferencias en su uso y comportamiento. A continuación, describiré brevemente cada una de ellas y proporcionaré un ejemplo de uso para cada una:

## execl
execl(): Esta función toma una lista de argumentos separados por comas y los utiliza para ejecutar un nuevo programa. La lista de argumentos debe terminar con un puntero nulo. La sintaxis de la función es la siguiente:

~~~c
int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
~~~

Aquí, path es la ruta del programa a ejecutar y arg es el primer argumento. Los argumentos adicionales se especifican como argumentos separados por comas después de arg.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "ls" con los argumentos "-l" y "-a". El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    execl("/bin/ls", "ls", "-l", "-a", NULL);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execl() se utiliza para ejecutar el programa "ls" con los argumentos "-l" y "-a". La última línea de la función main() no se ejecutará porque el proceso actual se ha reemplazado por el nuevo proceso.

## execlp
execlp(): Esta función funciona de manera similar a execl(), pero busca el programa a ejecutar en la variable de entorno PATH. La sintaxis es la siguiente:

~~~c
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
~~~

En este caso, file es el nombre del programa a ejecutar (sin la ruta completa) y arg es el primer argumento. Los argumentos adicionales se especifican como argumentos separados por comas después de arg.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "ls" con los argumentos "-l" y "-a", pero no conocemos la ruta completa del programa. El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    execlp("ls", "ls", "-l", "-a", NULL);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execlp() se utiliza para buscar el programa "ls" en la variable de entorno PATH y ejecutarlo con los argumentos "-l" y "-a".

## execle
execle(): Esta función es similar a execl(), pero permite especificar el entorno para el nuevo proceso. La sintaxis es la siguiente:

~~~c
int execle(const char *path, const char *arg, ... /*, (char *) NULL, char * const envp[] */);
~~~

En este caso, path es la ruta del programa a ejecutar, arg es el primer argumento y envp es un arreglo de punteros a cadenas que especifica el entorno para el nuevo proceso.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "echo" con el argumento "Hola, mundo!" y establecer la variable de entorno "LANG" en "es_ES.UTF-8". El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *envp[] = {"LANG=es_ES.UTF-8", NULL};
    execle("/bin/echo", "echo", "Hola, mundo!", NULL, envp);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execle() se utiliza para ejecutar el programa "echo" con el argumento "Hola, mundo!" y establecer la variable de entorno "LANG".

## execv
execv(): Esta función es similar a execl(), pero toma un arreglo de punteros a cadenas como argumento en lugar de una lista de argumentos separados por comas. La sintaxis es la siguiente:

~~~c
int execv(const char *path, char *const argv[]);
~~~

En este caso, path es la ruta del programa a ejecutar y argv es un arreglo de punteros a cadenas que contiene los argumentos para el nuevo programa. El último elemento de argv debe ser un puntero nulo.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "ls" con los argumentos "-l" y "-a". El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"ls", "-l", "-a", NULL};
    execv("/bin/ls", args);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execv() se utiliza para ejecutar el programa "ls" con los argumentos "-l" y "-a" utilizando un arreglo de punteros a cadenas.

## execvp
execvp(): Esta función es similar a execv(), pero busca el programa a ejecutar en la variable de entorno PATH. La sintaxis es la siguiente:

~~~c
int execvp(const char *file, char *const argv[]);
~~~

En este caso, file es el nombre del programa a ejecutar (sin la ruta completa) y argv es un arreglo de punteros a cadenas que contiene los argumentos para el nuevo programa. El último elemento de argv debe ser un puntero nulo.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "ls" con los argumentos "-l" y "-a", pero no conocemos la ruta completa del programa. El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"ls", "-l", "-a", NULL};
    execvp("ls", args);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execvp() se utiliza para buscar el programa "ls" en la variable de entorno PATH y ejecutarlo con los argumentos "-l" y "-a".

## execve

execve(): Esta función es similar a execv(), pero permite especificar el entorno para el nuevo proceso. La sintaxis es la siguiente:
~~~c
int execve(const char *path, char *const argv[], char *const envp[]);
~~~

En este caso, path es la ruta del programa a ejecutar, argv es un arreglo de punteros a cadenas que contiene los argumentos para el nuevo programa y envp es un arreglo de punteros a cadenas que especifica el entorno para el nuevo proceso. El último elemento de argv y envp debe ser un puntero nulo.

**Ejemplo:**

Supongamos que queremos ejecutar el programa "echo" con el argumento "Hola, mundo!" y establecer la variable de entorno "LANG" en "es_ES.UTF-8". El siguiente código mostraría cómo hacerlo:

~~~c
#include <unistd.h>
#include <stdio.h>

int main() {
    char *args[] = {"echo", "Hola, mundo!", NULL};
    char *envp[] = {"LANG=es_ES.UTF-8", NULL};
    execve("/bin/echo", args, envp);
    printf("Esta línea no se imprimirá\n");
    return 0;
}
~~~

En este ejemplo, execve() se utiliza para ejecutar el programa "echo" con el argumento "Hola, mundo!" y establecer la variable de entorno "LANG".
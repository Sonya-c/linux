# Taller 3 

El trabajo consta de una sección teórica y otra práctica de programación. Se deben conformar grupos de trabajo de tres estudiantes. Pueden constituirlos inter-cursos.

## Marco teórico 

1. [video 1] Función exec(): ¿cómo funciona?
2. Variantes de exec(): ejemplos de cada una con un programa simple 
    1. [video 1] execl()
    2. [video 1] execlp()
    3. [video 2] execlp()
    4. [video 2] execv()
    5. [video 3] execvp()
    6. [video 3] execve()

## Programas 

1. Escribir un programa llamado **Padre.c** que genere un proceso padre y un hijo. El programa debe permitir el paso de parámetros y no el ingreso de datos en forma interactiva. Los  parámetros deben ser de la forma:

    ~~~
    ./Padre vlr-inip vlr-finp <nombre-función> arg1 [arg2].
    ~~~

    Donde Padre debe:

    1. Comprobar que los parámetros pasados sean mínimo tres. Tenga en cuenta que C considera el nombre del programa un parámetro más. Si no son mínimo tres, debe emitir un mensaje de uso Uso: Padre vlr-inip, vlr-finp, fnc, arg1, arg2 en la terminal.
    2. En caso de no fallar, debe generar un proceso hijo.
    3. Considerar un posible fallo en la generación del hijo 
    con el comando fork.
    4. El código del padre debe imprimir el PID del mismo. Luego debe tomar los parámetros 
    vlr-inip vlr-finp para contar e imprimir en forma consecutiva el rango de números entre 
    estos límites.
    5. El código del hijo debe imprimir el <nombre-función> a ejecutar en el exec, PID del hijo y 
    del padre. Recordar el PID de ambos para comparar después.
    6. Ejecutar <nombre-función> con arg1 [arg2]
    7. Considerar imprimir “Fallo en la ejecución de la función”, en caso de darse esta situación.
    8. Mantener los procesos en ejecución hasta aplicar Ctrl-C.

2. Escribir los siguientes procesos (programas) que se ejecutarán con el exec():
    1. Conteo.c: Debe recibir como parámetros los números enteros arg1, arg2. Estos parámetros corresponden a los valores iniciales de un conteo entre arg1 y arg2. Debe imprimir un mensaje donde anuncie que entró a Conteo con su PID y el del padre. Comparar con los valores impresos cuando estaba en el hijo creado dentro del padre. En total debe recibir tres parámetros (¿por qué?), de no ser así, debe imprimir un mensaje de uso, parecido al del padre, pero con su formato. Si recibe sus parámetros correctamente, debe contar e imprimir los números entre arg1 y arg2, sumarlos y promediarlos. Al final, debe imprimir suma y promedio.

    2. Fibo.c: Debe recibir como parámetro el entero arg1. Este parámetro significa que debe generar los arg1 primeros números de Fibonacci e imprimirlos. Debe imprimir un mensaje donde anuncie que entró a Fibo con su PID y el del padre. Comparar con los valores impresos cuando estaba en el hijo creado dentro del padre. En total debe recibir dos parámetros (¿por qué?), de no ser así, debe imprimir un mensaje 
    de uso, parecido al del padre, pero con su formato.

    3. Primos.c: Debe recibir como parámetro el entero arg1. Este parámetro significa que debe generar los arg1 primeros números de primos e imprimirlos. Debe imprimir un mensaje donde anuncie que entró a Primo con su PID y el del padre. Comparar con los valores impresos cuando estaba en el hijo creado dentro del padre. En total debe recibir dos parámetros (¿por qué?), de no ser así, debe imprimir un mensaje 
    de uso, parecido al del padre, pero con su formato.

3. Los programas deben escribirse de la forma más simple posible. En el proceso padre se debe escribir un exec que sea general y que reciba los parámetros que requiera el proceso a ejecutar. Estos parámetros son tomados de los pasados al Padre cuando se lanza su ejecución.

**Entregable: Programas Padre.c, Conteo.c, Fibo.c, Primos.c**

## Ejemplos de uso

### Ejecución 1: Correcta con conteo.

~~~
$ ./Padre 3 7 conteo 5 9
Va a ejecutar al padre 16030
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(conteo) = 16031 de padre 16030
Entra a conteo 16031 de padre 16030
Conteo en el hijo 5
Conteo en el hijo 6
Conteo en el hijo 7
Conteo en el hijo 8
Conteo en el hijo 9
La suma = 35 y el promedio = 7.00
~~~

### Ejecución 2: Correcta con fibonacci.
~~~
$ ./Padre 3 7 fibo 5
Va a ejecutar al padre 16066
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(fibo) = 16067 de padre 16066
Entra al fibonacci 16067 de padre 16066
Fibo 1 = 0
Fibo 2 = 1
Fibo 3 = 1
Fibo 4 = 2
~~~

### Ejecución 3: Correcta con primos.
~~~
$ ./Padre 3 7 primos 5
Va a ejecutar al padre 16068
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(primos) = 16069 de padre 16068
Entra a primos 16069 de padre 16068
Primo 1 es 2
Primo 2 es 3
Primo 3 es 5
Primo 4 es 7
Primo 5 es 11
~~~

### Ejecución 4: No cuenta con los parámetros para proceso hijo
~~~
$ ./Padre 3 7
Va a ejecutar al padre 16061
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID((null)) = 16062 de padre 16061
Falló la ejecución del proceso hijo
~~~

### Ejecución 5: No cuenta con los parámetros para proceso hijo primos
~~~
$ ./Padre 3 7 primos 
Va a ejecutar al padre 16070
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(primos) = 16071 de padre 16070
Entra a primos 16071 de padre 16070
Uso: primos lim-primos
~~~

### Ejecución 6: No cuenta con los parámetros para proceso hijo fibo
~~~
$ ./Padre 3 7 fibo
Va a ejecutar al padre 16073
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(fibo) = 16074 de padre 16073
Entra al fibonacci 16074 de padre 16073
Uso: fibo lim-fibo
~~~
### Ejecución 7: No cuenta con los parámetros para proceso hijo conteo
~~~
$ ./Padre 3 7 conteo
Va a ejecutar al padre 16078
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(conteo) = 16079 de padre 16078
Entra a conteo 16079 de padre 16078
Uso: conteo ini_cont fin_cont
~~~
### Ejecución 8: No cuenta con los parámetros suficientes en el Padre
~~~
$ ./Padre 3 
Uso: ./Padre vlr-inip, vlr-finp, fnc, arg1, [arg2]...
Ejecución 9: Ejecuta al padre, pero no encuentra al proceso hijo (mal escrito)
$ ./Padre 3 7 conte 6 12
Va a ejecutar al padre 16083
Conteo en el padre 3
Conteo en el padre 4
Conteo en el padre 5
Conteo en el padre 6
Conteo en el padre 7
Va a ejecutar al hijo PID(conte) = 16084 de padre 16083
Falló la ejecución del proceso hijo
~~~

/*
Escribir un programa llamado suma.c que use wait() y exit(), donde el padre genere una 
cantidad de n hijos (n debe ser pasado como parámetro). Cada hijo debe mostrar en la 
terminal su pid y un número entero entre 0 y 9 generado aleatoriamente. Este número 
debe ser pasado al padre, quien debe mostrar su pid, el pid del hijo y el número entero 
generado. Al final debe mostrar la sumatoria de los n números.

Nota: Asegurarse que los procesos serán mostrados en el padre en cualquier orden.
Entrada:
./suma 4
Salida posible:
Hijo: PID = 48988, valor aleatorio calculado 8 
Hijo: PID = 48989, valor aleatorio calculado 6 
Hijo: PID = 48990, valor aleatorio calculado 5 
Hijo: PID = 48991, valor aleatorio calculado 8 
PADRE de PID = 48987, HIJO de PID = 48990 terminado, st = 5 
PADRE de PID = 48987, HIJO de PID = 48989 terminado, st = 6 
PADRE de PID = 48987, HIJO de PID = 48988 terminado, st = 8 
PADRE de PID = 48987, HIJO de PID = 48991 terminado, st = 8 
La suma es 27
*/
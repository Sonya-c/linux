# Unix

En SO, los procesos tienen un identificador de proceso (PIP, entero sin signo, pid_t). Todos los procesos tienen un padre que se identifica con el PPIP (Parent process ID). En las versiones viejas, el PPID creador primero es llamado init, mientras que en las versiones nuevas es systemd. Si el padre termina, el proceso hijo es adoptado por un proceso del sistema. 

| Función | Descrición |
|---------|------------|
| getpid  | Regresa id del proceso |
| getppid | Regresa id del padre del proceso 
| fork    | Crea un proceso copiano el padre. Ambos procesos, padre (llamador del fork) e hijo (proceso creado) continuando su ejecución despues del fork. Las variables inicializadas se conserva. Retorna un valor dependiendo del proceso. -1: creación del hijo falllo, 0 si es el hijo, ib de proceso hijo.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: Padre vlr-inip, vlr-finp, fnc, arg1, arg2\n");
        return 1;
    }
    pid_t pid = fork();

    while(true) {
        if (pid > 0) { // padre
            printf("Va a ejecutar al padre %d\n", getpid());
            int vlr_inip = atoi(argv[1]);
            int vlr_finp = atoi(argv[2]);
            
            for (int i = vlr_inip; i <= vlr_finp; i++) {
                printf("Conteo en el padre %d\n", i);
            }

        } else if (pid == 0) { // hijo
            printf("Va a ejecutar al hijo PID(%s) = %d de padre %d\n", argv[3], getpid(), getppid());
            
            char *args[] = {argv[3], argv[4], argv[5], NULL};
            
            char path[100];
            sprintf(path, "%s%s", "./", argv[3]); 
            printf("path: %s\n", path); 

            if (execv(path, args) == -1) {
                perror("execv");
                return 1;
            }
        } else { // falló
            printf("Falló la ejecución del proceso hijo\n");
        }
    }
    return 0;
}
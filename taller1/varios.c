#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main( int argc, char *argv[] )  {
    int n = atoi(argv[1]);

    printf("Soy el padre con ", getpid());

    for (int i = 0; i < n; i = i + 1) {
        pid_t pid = fork();

        if (pid == 0) {
            printf("Soy un hijo con pid %d y padre %d", getpid(), getppid());
        }
    }

    while(1) {}

    return 0;
}
#include <unistd.h>

int main() {
    char* args[] = { "./mi_programa", "Roberto", "Mario", NULL };
    char* envp[] = { NULL };
    execve("./mi_programa", args, envp);
    return 0;
}
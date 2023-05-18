#include <unistd.h>

int main() {
    char* envp[] = { NULL };
    execle("./mi_programa", "mi_programa", "Roberto", "Mario", NULL, envp);
    return 0;
}
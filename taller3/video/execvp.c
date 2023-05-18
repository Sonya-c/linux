#include <unistd.h>

int main() {
    char* args[] = { "mi_programa", "Roberto", "Mario", NULL };
    execvp("mi_programa", args);
    return 0;
}
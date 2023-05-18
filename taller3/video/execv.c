#include <unistd.h>

int main() {
    char* args[] = { "./mi_programa", "Roberto", "Mario", NULL };
    execv("./mi_programa", args);
    return 0;
}
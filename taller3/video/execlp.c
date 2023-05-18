#include <unistd.h>

int main() {
    execlp("mi_programa", "mi_programa", "Roberto", "Mario", NULL);
    return 0;
}
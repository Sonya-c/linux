#include <unistd.h>

int main() {
    execl("./mi_programa", "mi_programa", "Roberto", "Mario", NULL);
    return 0;
}

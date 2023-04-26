// un padre genera 3 hijos
// el primer hijo tiene dos hijos
// el segundo hijo tiene un hijo que, a su vez, tiene un hijo

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2 = -2, child3 = -2, granson;
    
    child1 = fork();

    /*
    padre   .--> padre child1 != 0  .--> padre  chidl2 !=0  ---> padre child3 != 0
                       child2 == -1             child1 !=0             child2 != 0
                       child3 == -1             child3 ==-1            child1 != 0     
                                                            .--> hijo 2 child3 == 0
                                                                        child2 != 0
                                                                        child1 != 0
                                    .--> hijo 2 child2 ==0 --> nieto 3 -> bisneto 1
                                                child1 != 0
                                                child3 == -1
            .--> hijo1 child1 == 0  .--> nieto1, nieto 2
                       child2 == -1
                       child3 == -1
    */
    
    if (child1 != 0) { // es el padre
        child2 = fork();

        if (child2 != 0) { // es el padre
            child3 = fork();
        }
    }
    
    // printf("pid %d %d %d %d\n", getpid(), child1, child2, child3);
    if (child1 == 0 && child2 == -2 && child3 == -2) {
        granson = fork();

        if (granson != 0) {       
            fork();
        }
    }

    if (child1 != 0 && child2 == 0 && child3 == -2) {
        granson = fork();

        if (granson == 0) {
            fork();
        } 
    }
    while(1);
    return 0;
}
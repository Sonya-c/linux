#include  <stdio.h>
/*#include  <sys/types.h>*/
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int id1 = fork(); // id del hijo 1
	int id2 = fork(); // id del hijo 2

	/*
	padre --> padre id1 != 0 --> padre  id2 != 0
				    		|--> hijo 2 id2 = 0
		 |--> hijo 1 id1=0  --> hijo 1 id2 != 0
		 					|--> hijo 3 id2 = 0
	*/

	if (id1 == 0) { // es el hijo 1 o hijo 3
		if (id2 == 0) { // hijo 3
			printf("Soy el proceso hijo 3 con PID = %d con padre PPID = %d\n", getpid(),getppid());
		} else { // es hijo 1
			printf("Soy el proceso hijo 1 con PID = %d con padre PPId = %d\n", getpid(),getppid());
		}
	} else { // padre o hijo 2
		if (id2 == 0) { // hijo 2
			printf("Soy el proceso hijo 2 con PID = %d con padre PPID = %d\n", getpid(),getppid());
		} else { // padre
			printf("Soy el proceso padre inicial %d\n", getpid());
		}
	}	
	wait(NULL);
	return 0;
}

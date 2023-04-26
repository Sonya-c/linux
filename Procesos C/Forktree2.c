#include  <stdio.h>
/*#include  <sys/types.h>*/
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int id1 = fork();
	int id2 = fork();
	if (id1 == 0) {
		if (id2 == 0) {
			printf("Soy el proceso hijo con PID = %d con padre PPID = %d\n", getpid(),getppid());
		} else {
			printf("Soy el proceso hijo con PID = %d con padre PPId = %d\n", getpid(),getppid());
		}
	} else {
		if (id2 == 0) {
			printf("Soy el proceso hijo con PID = %d con padre PPID = %d\n", getpid(),getppid());
		} else {
			printf("Soy el proceso padre inicial\n");
		}
	}	
	wait(NULL);
	return 0;
}

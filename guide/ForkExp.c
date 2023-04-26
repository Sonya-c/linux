#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int var = 22;

int main(void)
{
	pid_t pidC;
	printf("**proc. PID = %d comienza  **\n", getpid());
	pidC = fork();
	int i;

	printf("proc. PID = %d, pidC = %d ejecutándose  **\n", getpid(), pidC);

	if (pidC > 0)
	{
		var = var + 4;
	}
	else if (pidC == 0)
	{
		var = var + 3;
	}
	else /** error **/
	{
	}

	printf("proc. PID = %d, var = %d ejecutándose  **\n", getpid(), var);

	for (i = 1; i <= 20000; i++)
		//sleep(2);
		printf("   Tproc. PID = %d, var = %d ejecutándose i= %d  **\n", getpid(), var, i);

	/*	while(1);
	{
		sleep(2);
		printf("proc. PID = %d, var = %d ejecutándose  **\n", getpid(), var);
	}
*/
	return 0;
}
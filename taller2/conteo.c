#include<stdio.h> 
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int status;
	pid_t hijo=fork();
	if(hijo!=0){
		printf("Proceso padre y PID %d\n",getpid());
		for(int i=9;i <= 19; i++){
			printf("%d\n",i);
			if(n == i){
				wait(&status);
				printf("Hijo terminado y valor de status %d\n",WEXITSTATUS(status));
			}
		}
	}else{
		printf("Proceso hijo y PID %d\n",getpid());
		for(int i=0;i <= 8; i++){
			printf("%d\n",i);
		}
		exit(status);
	}	
}

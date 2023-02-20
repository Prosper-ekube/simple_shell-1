#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t my_pid;
        int status;	
	while(1)
	{
		printf("$ ");
		getline(&command, &len, stdin);
		
		stkn =  strtok(command, " \n");
		char *arr[] = {stkn, NULL};

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error");
			return (1);
		}

		
		else if (my_pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
			{
				perror(argv[0]);
				return (1);
			}

			execve(arr[0], arr, NULL);
		}

		else
		{
			wait(&status);
		}


	}
	free(command);
	return (0);
}

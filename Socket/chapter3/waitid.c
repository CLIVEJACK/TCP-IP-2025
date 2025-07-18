#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int status;
	pid_t pid = fork();

	if(pid == 0) {
		sleep(15);
		return 24;
	}
	else {
		while(!waitpid(-1, &status, WNOHANG)){
			sleep(3);
			puts("sleep 3sec");
		}
		if(WIFEXITED(status)) printf("child send %d", WEXITSTATUS(status));
	}
	return 0;
}

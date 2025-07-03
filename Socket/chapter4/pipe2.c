//4 
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fds[2];
	char str[] = "Who R U?...";
	char str2[] = " Thank U for UR message.";
	char buf[50];
	pid_t pid;

	pipe(fds);
	pid = fork(); // 자식프로세서 생성

	if(pid == 0) { // 자식
		write(fds[1], str, sizeof(str));
		sleep(2);
		read(fds[0], buf, sizeof(buf));
		printf("child proc output: %s\n", buf);
	}
	else {
		read(fds[0], buf, sizeof(buf)); // 부모 
		printf("parent proc output: %s\n", buf);
		write(fds[1], str2, sizeof(str2));
		sleep(3);
	}
	return 0;
}

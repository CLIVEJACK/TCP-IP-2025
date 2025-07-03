//3 
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fds[2];
	char str[] = "Who are you?";
	char buf[30];
	pid_t pid;

	pipe(fds);
	pid = fork();
	if(pid == 0) write(fds[1], str, sizeof(str)); // 자식 , 자식이 보내서
	else {
		read(fds[0], buf, sizeof(buf)); // 부모, 부모가 읽어옴
		puts(buf);
	}
	return 0;
}

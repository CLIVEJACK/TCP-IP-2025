//5 
#include <stdio.h>
#include <unistd.h>

void main()
{
	int fds[2], fds2[2]; 		// 입출력 을바꿔서 출력
	char str[] = "who R U";
	char str2[] = "thank U";
	char buf[30];
	pid_t pid;		//pid_t 타입 보기 
	pipe(fds), pipe(fds2);
	pid = fork();

	if(pid == 0) {
		write(fds[1], str, sizeof(str));
		read(fds2[0],  buf, sizeof(buf));
		printf("child: %s\n", buf);
	}else {
		read(fds[0], buf, sizeof(buf));
		printf("parent: %s\n", buf);
		write(fds2[1], str2, sizeof(str2));
		sleep(3);
	}
}

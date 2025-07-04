#include <stdio.h>
#include <unistd.h>
#include <poll.h>


int main()
{
	struct pollfd pfd;		// 감시할 FD와 이벤트를 담을 구조체
		
	pfd.fd = STDIN_FILENO;  // 표준입력등록
	pfd.events = POLLIN;		// 입력에 해당하는 FD에 입력이 해당되면 이벤트 발생

	printf("Wait 5 seconds......\n");

	int ret = poll(&pfd, 1, 5000); 		// 파일 디스크립트 등록 1을 5초로 등록
	
	if(ret == -1) perror("poll error\n");
	else if(ret == 0) printf("timeout");
	else{
		if(pfd.revents & POLLIN) {		// 실제로 발생하는 이벤트는 revernts에 저장
			char buffer[100];
			fgets(buffer, sizeof(buffer), stdin);
			printf("Entered: %s\n", buffer);
		}
	}
	return 0;
}

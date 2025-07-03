// 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

int main()
{
	fd_set reads, temps;
	int result, str_len;
	char buf [BUF_SIZE];
	struct timeval timeout;

	FD_ZERO(&reads);
	FD_SET(0, &reads);	// 파일디스크립터 0번을 fdest에 등록

	while(1) {
		temps = reads;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;
		result = select(1, &temps, 0, 0, &timeout);
		if(result == -1) {
			puts("select() error");
			break;
		} else if (result == 0) puts("time-out");
		else {
			if(FD_ISSET (0, &temps)) // 0번이면 temps에 있는 거실행
			{
				str_len = read(0, buf, BUF_SIZE);
				buf[str_len] ='\0';
				printf("message from consol: %s", buf);
			}
		}
	}

	 return 0;
}

#include <stdio.h>
#include <unistd.h>

int globalval = 10;					// 전역변수

int main()
{
	pid_t pid;
	int localval = 20;				// 지역변수

	globalval++;			// 11
	localval += 5;			// 25 

	pid = fork();
	if(pid == 0) {
		globalval += 2;
		localval += 2;
	} else{
		globalval -=2;
		localval -=2;
	}

	if(pid == 0) printf("Child proc: [%d, %d]\n", globalval, localval);
	else printf("Parent proc: [%d, %d]\n", globalval, localval);

	return 0;
}

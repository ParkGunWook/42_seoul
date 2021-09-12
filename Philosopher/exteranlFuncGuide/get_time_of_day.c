#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	struct timeval *tv;
	struct timezone *tz;

	tv = malloc(sizeof(tv));
	tz = malloc(sizeof(tz));

	gettimeofday(tv, tz);
	printf("%d\n", tv->tv_usec);
	int start = tv->tv_usec;
	sleep(3);
	int end = tv->tv_usec;
	printf("%d\n", tv->tv_usec);
	printf("diff : %d\n", end - start);
}
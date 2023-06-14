
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
//without the pthread.h headerfile, use gcc -pthread flag or it won't work.

// void *routine()
// {
// 	printf("Test from threads\n");
// 	usleep(1000000);
// 	printf("Ending thread\n");
// 	printf("Process id %d\n", getpid());
// }

int x = 2;

void *routine()
{
	x += 5;
	sleep(2);
	printf("Value of x: %d\n", x);
}

void *routine2()
{
	sleep(2);
	printf("Value of x: %d\n", x);
}

int main(int argc, char **argv)
{
	pthread_t t1, t2;
	//these are happening parallel
	if (pthread_create(&t1, NULL, &routine, NULL) != 0) //there can be error in the thread, so adding the if statement is correct way to do.
	{
		return 1;
	}
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return 2;
	}
	//pthread_join is wait function for thread
	if (pthread_join(t1, NULL) != 0)
	{
		return 3;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 4;
	}
	return 0;
}

// int main(void)
// {
// 	while (1)
// 	{
// 		write (1, "Mississippi\n", 12);
// 		usleep(1000 *1000);
// 	}
// }

// int main()
// {
// 	struct timeval time_info;

// 	gettimeofday(&time_info, NULL);
// 	printf("time is %ld seconds\n", time_info.tv_sec);
// 	return (0);
// }
/* gettimeofday function tells you microseconds.
tv_sec and tv_usec saves the current system time.*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

/*each thread increases value to 100, so it would be 100 * number of threads
if incremation value goes bigger than 10000, race condition happens where 2nd thread
creation happens while you are incrementing the value of mail. if it is smaller incrementation
value, mails value is most likely reached to its end of incrementation value before 2nd threads
creation happens*/
int mails = 0;

void *routine()
{
	for (int i = 0; i < 100; i++)
		mails++;
		//read value of mails
		//increment
		//write mails
}

// void *routine2()
// {
// 	sleep(2);
// 	printf("Value of x: %d\n", x);
// }

int main(int argc, char **argv)
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	{
		return 1;
	}
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return 2;
	}
	if (pthread_join(t1, NULL) != 0)
	{
		return 3;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 4;
	}
	printf("number of mails: %d\n", mails);
	return 0;
}

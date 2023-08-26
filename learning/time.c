#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval current_time;
	struct timeval hehe;
    
    // Get the current time
    gettimeofday(&current_time, NULL);
    
    // Access the seconds and microseconds components
    printf("Seconds: %ld\n", current_time.tv_sec);
    printf("Microseconds: %d\n", current_time.tv_usec);
    
    return 0;
}

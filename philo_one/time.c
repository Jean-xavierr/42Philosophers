#include <sys/time.h>
#include <stdio.h>



void	ft_time(void)
{
	struct timeval start_time;
	gettimeofday(&start_time, NULL);
	printf("time sec: %ld | time microsec %d\n", start_time.tv_sec, start_time.tv_usec);
	int i = 0;
	while (i < 10000)
		i++;
	struct timeval end_time;
	gettimeofday(&end_time, NULL);
	printf("time sec: %ld | time microsec %d\n", end_time.tv_sec - start_time.tv_sec, end_time.tv_usec -start_time.tv_usec);
	
}

int 	main(void)
{
	ft_time();
	return (0);
}
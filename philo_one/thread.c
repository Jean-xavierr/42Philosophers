#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	*myturn(void *data)
{
	int i;
	int *myvar;

	myvar = (int *)data;
	i = 0;
	while (i < 10)
	{
		sleep(1);
		printf("My Turn! %d | myvar %d\n", i, *myvar);
		i++;
	}
	return NULL;
}

void	yourturn(void)
{
	int i;

	i = 0;
	while (i < 3)
	{
		sleep(2);
		printf("You Turn! %d\n", i);
		i++;
	}
}

int		main(void)
{
	pthread_t	newthread;
	int var;

	var = 2;
	pthread_create(&newthread, NULL, myturn,  &var);
	// myturn();
	yourturn();
	pthread_join(newthread, NULL);
	return (0);
}
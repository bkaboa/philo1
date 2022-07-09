#include "Includes/philo.h"
#include <pthread.h>

static void	monitor(void philo)

static void	*routine(void *philo)
{
	t_philo		*philos;
	pthread_t	tid;

	philos = (t_philo*)philo;
	while (1)
	{
		if (take_fork(philo) != 0)
		if (eat(philo) != 0)
		if (sleep(philo) != 0)
	}
}

static void init_thread(t_rules *rules)
{
	u_int16_t	i;
	pthread_t	tid;
	void		*philo;

	i = 0;
	rules->time = get_time();
	while (i < rules->n_philo)
	{
		philo = (void*)(&rules->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return ;
		pthread_detach(tid);
		usleep(100);
		++i;
	}
}

int main(int argc, char **argv)
{
	t_rules		rules;

	argv[argc] = NULL;
	if (argc != 5 || argc != 6)
		return (write_error(WRONG_N_ARG));
	if (init_rules(argc, argv, &rules) == false)
		return (1);
	init_thread(&rules);
	return (0);
}

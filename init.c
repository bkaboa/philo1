#include "Includes/philo.h"

static void	init_philos(t_rules *rules)
{
	u_int16_t	i;

	i = 1;
	while ( i < rules->n_philo + 1)
	{
		rules->philos[i].fork_right_hand = i;
		rules->philos[i].fork_left_hand = (i + 1) % rules->n_philo;
		rules->philos[i].n_eating = 0;
		rules->philos[i].philo_pos = i;
		rules->philos[i].rules = rules;
		pthread_mutex_init(&(rules->philos[i].mutex), NULL);
		pthread_mutex_init(&(rules->philos[i].eat_mutex), NULL);
		pthread_mutex_lock(&(rules->philos[i].eat_mutex));
		++i;
	}
}

static void	init_mutex_rules(t_rules *rules)
{
	u_int16_t	i;

	i = 0;
	pthread_mutex_init(&(rules->message_m), NULL);
	pthread_mutex_init(&(rules->dieded), NULL);
	pthread_mutex_lock(&(rules->dieded));
	rules->fork_m = malloc(sizeof(pthread_mutex_t) * rules->n_philo);
	while (i < rules->n_philo)
		pthread_mutex_init(&(rules->fork_m[i++]), NULL);
}

static bool	check_rules(t_rules rules, int argc)
{
	bool	function;
	if (rules.n_philo <= 1)
		return (false);
	if (rules.time_to_die <= 60)
		return (false);
	if (rules.n_must_eat <= 60)
		return (false);
	if (rules.time_to_sleep <= 60)
		return (false);
	if (argc == 6)
	{
		if (rules.n_must_eat <= 0)
			return(false);
	}
	return (true);
}

bool	init_rules(int argc, char **argv, t_rules *rules)
{
	ft_atoi(argv[1], &rules->n_philo);
	ft_atoi(argv[2], &rules->time_to_die);
	ft_atoi(argv[3], &rules->time_to_eat);
	ft_atoi(argv[4], &rules->time_to_sleep);
	if (argc == 6)
	{
		ft_atoi(argv[5], &rules->n_must_eat);
	}
	if (check_rules(*rules, argc) == false)
		return (false);
	rules->all_ate = 0;
	if (!(rules->philos = malloc(sizeof(t_philo) * rules->n_philo)))
		return (false);
	init_philos(rules);
	init_mutex_rules(rules);
	return (true);
}

#include "Includes/philo.h"

static bool	check_philo(t_rules rules)
{
	if (rules.n_philo <= 0)
		return (false);
	if (rules.time_to_die <= 0)
		return (false);
	if (rules.time_to_eat <= 0)
		return (false);
	if (rules.time_to_sleep <= 0)
		return (false);
	if (rules.n_must_eat != -2)
	{
		if (rules.n_must_eat <= 0)
			return (false);
	}
	return (true);
}

bool	init_rules(char **argv)
{
	t_rules	rules;

	rules.n_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules.n_must_eat = ft_atoi(argv[5]);
	else
		rules.n_must_eat = -2;
	rules.all_ate = 0;
	rules.dieded = false;
	return (check_philo(rules));
}

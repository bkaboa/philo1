#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define INT32_MIN		INT_MIN
# define INT32_MAX		INT_MAX
# define WRONG_N_ARG	"bad nubers of arguments\n"

typedef	char*	t_string;

typedef struct	s_rules
{
	int32_t			n_philo;
	int32_t			time_to_die;
	int32_t			time_to_eat;
	int32_t			time_to_sleep;
	int32_t			n_must_eat;
	u_int32_t		all_ate;
	bool			dieded;
}	t_rules;

typedef struct	s_philo
{
	bool			fork_right_hand;
	bool			fork_left_hand;
	t_rules			*rules;
	pthread_t		thread_id;
}	t_philo;

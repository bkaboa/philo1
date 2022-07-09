#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

# define INT32_MIN		INT_MIN
# define INT32_MAX		INT_MAX
# define UINT16_MAX		USHRT_MAX
# define UINT8_MAX		UCHAR_MAX
# define WRONG_N_ARG	"invalid number of arguments\n"

# define THINK_M		"think\n"
# define EAT_M			"eat\n"
# define SLEEP_M		"sleep\n"
# define DIED_M			"dead\n"

typedef	char*	t_string;

typedef struct	s_rules
{
	int32_t				n_philo;
	int32_t				time_to_die;
	int32_t				time_to_eat;
	int32_t				time_to_sleep;
	int32_t				n_must_eat;
	u_int32_t			all_ate;
	int64_t				time_statrt;
	pthread_mutex_t		dieded;
	pthread_mutex_t		message_m;
	pthread_mutex_t		*fork_m;
	struct s_philo		*philos;
}	t_rules;

typedef struct	s_philo
{
	pthread_mutex_t		mutex;
	pthread_mutex_t		eat_mutex;
	u_int16_t			fork_right_hand;
	u_int16_t			fork_left_hand;
	u_int32_t			n_eating;
	u_int32_t			philo_pos;
	u_int64_t			last_eat;
	t_rules				*rules;
}	t_philo;

/*
 ******************************		utils.c			***
*/
bool		ft_atoi(t_string str, int32_t *ret);
u_int16_t	ft_strlen(t_string str);
int			write_error(t_string error);
u_int32_t	get_time(void);

/*
 ******************************		utils.c			***
*/
bool	init_rules(int argc, char **argv, t_rules *rules);
#endif

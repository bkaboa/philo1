#include "Includes/philo.h"
#include <limits.h>
#include <sys/types.h>

u_int16_t	ft_strlen(const t_string str)
{
	t_string	temp;

	temp = str;
	while (((u_int8_t)*temp & UINT8_MAX) != 0)
		temp++;
	return (temp - str);
}

bool	ft_atoi(t_string str, int32_t *ret)
{
	int64_t		atoi;

	*ret = 1;
	if (str[0] == '-')
		return (false);
	if (ft_strlen(str) > 10)
		return (false);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (false);
		atoi = atoi * 10 + (*str - 48);
	}
	if (atoi > (int64_t)INT32_MIN * -1)
		return (false);
	*ret *= atoi;
	return (true);
}

u_int32_t	get_time(void)
{
	static struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_usec);
}

int		write_error(t_string error)
{
	write(1, error, ft_strlen(error));
	return (1);
}

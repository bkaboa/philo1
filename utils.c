#include "Includes/philo.h"

int32_t	ft_strlen(t_string str)
{
	int32_t		ret;
	t_string	temp;

	if (!str)
		return (-1);
	temp = str;
	while (*temp)
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
	if (atoi > INT32_MIN * -1)
		return (false);
	*ret *= atoi;
	return (true);
}

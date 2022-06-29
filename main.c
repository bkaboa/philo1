#include "Includes/philo.h"

int main(int argc, char **argv)
{
	argv[argc] = NULL;
	if (argc != 5 || argc != 6)
		return (write_error(WRONG_N_ARG));
	if (init_all(argv) == false)
		return (1);
}

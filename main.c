#include "main.h"

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i <= argc)
	{
		ft_putnbr_fd(123, 1);
		write(1, argv[i], 2);
		write(1, "\n", 1);
		i++;
	}
	
	write(1, "hello world\n", 12);
}
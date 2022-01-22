#include "main.h"

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (0);
	i = 1;
	while (i <= argc)
	{
		ft_putendl_fd(argv[i], 1);
		i++;
	}
	
	write(1, "hello world\n", 12);
}
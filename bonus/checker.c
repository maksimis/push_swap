#include "checker.h"

int main(int argc, char **argv)
{
	int	i;
	char *all_arg;
	char *tmp;
	char *tmp2;
	char **splited_args;
	char **splited_args_temp;
	int *stack_a;
	int *stack_b;
	int length;

	i = 1;
	all_arg = ft_strdup("");
	while (i < argc)
	{
		if (ft_strlen(all_arg) > 0)
		{
			tmp2 = all_arg;
			all_arg = ft_strjoin(all_arg, " ");
			free(tmp2);
		}
		tmp = all_arg;
		all_arg = ft_strjoin(all_arg, argv[i]);
		free(tmp);
		i++;
	}
	splited_args = ft_split(all_arg, ' ');
	free(all_arg);
	splited_args_temp = splited_args;
	length = i;
	stack_a = malloc(sizeof(int) * length);
	stack_b = malloc(sizeof(int) * length);
	i = 0;
	while (*splited_args_temp)
	{
		stack_a[i] = ft_atoi(*splited_args_temp);
		free(*splited_args_temp);
		splited_args_temp++;
		i++;
	}
	i = 0;
	while (i < length)
	{
		ft_putnbr_fd(stack_a[i], 1);
		ft_putendl_fd("", 1);
		i++;
	}
	return (1);
}
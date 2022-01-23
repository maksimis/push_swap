#include "main.h"

int main(int argc, char **argv)
{
	int	i;
	char *all_arg;
	char *tmp;
	char *tmp2;
	char **splited_args;

	if (argc == 1)
		return (0);
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
	while (*splited_args)
	{
		ft_putendl_fd(*splited_args, 1);
		free(*splited_args);
		splited_args++;
	}
	return (1);
}
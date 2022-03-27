#include "main.h"

void ft_putnbr(int a)
{
	ft_putnbr_fd(a, 1);
	ft_putendl_fd("", 1);
}

int main(int argc, char **argv)
{
	int	i;
	char *all_arg;
	char *tmp;
	char *tmp2;
	char **splited_args;
	t_int_list	*list_a;
	t_int_list	*list_b;

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
	list_a = i_l_new(1);
	list_b = i_l_new(2);
	i_l_add_back(&list_a, i_l_new(3));
	i_l_add_back(&list_b, i_l_new(4));
	i_l_iter(list_a, ft_putnbr);
	i_l_iter(list_b, ft_putnbr);
	sa(&list_a);
	sb(&list_b);
	//ss(&list_a, &list_b);
	i_l_iter(list_a, ft_putnbr);
	i_l_iter(list_b, ft_putnbr);
	return (1);
}
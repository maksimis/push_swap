#include "../main.h"

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	clear_error_and_exit(t_int_list *a)
{
	i_l_clear(&a);
	error_and_exit();
}

void	check_has_dup(t_int_list *list)
{
	t_int_list *copy;

	if (list->next)
		copy = list->next;
	while (list && copy)
	{
		while (copy)
		{
			if (list->content == copy->content)
			{
				error_and_exit();
			}
			copy = copy->next;
		}
		list = list->next;
		if (list->next)
			copy = list->next;
	}
}

int	is_desc(t_int_list *list, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (list->next && list->next->content > list->content)
			return (0);
		i++;
	}
	return (1);
}

int	is_asc(t_int_list *list, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (list->next && list->next->content < list->content)
			return (0);
		i++;
	}
	return (1);
}

void init_stack(t_int_list **list, int argc, char **argv)
{
	int	i;
	char *all_arg;
	char *tmp;
	char *tmp2;
	char **splited_args;
	char **splited_args_temp;

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
	while (*splited_args_temp)
	{
		i_l_add_back(list, i_l_new(ft_atoi(*splited_args_temp)));
		free(*splited_args_temp);
		splited_args_temp++;
	}
	free(splited_args);
}
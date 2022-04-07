/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:26 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 11:28:26 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	check_has_dup(t_int_list *list)
{
	t_int_list	*copy;

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
	int	i;

	i = 0;
	while (list && i < len)
	{
		if (list->next && list->next->content > list->content)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int	is_asc(t_int_list *list, int len)
{
	int	i;

	i = 0;
	while (list && i < len)
	{
		if (list->next && list->next->content < list->content)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

char	*concat_args(int argc, char **argv)
{
	int		i;
	char	*all_arg;
	char	*tmp;
	char	*tmp2;

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
	return (all_arg);
}

void	init_stack(t_int_list **list, int argc, char **argv)
{
	char	*all_arg;
	char	**splited_args;
	char	**splited_args_temp;

	all_arg = concat_args(argc, argv);
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

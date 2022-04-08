/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:25 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:21:35 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

bool	swap(t_int_list **list, char *command)
{
	t_int_list	*temp1;
	t_int_list	*temp2;

	if (i_l_size(*list) >= 2)
	{
		temp1 = (*list)->next->next;
		temp2 = *list;
		*list = (*list)->next;
		(*list)->next = temp2;
		(*list)->next->next = temp1;
		if (command)
			ft_putendl_fd(command, 1);
	}
	return (true);
}

void	sa(t_int_list **list)
{
	swap(list, "sa");
}

void	sb(t_int_list **list)
{
	swap(list, "sb");
}

void	ss(t_int_list **list_a, t_int_list **list_b)
{
	sa(list_a);
	sb(list_b);
}

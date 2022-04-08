/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:23 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:21:35 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

bool	rotate(t_int_list **list, char *command)
{
	t_int_list	*temp1;

	if (i_l_size(*list) >= 2)
	{
		temp1 = *list;
		*list = (*list)->next;
		temp1->next = 0;
		i_l_add_back(list, temp1);
		if (command)
			ft_putendl_fd(command, 1);
	}
	return (true);
}

void	ra(t_int_list **list_a)
{
	rotate(list_a, "ra");
}

void	rb(t_int_list **list_b)
{
	rotate(list_b, "rb");
}

void	rr(t_int_list **list_a, t_int_list **list_b)
{
	ra(list_a);
	rb(list_b);
}

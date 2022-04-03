/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:21 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 11:28:21 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	reverse(t_int_list **list, char *command)
{
	t_int_list	*last;
	t_int_list	*pre_last;

	if (i_l_size(*list) >= 2)
	{
		pre_last = *list;
		while (pre_last->next->next)
			pre_last = pre_last->next;
		last = pre_last->next;
		pre_last->next = 0;
		i_l_add_front(list, last);
		ft_putendl_fd(command, 1);
	}
}

void	rra(t_int_list **list_a)
{
	reverse(list_a, "rra");
}

void	rrb(t_int_list **list_b)
{
	reverse(list_b, "rrb");
}

void	rrr(t_int_list **list_a, t_int_list **list_b)
{
	rra(list_a);
	rrb(list_b);
}

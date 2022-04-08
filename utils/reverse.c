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

bool	reverse(t_int_list **list)
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
	}
	return (true);
}

void	rra(t_int_list **list_a)
{
	reverse(list_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_int_list **list_b)
{
	reverse(list_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_int_list **list_a, t_int_list **list_b)
{
	reverse(list_a);
	reverse(list_b);
	ft_putendl_fd("rrr", 1);
}

void	rewind_stack(t_int_list **a, t_int_list **b, int cnt)
{
	while (cnt > 0)
	{
		rrr(a, b);
		--cnt;
	}
}

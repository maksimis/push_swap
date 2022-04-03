/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:19 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 11:28:19 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	push(t_int_list **source, t_int_list **destination, char *command)
{
	t_int_list	*temp;

	if (i_l_size(*source) > 0)
	{
		temp = *source;
		*source = (*source)->next;
		i_l_add_front(destination, temp);
		ft_putendl_fd(command, 1);
	}
}

void	pa(t_int_list **list_a, t_int_list **list_b)
{
	push(list_b, list_a, "pa");
}

void	pb(t_int_list **list_a, t_int_list **list_b)
{
	push(list_a, list_b, "pb");
}

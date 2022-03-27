/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:24:22 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/21 12:48:37 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	i_l_add_back(t_int_list **lst, t_int_list *new)
{
	t_int_list	*last;

	if (*lst)
	{
		last = *lst;
		while (last->next)
			last = (last)->next;
		last->next = new;
	}
	else
		*lst = new;
}

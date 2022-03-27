/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:24:32 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/17 09:24:32 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	i_l_clear(t_int_list **lst)
{
	t_int_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			(*lst) = tmp;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:24:52 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/17 09:24:54 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

int	i_l_size(t_int_list *lst)
{
	int	result;

	result = 0;
	while (lst)
	{
		result++;
		lst = lst->next;
	}
	return (result);
}

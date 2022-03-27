/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:24:42 by cmichael          #+#    #+#             */
/*   Updated: 2022/01/17 09:24:47 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

t_int_list	*i_l_last(t_int_list *lst)
{
	t_int_list	*result;

	result = lst;
	if (result == NULL)
		return (NULL);
	while (result->next)
		result = result->next;
	return (result);
}

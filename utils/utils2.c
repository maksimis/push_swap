/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:27 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:19:04 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	reverse_a(t_int_list **list_a, t_int_list **list_b, int len)
{
	int		i;

	i = 0;
	if (len == 2)
		sa(list_a);
	else if (len == 3)
	{
		sa(list_a);
		rra(list_a);
	}
	else
	{
		while (i < len - 1)
		{
			pb(list_a, list_b);
			i++;
		}
		while (i > 0)
		{
			pa(list_a, list_b);
			ra(list_a);
			i--;
		}
	}
}

int	get_min_val(t_int_list *head)
{
	t_int_list	*cur;
	int			min_val;

	cur = head->next;
	min_val = head->content;
	while (1)
	{
		if (cur == NULL)
			break ;
		if (min_val > cur->content)
			min_val = cur->content;
		cur = cur->next;
	}
	return (min_val);
}

int	get_max_val(t_int_list *head)
{
	t_int_list	*cur;
	int			max_val;

	cur = head->next;
	max_val = head->content;
	while (1)
	{
		if (cur == NULL)
			break ;
		if (max_val < cur->content)
			max_val = cur->content;
		cur = cur->next;
	}
	return (max_val);
}

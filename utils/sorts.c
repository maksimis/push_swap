/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:27 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:19:04 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	sort(t_int_list **list_a, t_int_list **list_b, int len)
{
	if (len == 3)
		sort_3(list_a);
	else if (len == 4)
		sort_4(list_a, list_b);
	else if (len == 5)
		sort_5(list_a, list_b);
	else
		a_to_b(list_a, list_b, len);
}

void	sort_3(t_int_list **a)
{
	if ((*a)->content == get_min_val(*a))
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->content == get_max_val(*a))
		ra(a);
	else
	{
		if ((*a)->next->content == get_min_val(*a))
			sa(a);
		else
			rra(a);
	}
}

void	sort_4(t_int_list **a, t_int_list **b)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
	pb(a, b);
	if ((*a)->content > (*a)->next->content)
		sa(a);
	pb(a, b);
	if ((*a)->content > (*a)->next->content && (*b)->content < (*b)->next->content)
		ss(a, b);
	else if ((*a)->content > (*a)->next->content)
		sa(a);
	else if ((*b)->content < (*b)->next->content)
		sb(b);
	pa(a, b);
	if ((*a)->content > (*a)->next->content)
		sa(a);
	pa(a, b);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_minmax(t_int_list **a, t_int_list **b, int min_val)
{
	if ((*b)->content == min_val)
		pa(a, b);
	else
	{
		pa(a, b);
		ra(a);
	}
}

void	sort_5(t_int_list **a, t_int_list **b)
{
	int	min_val;
	int	max_val;
	int	cnt_pb;

	min_val = get_min_val(*a);
	max_val = get_max_val(*a);
	cnt_pb = 0;
	while (i_l_size(*a) > 3)
	{
		if ((*a)->content == min_val || (*a)->content == max_val)
		{
			pb(a, b);
			++cnt_pb;
		}
		else
			ra(a);
	}
	if (is_desc(*a, 3))
		reverse_a(a, b, 3);
	else if (!is_asc(*a, 1))
		sort_3(a);
	while (cnt_pb-- > 0)
		sort_minmax(a, b, min_val);
}
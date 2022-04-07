/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:27:59 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:23:40 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

void	conquer_a(t_int_list **a, t_int_list **b, int cnt)
{
	if (cnt == 2 || cnt == 3)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		if (cnt == 3 && !is_asc(*a, cnt))
		{
			ra(a);
			sa(a);
			rra(a);
			if ((*a)->content > (*a)->next->content)
				sa(a);
		}
	}
	else if (cnt == 4)
		sort_4(a, b);
	else if (cnt == 5)
		sort_5(a, b);
}

void	divide_a(t_int_list **a, t_int_list **b, int cnt, t_param *param)
{
	while (cnt > 0)
	{
		if ((*a)->content <= param->pvt_less)
		{
			pb(a, b);
			++(param->cnt_pb);
		}
		else if ((*a)->content > param->pvt_greater)
		{
			ra(a);
			++(param->cnt_ra);
		}
		else
		{
			pb(a, b);
			++(param->cnt_pb);
			rb(b);
			++(param->cnt_rb);
		}
		--cnt;
	}
}

void	a_to_b(t_int_list **a, t_int_list **b, int cnt)
{
	t_param	param;

	if (cnt <= 5)
	{
		if (!is_asc(*a, cnt))
			conquer_a(a, b, cnt);
		return ;
	}
	param = (t_param){0, };
	set_pvt(*a, cnt, 'a', &param);
	divide_a(a, b, cnt, &param);
	rewind_stack(a, b, param.cnt_rb);
	a_to_b(a, b, param.cnt_ra);
	b_to_a(a, b, param.cnt_rb);
	b_to_a(a, b, param.cnt_pb - param.cnt_rb);
}

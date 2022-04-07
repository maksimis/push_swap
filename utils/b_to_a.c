/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:01 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 11:28:01 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

static void	conquer_b(t_int_list **a, t_int_list **b, int cnt)
{
	if (cnt == 2 || cnt == 3)
	{
		if ((*b)->content < (*b)->next->content)
			sb(b);
		if (cnt == 3)
		{
			if (!is_desc(*b, cnt))
			{
				rb(b);
				sb(b);
				rrb(b);
				if ((*b)->content < (*b)->next->content)
					sb(b);
			}
			pa(a, b);
		}
		pa(a, b);
	}
	pa(a, b);
}

static void	divide_b(t_int_list **a, t_int_list **b, int cnt, t_param *param)
{
	while (cnt > 0)
	{
		if ((*b)->content >= param->pvt_greater)
		{
			pa(a, b);
			++(param->cnt_pa);
		}
		else if ((*b)->content < param->pvt_less)
		{
			rb(b);
			++(param->cnt_rb);
		}
		else
		{
			pa(a, b);
			++(param->cnt_pa);
			ra(a);
			++(param->cnt_ra);
		}
		--cnt;
	}
}

void	b_to_a(t_int_list **a, t_int_list **b, int cnt)
{
	t_param	param;

	if (cnt <= 3)
	{
		conquer_b(a, b, cnt);
		return ;
	}
	param = (t_param){0, };
	set_pvt(*b, cnt, 'b', &param);
	divide_b(a, b, cnt, &param);
	a_to_b(a, b, param.cnt_pa - param.cnt_ra);
	rewind_stack(a, b, param.cnt_ra);
	a_to_b(a, b, param.cnt_ra);
	b_to_a(a, b, param.cnt_rb);
}

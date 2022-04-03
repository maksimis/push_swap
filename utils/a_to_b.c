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

void	a_to_b(t_int_list **a, t_int_list **b, int cnt)
{
	t_info	info;
	int		*arr;

	if (break_a_to_b(a, b, cnt))
		return ;
	arr = create_arr(*a, cnt);
	info.pvt_a = get_pvt(*a, cnt, arr);
	info.cnt_ra = 0;
	info.cnt_pb = 0;
	while (cnt-- > 0)
	{
		if ((*a)->content > info.pvt_a)
		{
			ra(a);
			++(info.cnt_ra);
		}
		else
		{
			pb(a, b);
			++(info.cnt_pb);
		}
	}
	rewind_stack_a(a, info.cnt_ra);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_pb);
}

bool	break_a_to_b(t_int_list **a, t_int_list **b, int cnt)
{
	if (cnt == 1)
		return (true);
	else if (cnt == 2)
	{
		if (is_desc(*a, 2))
			reverse_a(a, b, 2);
		return (true);
	}
	return (false);
}

int	*create_arr(t_int_list *a, int cnt)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * cnt);
	if (arr == NULL)
		clear_error_and_exit(a);
	return (arr);
}

int	get_pvt(t_int_list *head, int cnt, int *arr)
{
	int	i;
	int	j;
	int	cnt_greater;

	i = 0;
	while (i < cnt)
	{
		arr[i] = head->content;
		head = head->next;
		++i;
	}
	i = -1;
	while (++i < cnt)
	{
		j = -1;
		cnt_greater = 0;
		while (++j < cnt)
		{
			if (arr[i] < arr[j])
				++cnt_greater;
		}
		if (cnt_greater == cnt / 2)
			break ;
	}
	return (free_arr_then_get_ret(arr, arr[i]));
}

int	free_arr_then_get_ret(int *arr, int ret)
{
	free(arr);
	return (ret);
}

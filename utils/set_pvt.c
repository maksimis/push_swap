/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pvt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:28:27 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:19:04 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../main.h"

static int	*init_arr(t_int_list *a, int cnt)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * cnt);
	if (arr == NULL)
		error_and_exit();
	i = 0;
	while (i < cnt)
	{
		arr[i] = a->content;
		a = a->next;
		++i;
	}
	return (arr);
}

static void	assign_pvt(int cnt, t_param *param, int *arr)
{
	int	i;
	int	j;
	int	cnt_less;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		cnt_less = 0;
		while (j < cnt)
		{
			if (arr[i] > arr[j])
				++cnt_less;
			++j;
		}
		if (cnt_less == param->idx_pvt_less)
			param->pvt_less = arr[i];
		else if (cnt_less == param->idx_pvt_greater)
			param->pvt_greater = arr[i];
		++i;
	}
}

void	set_pvt(t_int_list *a, int cnt, char flag_stack, t_param *param)
{
	int	*arr;
	int	q;

	arr = init_arr(a, cnt);
	q = cnt / 3;
	if (cnt % 3 == 2)
		++q;
	if (flag_stack == 'a')
	{
		param->idx_pvt_less = (cnt - 1) - (2 * q);
		param->idx_pvt_greater = (cnt - 1) - q;
	}
	else if (flag_stack == 'b')
	{
		param->idx_pvt_less = q;
		param->idx_pvt_greater = 2 * q;
	}
	assign_pvt(cnt, param, arr);
	free(arr);
	arr = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_with_int_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 01:19:19 by sshin             #+#    #+#             */
/*   Updated: 2021/08/18 23:35:46 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

bool	is_plusminus(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

bool	is_nbr(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

void	apply_sign(int sign, long long *res)
{
	if (sign < 0)
		*res = *res * -1;
}

int	extract_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (is_plusminus(*str))
	{
		if (*str == '-')
			sign = sign * -1;
	}
	return (sign);
}

int	atoi_with_check(const char *str)
{
	int			sign;
	long long	result;
	char		*tmp;

	tmp = (char *)str;
	sign = extract_sign(tmp);
	if (sign < 0)
		tmp++;
	result = 0;
	while (*tmp)
	{
		if (is_nbr(*tmp) && result < 2147483648)
		{
			result *= 10;
			result += (*tmp - '0');
		}
		else
			error_and_exit();
		tmp++;
	}
	apply_sign(sign, &result);
	if (result < -2147483648 || result > 2147483647)
		error_and_exit();
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:16:48 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:16:58 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

void	ft_putnbr(int a)
{
	ft_putnbr_fd(a, 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char **argv)
{
	t_int_list	*list_a;
	t_int_list	*list_b;
	int			len;

	list_a = 0;
	list_b = 0;
	if (argc == 1)
		error_and_exit();
	init_stack(&list_a, argc, argv);
	check_has_dup(list_a);
	len = i_l_size(list_a);
	if (len >= 2 && is_desc(list_a, len))
		reverse_a(&list_a, &list_b, len);
	else if (len >= 3 && !is_asc(list_a, len))
		sort(&list_a, &list_b, len);
	return (1);
}

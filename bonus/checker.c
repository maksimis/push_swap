/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:27:21 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:29:21 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./main.h"

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
	return (1);
}

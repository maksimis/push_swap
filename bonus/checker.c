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
#include "../main.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	switch_op(char *command, t_int_list **a, t_int_list **b)
{
	if (!ft_strcmp(command, "sa") && swap(a, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "sb") && swap(b, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "ss") && swap(a, NULL) && swap(b, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "pa") && push(a, b, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "pb") && push(b, a, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "ra") && rotate(a, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "rb") && rotate(b, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "rr")
		&& rotate(a, NULL) && rotate(b, NULL))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "rra") && reverse(a))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "rrb") && reverse(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else if (!ft_strcmp(command, "rrr") && reverse(a) && reverse(b))
		ft_putstr_fd("", STDOUT_FILENO);
	else
		error_and_exit();
}

static void	check(t_int_list **a, t_int_list **b, int len)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, "Error", 5) == 0)
			error_and_exit();
		switch_op(line, a, b);
		free(line);
		line = NULL;
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	line = NULL;
	if (is_asc(*a, len))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_int_list	*list_a;
	t_int_list	*list_b;
	int			len;

	list_a = 0;
	list_b = 0;
	if (argc == 1)
		exit(1);
	init_stack(&list_a, argc, argv);
	len = i_l_size(list_a);
	if (len >= 2)
		check_has_dup(list_a);
	check(&list_a, &list_a, len);
	i_l_clear(&list_a);
	i_l_clear(&list_b);
	return (1);
}

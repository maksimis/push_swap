#include "../main.h"

void	error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	check_has_dup(t_int_list *list)
{
	t_int_list *copy;

	if (list->next)
		copy = list->next;
	while (list && copy)
	{
		while (copy)
		{
			if (list->content == copy->content)
			{
				error_and_exit();
			}
			copy = copy->next;
		}
		list = list->next;
		if (list->next)
			copy = list->next;
	}
}

int	is_sorted(t_int_list *list)
{
	(void) list;
	return (1);
}
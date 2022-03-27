# include "../main.h"

void	sa(t_int_list *list)
{
	(void) list;
	ft_putendl_fd("sa", 1);
}

void	sb(t_int_list *list)
{
	(void) list;
	ft_putendl_fd("sb", 1);
}

void	ss(t_int_list *list_a, t_int_list *list_b)
{
	sa(list_a);
	sb(list_b);
}
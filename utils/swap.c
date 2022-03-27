# include "../main.h"

void	swap(t_int_list **list, char *command)
{
	t_int_list *temp1;
	t_int_list *temp2;

	if (i_l_size(*list) >= 2)
	{
		temp1 = (*list)->next->next;
		temp2 = *list;
		*list = (*list)->next;;
		(*list)->next = temp2;
		(*list)->next->next = temp1;
		ft_putendl_fd(command, 1);
	}
}

void	sa(t_int_list **list)
{
	swap(list, "sa");
}

void	sb(t_int_list **list)
{
	swap(list, "sb");
}

void	ss(t_int_list **list_a, t_int_list **list_b)
{
	sa(list_a);
	sb(list_b);
}
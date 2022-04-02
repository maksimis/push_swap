#include "../main.h"


void reverse_a(t_int_list **list_a, t_int_list **list_b, int len) {
	int		i;

	i = 0;
	if (len == 2)
		sa(list_a);
	else if (len == 3)
	{
		sa(list_a);
		rra(list_a);
	}
	else
	{
		while (i < len - 1)
		{
			pb(list_a, list_b);
			i++;
		}
		while (i > 0)
		{
			pa(list_a, list_b);
			ra(list_a);
			i--;
		}
	}
}

void sort(t_int_list **list_a, t_int_list **list_b, int len) {
	(void ) list_a;
	(void ) list_b;
	(void) len;
}
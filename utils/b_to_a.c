#include "../main.h"

void	rewind_stack_a(t_int_list **a, int cnt_ra)
{
	while (cnt_ra > 0)
	{
		rra(a);
		--cnt_ra;
	}
}

void	b_to_a(t_int_list **a, t_int_list **b, int cnt)
{
	t_info	info;

	if (break_b_to_a(a, b, cnt))
		return ;
	info.pvt_b = get_pvt(*b, cnt, create_arr(*a, cnt));
	info.cnt_pa = 0;
	info.cnt_rb = 0;
	while (cnt-- > 0)
	{
		if ((*b)->content > info.pvt_b)
		{
			pa(a, b);
			++(info.cnt_pa);
		}
		else
		{
			rb(b);
			++(info.cnt_rb);
		}
	}
	rewind_stack_b(b, info.cnt_rb);
	a_to_b(a, b, info.cnt_pa);
	b_to_a(a, b, info.cnt_rb);
}

bool	break_b_to_a(t_int_list **a, t_int_list **b, int cnt)
{
	if (cnt == 1)
	{
		pa(a, b);
		return (true);
	}
	return (false);
}

void	rewind_stack_b(t_int_list **b, int cnt_rb)
{
	while (cnt_rb > 0)
	{
		rrb(b);
		--cnt_rb;
	}
}

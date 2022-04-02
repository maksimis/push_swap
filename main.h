#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <unistd.h>
#include "libft/libft.h"

typedef struct s_int_list
{
	int					content;
	struct s_int_list	*next;
}	t_int_list;

t_int_list	*i_l_new(int content);
void		i_l_add_back(t_int_list **lst, t_int_list *new);
void		i_l_add_front(t_int_list **lst, t_int_list *new);
void		i_l_clear(t_int_list **lst);
void		i_l_delone(t_int_list *lst);
void		i_l_iter(t_int_list *lst, void (*f)(int));
t_int_list	*i_l_last(t_int_list *lst);
int			i_l_size(t_int_list *lst);
void		sa(t_int_list **list);
void		sb(t_int_list **list);
void		ss(t_int_list **list_a, t_int_list **list_b);
void 		pa(t_int_list **list_a, t_int_list **list_b);
void 		pb(t_int_list **list_a, t_int_list **list_b);
void		ra(t_int_list **list_a);
void		rb(t_int_list **list_b);
void		rr(t_int_list **list_a, t_int_list **list_b);
void		rra(t_int_list **list_a);
void		rrb(t_int_list **list_b);
void		rrr(t_int_list **list_a, t_int_list **list_b);
void		error_and_exit();
void		check_has_dup(t_int_list *list);
int			is_desc(t_int_list *list, int len);
int			is_asc(t_int_list *list, int len);
void 		init_stack(t_int_list **list, int argc, char **argv);
void 		reverse_a(t_int_list **list_a, t_int_list **list_b, int len);
void 		sort(t_int_list **list_a, t_int_list **list_b, int len);

#endif
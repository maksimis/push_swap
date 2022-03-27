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

#endif
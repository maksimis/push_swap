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
void		sa(t_int_list *list);
void		sb(t_int_list *list);
void		ss(t_int_list *list_a, t_int_list *list_b);

#endif
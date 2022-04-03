/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichael <cmichael@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:16:52 by cmichael          #+#    #+#             */
/*   Updated: 2022/04/03 12:27:32 by cmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_int_list
{
	int					content;
	struct s_int_list	*next;
}	t_int_list;

typedef struct s_info
{
	int	pvt_a;
	int	pvt_b;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_pb;
}	t_info;

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
void		pa(t_int_list **list_a, t_int_list **list_b);
void		pb(t_int_list **list_a, t_int_list **list_b);
void		ra(t_int_list **list_a);
void		rb(t_int_list **list_b);
void		rr(t_int_list **list_a, t_int_list **list_b);
void		rra(t_int_list **list_a);
void		rrb(t_int_list **list_b);
void		rrr(t_int_list **list_a, t_int_list **list_b);
void		error_and_exit(void);
void		check_has_dup(t_int_list *list);
int			is_desc(t_int_list *list, int len);
int			is_asc(t_int_list *list, int len);
void		init_stack(t_int_list **list, int argc, char **argv);
void		reverse_a(t_int_list **list_a, t_int_list **list_b, int len);
void		sort(t_int_list **list_a, t_int_list **list_b, int len);
int			get_pvt(t_int_list *head, int cnt, int *arr);
int			free_arr_then_get_ret(int *arr, int ret);
void		rewind_stack_a(t_int_list **a, int cnt_ra);
void		a_to_b(t_int_list **a, t_int_list **b, int cnt);
void		b_to_a(t_int_list **a, t_int_list **b, int cnt);
int			*create_arr(t_int_list *a, int cnt);
void		clear_error_and_exit(t_int_list *a);
bool		break_a_to_b(t_int_list **a, t_int_list **b, int cnt);
bool		break_b_to_a(t_int_list **a, t_int_list **b, int cnt);
void		rewind_stack_b(t_int_list **b, int cnt_rb);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:35:53 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:35:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define MIN(a, b) (a < b) ? a : b

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				grp;
}					t_stack;

typedef struct		s_head
{
	int				count;
	int				c;
	int				visio;
	struct s_stack	*a;
	struct s_stack	*a_last;
	struct s_stack	*b;
	struct s_stack	*b_last;
	int				grp_count;
	int				cur_grp;
	int				b_grp_size;
	int				b_top_index;
	int				b_l;
	int				width;
}					t_head;

typedef struct		s_act
{
	struct s_act	*next;
	int				code;
}					t_act;

t_head				*read_nb(int argc, char **argv, int c);
t_head				*add_list(long nb, t_head *head);
t_stack				*add_data(int nb);
int					width(t_head *head);
int					if_sort(t_stack *stack, int route);
int					ft_count(t_stack *stack);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);
int					ft_med(t_stack *stack, int min, int max);
t_stack				*sa(t_stack *stack);
t_head				*ra(t_head *head);
t_head				*rb(t_head *head);
t_head				*rra(t_head *head);
t_head				*rrb(t_head *head);
t_head				*pb(t_head *head);
t_head				*pa(t_head *head);
void				print_head(t_head *head);
int					equ(char const *s1, char const *s2);
int					sort_lite(t_head *head);
t_head				*sort_hard(t_head *head);
t_head				*q_sort(t_head *head);
int					compl(t_head *head);
t_head				*refresh(t_head *head);
t_head				*bal_sort(t_head *head);
int					position(t_stack *stack, int nb);
t_head				*algo(t_head *head);
t_head				*add_attribut(t_head *head, int ac, char **av);
void				sort(t_head *head);
void				sort_5(t_head *head);
void				sort_3(t_head *head);
int					all_grps(t_stack *a);
void				put_grp(t_head *head, int min, t_stack *a, int i);
void				put_grps(t_head *head, int grp_count);
int					find_cur_nb(t_head *head);
int					find_b_nb(t_head *head, int val);
void				do_rr(t_head *head, int b_i);
void				do_a(t_head *head);
int					get_grp_size(int count);

#endif

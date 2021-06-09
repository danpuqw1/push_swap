/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:35:14 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:35:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_b(t_head *head)
{
	if (head->b_l == 0)
	{
		head = rb(head);
		head->c ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) :
		write(1, "rb\n", 3);
		head->b_top_index++;
		if (head->visio)
			print_head(head);
	}
	else
	{
		head = rrb(head);
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) :
		write(1, "rrb\n", 4);
		head->b_top_index--;
		if (head->visio)
			print_head(head);
	}
}

void	push_b(t_head *head, int b_i)
{
	head = pb(head);
	head->c ? write(1, "\x1b[1;33mpb\x1b[0m\n", 14) :
	write(1, "pb\n", 3);
	if (head->visio)
		print_head(head);
	if (head->cur_grp == 1 && b_i > head->b_grp_size && head->b_grp_size)
	{
		head = rb(head);
		head->c ? write(1, "\x1b[1;33mrb\x1b[0m\n", 14) :
		write(1, "rb\n", 3);
		if (head->visio)
			print_head(head);
	}
}

void	do_nxt_grp(t_head *head)
{
	while (head->b_top_index != 1)
	{
		head = rrb(head);
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) :
		write(1, "rrb\n", 4);
		head->b_top_index--;
		if (head->visio)
			print_head(head);
	}
	head->cur_grp++;
	head->b_grp_size = 0;
}

void	return_a_and_b(t_head *head)
{
	while (head->b_top_index != 1)
	{
		head = rrb(head);
		head->c ? write(1, "\x1b[1;33mrrb\x1b[0m\n", 15) :
		write(1, "rrb\n", 4);
		head->b_top_index--;
		if (head->visio)
			print_head(head);
	}
	while (head->b)
	{
		head = pa(head);
		head->c ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) :
		write(1, "pa\n", 3);
		if (head->visio)
			print_head(head);
	}
}

void	sort(t_head *head)
{
	int		val;
	int		b_i;
	int		grp_size;

	grp_size = get_grp_size(head->count);
	put_grps(head, grp_size);
	head->cur_grp = 1;
	head->b_grp_size = 0;
	while (ft_count(head->a) > 0)
	{
		val = find_cur_nb(head);
		b_i = find_b_nb(head, val);
		if (head->b_l == 0)
			do_rr(head, b_i);
		while (head->a->grp != head->cur_grp)
			do_a(head);
		while (head->b_top_index != b_i && !(head->cur_grp == 1 && b_i
		> head->b_grp_size))
			do_b(head);
		push_b(head, b_i);
		head->b_grp_size++;
		if (head->b_grp_size == grp_size)
			do_nxt_grp(head);
	}
	return_a_and_b(head);
}

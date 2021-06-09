/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:01:34 by student           #+#    #+#             */
/*   Updated: 2020/08/08 20:01:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_3(t_head *head, int max)
{
	if ((head->a->val > head->a->next->val && !(head->a->val == max &&
		head->a_last->val > head->a->next->val)) || (head->a->next->val
		== max && head->a->val < head->a_last->val))
	{
		head->a = sa(head->a);
		head->c ? write(1, "\x1b[1;33msa\x1b[0m\n", 14) : write(1, "sa\n", 3);
		if (head->visio)
			print_head(head);
	}
}

void	second_3(t_head *head, int max)
{
	if (head->a->next->val == max)
	{
		head = rra(head);
		head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) :
		write(1, "rra\n", 4);
		if (head->visio)
			print_head(head);
	}
	else
	{
		head = ra(head);
		head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 15) :
		write(1, "ra\n", 4);
		if (head->visio)
			print_head(head);
	}
}

void	sort_3(t_head *head)
{
	int		max;

	max = ft_max(head->a);
	if (head->count == 2)
	{
		if (head->a->val > head->a->next->val)
		{
			head->a = sa(head->a);
			head->c ? write(1, "\x1b[1;33msa\x1b[0m\n", 14)
			: write(1, "sa\n", 3);
			if (head->visio)
				print_head(head);
		}
		return ;
	}
	first_3(head, max);
	if (if_sort(head->a, 1))
		return ;
	second_3(head, max);
}

void	top_b_min(t_head *head, int min)
{
	if (head->a_last->val == min || head->a_last->prev->val == min)
	{
		while (head->a->val != min)
		{
			head = rra(head);
			head->c ? write(1, "\x1b[1;33mrra\x1b[0m\n", 15) :
			write(1, "rra\n", 4);
			if (head->visio)
				print_head(head);
		}
	}
	else
	{
		while (head->a->val != min)
		{
			head = ra(head);
			head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 15) :
			write(1, "ra\n", 4);
			if (head->visio)
				print_head(head);
		}
	}
}

void	sort_5(t_head *head)
{
	int		min;
	int		i;

	i = 0;
	while (i++ < 2)
	{
		min = ft_min(head->a);
		top_b_min(head, min);
		head = pb(head);
		head->c ? write(1, "\x1b[1;33mpb\x1b[0m\n", 14) :
		write(1, "pb\n", 3);
		if (head->visio)
			print_head(head);
	}
	sort_3(head);
	i = 0;
	while (i < 2)
	{
		head = pa(head);
		head->c ? write(1, "\x1b[1;33mpa\x1b[0m\n", 14) :
		write(1, "pa\n", 3);
		if (head->visio)
			print_head(head);
		i++;
	}
}

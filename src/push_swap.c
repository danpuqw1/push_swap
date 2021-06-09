/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:35:46 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:35:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_grp_size(int count)
{
	if (count < 20)
		return (20);
	if (count < 50)
		return (10);
	if (count < 120)
		return (20);
	if (count < 200)
		return (30);
	if (count < 300)
		return (40);
	if (count < 600)
		return (47);
	return (60);
}

void	do_rr(t_head *head, int b_i)
{
	while (head->a->grp != head->cur_grp && head->b_top_index != b_i &&
	!(head->cur_grp == 1 && b_i > head->b_grp_size))
	{
		head = rb(ra(head));
		head->c ? write(1, "\x1b[1;33mrr\x1b[0m\n", 14) :
		write(1, "rr\n", 3);
		head->b_top_index++;
		if (head->visio)
			print_head(head);
	}
}

void	do_a(t_head *head)
{
	head = ra(head);
	head->c ? write(1, "\x1b[1;33mra\x1b[0m\n", 14) :
	write(1, "ra\n", 3);
	if (head->visio)
		print_head(head);
}

int		position(t_stack *stack, int nb)
{
	t_stack		*tmp;
	int			i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->val == nb)
			break ;
		else
			tmp = tmp->next;
		i++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	t_head		*head;
	t_stack		*nxt;

	head = NULL;
	head = add_attribut(head, ac, av);
	if (if_sort(head->a, 1))
		exit(0);
	if (head->count <= 3)
		sort_3(head);
	if (if_sort(head->a, 1))
		exit(0);
	if (head->count <= 5)
		sort_5(head);
	if (if_sort(head->a, 1))
		exit(0);
	sort(head);
	while (head->a)
	{
		nxt = head->a->next;
		free(head->a);
		head->a = nxt;
	}
	free(head);
	exit(0);
}

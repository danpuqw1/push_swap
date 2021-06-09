/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:34:21 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:34:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*sa(t_stack *stack)
{
	int		tmp;

	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	return (stack);
}

t_head		*ra(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a->next;
	head->a->next->prev = NULL;
	head->a->next = NULL;
	head->a_last->next = head->a;
	head->a->prev = head->a_last;
	head->a_last = head->a;
	head->a = tmp;
	return (head);
}

t_head		*rb(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b->next;
	head->b->next->prev = NULL;
	head->b->next = NULL;
	head->b_last->next = head->b;
	head->b->prev = head->b_last;
	head->b_last = head->b;
	head->b = tmp;
	return (head);
}

t_head		*rra(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a_last;
	head->a_last->prev->next = NULL;
	head->a_last = head->a_last->prev;
	head->a->prev = tmp;
	tmp->next = head->a;
	head->a = tmp;
	return (head);
}

t_head		*rrb(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b_last;
	head->b_last->prev->next = NULL;
	head->b_last = head->b_last->prev;
	head->b->prev = tmp;
	tmp->next = head->b;
	head->b = tmp;
	return (head);
}

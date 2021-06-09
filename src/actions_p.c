/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:34:31 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:34:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head		*pa(t_head *head)
{
	t_stack	*tmp;

	tmp = head->b;
	if (head->b->next)
		head->b->next->prev = NULL;
	head->b = head->b->next;
	if (head->a == NULL)
		head->a_last = tmp;
	else
		head->a->prev = tmp;
	tmp->next = head->a;
	head->a = tmp;
	return (head);
}

t_head		*pb(t_head *head)
{
	t_stack	*tmp;

	tmp = head->a;
	if (head->a->next)
		head->a->next->prev = NULL;
	head->a = head->a->next;
	if (head->b == NULL)
		head->b_last = tmp;
	else
		head->b->prev = tmp;
	tmp->next = head->b;
	head->b = tmp;
	return (head);
}

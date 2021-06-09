/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:01:45 by student           #+#    #+#             */
/*   Updated: 2020/08/08 20:01:47 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		all_grps(t_stack *a)
{
	t_stack *cur;

	cur = a;
	while (cur)
	{
		if (cur->grp == 0)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	put_grp(t_head *head, int min, t_stack *a, int i)
{
	a = head->a;
	min = INT_MAX;
	while (a)
	{
		if (a->grp == 0 && a->val < min)
			min = a->val;
		a = a->next;
	}
	a = head->a;
	while (a)
	{
		if (a->val == min)
			a->grp = i;
		a = a->next;
	}
}

void	put_grps(t_head *head, int grp_count)
{
	int		i;
	int		j;
	t_stack	*a;
	int		min;

	i = 1;
	j = 0;
	min = INT_MAX;
	a = head->a;
	while (all_grps(head->a))
	{
		put_grp(head, min, a, i);
		j++;
		if (j == grp_count)
		{
			j = 0;
			i++;
		}
	}
}

int		find_cur_nb(t_head *head)
{
	int		min_v;
	t_stack	*a;
	int		i;
	int		ret;
	int		count;

	min_v = head->count;
	a = head->a;
	i = 0;
	ret = 0;
	count = ft_count(head->a);
	while (a)
	{
		if (a->grp == head->cur_grp)
		{
			if (min_v > (MIN(i, count - i + 1)))
			{
				min_v = MIN(i, count - i + 1);
				ret = a->val;
			}
		}
		a = a->next;
		i++;
	}
	return (ret);
}

int		find_b_nb(t_head *head, int val)
{
	int		i;
	t_stack	*b;

	i = head->b_top_index;
	if (head->b_grp_size == 0)
		return (1);
	if (val < head->b->val)
	{
		b = head->b;
		while (b && val < b->val && ++i)
			b = b->next;
		head->b_l = 0;
	}
	else
	{
		b = head->b_last;
		while (b && val > b->val && i > 1)
		{
			i--;
			b = b->prev;
		}
		head->b_l = 1;
	}
	return (i);
}

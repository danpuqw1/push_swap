/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:36:08 by student           #+#    #+#             */
/*   Updated: 2020/07/25 12:36:12 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		equ(char const *s1, char const *s2)
{
	while (s1 && s2 && *s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

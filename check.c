/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:09:55 by mwen              #+#    #+#             */
/*   Updated: 2021/07/30 15:31:25 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stack *a, long int num, int alen)
{
	while (alen--)
	{
		if (num == a->content)
			error(a, alen);
		a = a->next;
	}
}

void	check_numeric(t_stack *a, char *input, int alen)
{
	int	i;

	i = -1;
	while(input[++i])
	{
		if (input[i] == '-' || input[i] == '+' || input[i] == ' ')
		{
			if (!input[i + 1])
				error(a, alen);
			else
				++i;
		}
		if (input[i] < '0' || input[i] > '9')
			error(a, alen);
	}
}

void	check_maxint(t_stack *a, long int num, int alen)
{
	if (num > 2147483647 || num < -2147483648)
		error(a, alen);
}

int	check_sorted(t_stack *a, int alen)
{
	t_stack *new;
	t_stack *old;
	int		sorted;

	new = NULL;
	old = NULL;
	sorted = 1;
	if (alen > 0)
	{
		new = a->prev;
		old = new->prev;
		if (new->content <= old->content)
		{
			sorted = 0;
		}
	}
	return (sorted);
}

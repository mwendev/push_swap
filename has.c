/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:59 by mwen              #+#    #+#             */
/*   Updated: 2021/08/27 17:22:10 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_to_push(t_stack *target, long int num, int len)
{
	int	has_to_push;

	if (!target)
		return (-1);
	has_to_push = 0;
	if ((target->stack == 'a' && target->sub_cont < num) ||
		(target->stack == 'b' && target->sub_cont > num))
		return (1);
	else if ((target->stack == 'a' && target->next->sub_cont < num) ||
			(target->stack == 'b' && target->next->sub_cont > num))
		return (2);
	else
	{
		while (len--)
		{
			if ((target->stack == 'a' && target->sub_cont < num) ||
				(target->stack == 'b' && target->sub_cont > num))
				has_to_push = 3;
			target = target->next;
		}
		target = target->next;
		return (has_to_push);
	}
}

int	has_to_sort(t_stack *stack)
{
	int	to_sort;
	int	len;

	to_sort = 0;
	len = get_len(stack);
	while (stack->content < stack->next->content)
	{
		to_sort++;
		stack = stack->next;
	}
	stack = stack->next;
	if (to_sort == (get_len(stack) - 1))
		return (0);
	else
		return (1);
}
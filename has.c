/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:03:59 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 00:28:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_to_push(t_stack *stack, long int num, int larger)
{
	int	len;
	int	has_to_push;

	if (!stack)
		return (-1);
	len = get_len(stack);
	has_to_push = 0;
	while (len--)
	{
		if (larger == 1)
		{
			if (stack->sub_cont > num)
				has_to_push = 1;
		}
		else
		{
			if (stack->sub_cont < num)
				has_to_push = 1;
		}
		stack = stack->next;
	}
	stack = stack->next;
	return (has_to_push);
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
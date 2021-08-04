/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:58:38 by mwen              #+#    #+#             */
/*   Updated: 2021/08/02 15:50:56 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char c)
{
	*stack = (*stack)->next;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, 'n');
	rotate(b, 'n');
	ft_putstr_fd("rr\n", 1);
}

void	rrotate(t_stack **stack, char c)
{
	*stack = (*stack)->prev;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rrotate_both(t_stack **a, t_stack **b)
{
	rrotate(a, 'n');
	rrotate(b, 'n');
	ft_putstr_fd("rrr\n", 1);
}

void	rotate_multiple(t_stack **stack, char c, char *func, int times)
{
	while (times--)
	{
		if (ft_strncmp(func, "rr", 2) == 0)
			rrotate(stack, c);
		else if (ft_strncmp(func, "r", 1) == 0)
			rotate(stack, c);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:56:30 by mwen              #+#    #+#             */
/*   Updated: 2021/08/04 13:38:25 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack		*next;
	long int	temp;
	long int	sub_temp;

	next = (*stack)->next;
	temp = (*stack)->content;
	sub_temp = (*stack)->sub_cont;
	(*stack)->content = next->content;
	(*stack)->sub_cont = next->sub_cont;
	next->content = temp;
	next->sub_cont = sub_temp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, 'n');
	swap(b, 'n');
	ft_putstr_fd("ss\n", 1);
}

void	swap_multiple(t_stack **a, t_stack **b, char *func, int times)
{
	while (times--)
	{
		if (ft_strncmp(func, "sa", 2) == 0)
		{
			if (*a && *b && (*b)->content < (*b)->next->content)
				swap_both(a, b);
			else
				swap(a, 'a');
		}
		if (ft_strncmp(func, "sb", 2) == 0)
		{
			if (*a && *b && (*a)->content > (*a)->next->content)
				swap_both(a, b);
			else
				swap(b, 'b');
		}
	}
}
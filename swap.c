/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:56:30 by mwen              #+#    #+#             */
/*   Updated: 2021/08/27 12:33:28 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **target, char print)
{
	t_stack		*next;
	long int	temp;
	long int	sub_temp;

	next = (*target)->next;
	temp = (*target)->content;
	sub_temp = (*target)->sub_cont;
	(*target)->content = next->content;
	(*target)->sub_cont = next->sub_cont;
	next->content = temp;
	next->sub_cont = sub_temp;
	if (print != 'n')
	{
		if ((*target)->stack == 'a')
			ft_putstr_fd("sa\n", 1);
		else if ((*target)->stack == 'b')
			ft_putstr_fd("sb\n", 1);
	}
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
				swap(a, 'y');
		}
		if (ft_strncmp(func, "sb", 2) == 0)
		{
			if (*a && *b && (*a)->content > (*a)->next->content)
				swap_both(a, b);
			else
				swap(b, 'y');
		}
	}
}
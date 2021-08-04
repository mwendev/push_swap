/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:32:15 by mwen              #+#    #+#             */
/*   Updated: 2021/08/03 17:13:39 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		*b = stacknew((*a)->content, (*a)->sub_cont);
	else
		*b = stackadd(*b, (*a)->content, (*a)->sub_cont, 1);
	stackdel(a);
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_stack **a, t_stack **b)
{
	*a = stackadd(*a, (*b)->content, (*b)->sub_cont, 1);
	stackdel(b);
	ft_putstr_fd("pa\n", 1);
}

void	push_multiple(t_stack **a, t_stack **b, char *func, int times)
{
	while (times--)
	{
		if (ft_strncmp(func, "pa", 2) == 0)
			push_a(a, b);
		else
			push_b(a, b);
	}
}

int	push_less_med(t_stack **stack_one, t_stack **stack_two, long int med)
{
	int			len_one;
	int			len_two;

	len_one = get_len(*stack_one);
	len_two = 0;
	if (len_one % 2 == 0)
		med++;
	while (len_two != len_one / 2)
	{
		if ((*stack_one)->sub_cont < med)
		{
			push_b(stack_one, stack_two);
			len_two++;
		}
		else
			rotate(stack_one, 'a');
	}
	return (len_two);
}

int	push_more_med(t_stack **stack_one, t_stack **stack_two, long int pushed)
{
	long int	med;
	int			len_two;
	int			times;

	med = get_median(*stack_one, pushed);
	len_two = 0;
	times = 0;
	while (len_two != pushed / 2)
	{
		if ((*stack_one)->sub_cont > med)
		{
			push_a(stack_two, stack_one);
			len_two++;
		}
		else
		{
			rotate(stack_one, 'b');
			times++;
		}
	}
	rotate_multiple(stack_one, 'b', "rr", times);
	return (len_two);
}

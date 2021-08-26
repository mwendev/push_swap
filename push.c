/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:32:15 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 12:57:59 by mwen             ###   ########.fr       */
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

int	push_smaller_than(t_stack **a, t_stack **b, long int num, int rr)
{
	int	pushed;
	int	times;

	pushed = 0;
	times = 0;
	while (has_to_push(*a, num, 0) == 1)
	{
		if ((*a)->sub_cont < num)
		{
			push_b(a, b);
			pushed++;
		}
		else
		{
			rotate(a, 'a');
			times++;
		}
	}
	if (rr == 1 &&  get_len(*a) > 3)// get_len(*a) > 5 can reduce 1 5 2 4 3 but make 8 broken
		rotate_multiple(a, 'a', "rr", times);
	// printf("PUSH SMALL\n");
	return (pushed);
}

// int	push_smaller_than(t_stack **stack_one, t_stack **stack_two, long int med)
// {
// 	int			len;
// 	int			pushed;

// 	len = get_len(*stack_one);
// 	pushed = 0;
// 	if (len % 2 == 0)
// 		med++;
// 	while (pushed != len / 2)
// 	{
// 		if ((*stack_one)->sub_cont < med)
// 		{
// 			push_b(stack_one, stack_two);
// 			pushed++;
// 		}
// 		else
// 			rotate(stack_one, 'a');
// 	}
// 	return (pushed);
// }

int	push_larger_than(t_stack **b, t_stack **a, long int num)
{
	int	pushed;
	int	times;

	pushed = 0;
	times = 0;
	while (has_to_push(*b, num, 1) == 1)
	{
		if ((*b)->sub_cont > num)
		{
			push_a(a, b);
			pushed++;
		}
		else
		{
			rotate(b, 'b');
			times++;
		}
	}
	if (get_len(*b) > 5)
		rotate_multiple(b, 'b', "rr", times);
	// printf("PUSH LARGE\n");
	return (pushed);
}

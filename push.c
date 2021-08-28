/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:32:15 by mwen              #+#    #+#             */
/*   Updated: 2021/08/27 17:42:23 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	if (*to == NULL)
		*to = stacknew((*from)->content, (*from)->sub_cont);
	else
		*to = stackadd(*to, (*from)->content, (*from)->sub_cont, 1);
	if ((*from)->stack == 'a')
		(*to)->stack = 'b';
	else if ((*from)->stack == 'b')
		(*to)->stack = 'a';
	stackdel(from);
	if ((*to)->stack == 'a')
		ft_putstr_fd("pa\n", 1);
	else if ((*to)->stack == 'b')
		ft_putstr_fd("pb\n", 1);
}

// void	push_a(t_stack **a, t_stack **b)
// {
// 	*a = stackadd(*a, (*b)->content, (*b)->sub_cont, 1);
// 	stackdel(b);
// 	ft_putstr_fd("pa\n", 1);
// }

void	push_multiple(t_stack **from, t_stack **to, int times)
{
	while (times--)
		push(from, to);
}

int	push_break(t_stack **from, t_stack **to, long int num, int rr)
{
	int	pushed;
	int	times;

	pushed = 0;
	times = 0;
	while (has_to_push(*from, num, get_len(*from)) != 0)
	{
		if (has_to_push(*from, num, get_len(*from)) == 1)
		{
			push(from, to);
			pushed++;
		}
		// else if (has_to_push(*from, num, get_len(*from)) == 2)//test if help for sort100
		// 	sort_two(from, to);
		else
		{
			rotate(from, 'y');
			times++;
		}
	}
	if (((*from)->stack == 'a' && rr == 1 && get_len(*from) > 3) ||
		((*from)->stack == 'b' && get_len(*from) > 5))
		rotate_multiple(from, "rr", times);
	// printf("PUSH SMALL\n");
	return (pushed);
}

// int	push_larger_than(t_stack **b, t_stack **a, long int num)
// {
// 	int	pushed;
// 	int	times;

// 	pushed = 0;
// 	times = 0;
// 	while (has_to_push(*b, num, 1) == 1)
// 	{
// 		if ((*b)->sub_cont > num)
// 		{
// 			push_a(a, b);
// 			pushed++;
// 		}
// 		else
// 		{
// 			rotate(b, 'b');
// 			times++;
// 		}
// 	}
// 	if (get_len(*b) > 5)
// 		rotate_multiple(b, 'b', "rr", times);
// 	// printf("PUSH LARGE\n");
// 	return (pushed);
// }

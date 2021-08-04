/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:33:30 by mwen              #+#    #+#             */
/*   Updated: 2021/08/04 12:16:53 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_one, t_stack **stack_two, char c)
{
	if ((*stack_one)->content > (*stack_one)->next->content)
	{
		if (*stack_two && (*stack_two)->content > (*stack_two)->next->content)
			swap_both(stack_one, stack_two);
		else
			swap(stack_one, c);
	}
}

void	sort_three(t_stack **stack_one, t_stack **stack_two, char d)
{
	long int	a;
	long int	b;
	long int	c;

	a = (*stack_one)->content;
	b = (*stack_one)->next->content;
	c = (*stack_one)->next->next->content;
	if (b > a && b > c && c > a)//132
	{
		if (*stack_two && (*stack_two)->content < (*stack_two)->next->content)
			swap_both(stack_one, stack_two);
		else
			swap(stack_one, d);
		rotate(stack_one, d);
	}
	if (b > a && b > c && a > c)//231
		rrotate(stack_one, d);
	if (c > a && c > b && a > b)
	{
		if (*stack_two && (*stack_two)->content < (*stack_two)->next->content)
			swap_both(stack_one, stack_two);
		else
		swap(stack_one, d);
	}
	if (a > b && a > c && c > b)
		rotate(stack_one, d);
	if (a > b && a > c && b > c)
	{
		if (*stack_two && (*stack_two)->content < (*stack_two)->next->content)
			swap_both(stack_one, stack_two);
		else
			swap(stack_one, d);
		rrotate(stack_one, d);
	}
}

void	sort_five(t_stack **a, t_stack **b) // add rule to check 4 already sorted
{
	int			len;
	long int	med;

	len = get_len(*a);
	med = get_median(*a, 0);
	push_less_med(a, b, med);
	if (get_len(*a) == 2)
		sort_two(a, b, 'a');
	else
		sort_three(a, b, 'a');
	while (get_len(*a) != len)
		push_a(a, b);
	sort_two(a, b, 'a');
}

void	sort_ten(t_stack **a, t_stack **b)
{
	int			len;
	long int	med;
	int			pushed;
	
	len = get_len(*a);
	med = get_median(*a, 0);
	pushed = push_less_med(a, b, med);
	sort_five(a, b);
	push_more_med(b, a, pushed);
	sort_two(a, b, 'a');
	while (get_len(*a) != len)
	{
		if ((*b)->content < (*b)->next->content)
			swap(b, 'b');
		push_a(a, b);
		sort_two(a, b, 'a');
	}
}

void	sort_hundred(t_stack **a, t_stack **b)
{
	long int	med;
	int			alen;

	while (get_len(*a) > 10)
	{
		med = get_median(*a, 0);
		push_less_med(a, b, med);
	}
	sort_ten(a, b);
	alen = get_len(*a);
	push_more_med(b, a, alen);
	
}

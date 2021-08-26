/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:33:30 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 16:28:29 by mwen             ###   ########.fr       */
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

void	sort_three(t_stack **stack_one, t_stack **stack_two, char c)
{
	sort_two(stack_one, stack_two, c);
	if (has_to_sort(*stack_one) == 1)
	{
		if (get_len(*stack_one) == 3)
			rrotate(stack_one, c);
		else
		{
			rotate(stack_one, c);
			sort_two(stack_one, stack_two, c);
			rrotate(stack_one, c);
		}
	}
	if (has_to_sort(*stack_one) == 1)
		sort_two(stack_one, stack_two, c);
}

void	sort_five(t_stack **stack_one, t_stack **stack_two, int sort_len)
{
	long int	med;
	int			pushed;
	int			len;

	len = get_len(*stack_one);
	if (len == 3)
	{
		sort_three(stack_one, stack_two, 'a');
		return ;
	}
	med = get_median(*stack_one, sort_len);
	pushed = push_smaller_than(stack_one, stack_two, med, 1);
	sort_three(stack_one, stack_two, 'a');
	while (pushed--)
		push_a(stack_one, stack_two);
	sort_two(stack_one, stack_two, 'a');
	// printf("SORT FIVE\n");
}

void	sort_ten(t_stack **a, t_stack **b)
{
	long int	med;
	int			pushed_smaller;
	int			pushed_larger;
	int			len;
	int			counter;

	len = get_len(*a);
	if (len > 10)
		len = 10;
	med = get_median(*a, len);
	pushed_smaller = push_smaller_than(a, b, med, 1);
	sort_five(a, b, len - pushed_smaller);
	med = get_median(*b, pushed_smaller);
	pushed_larger = push_larger_than(b, a, med);
	counter = pushed_smaller - pushed_larger;
	sort_three(a, b, 'a');
	while (counter-- && get_len(*b) != 0)
	{
		if ((*b)->content < (*b)->next->content)
			swap(b, 'b');
		push_a(a, b);
		sort_two(a, b, 'a');
	}
	// printf("SORT TEN\n");
}

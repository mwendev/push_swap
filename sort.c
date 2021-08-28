/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:33:30 by mwen              #+#    #+#             */
/*   Updated: 2021/08/28 19:23:37 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_stack **b)
{
	long int	first;
	long int	sec;

	first = (*a)->content;
	sec = (*a)->next->content;
	if (((*a)->stack == 'a' && first > sec) ||
		((*a)->stack == 'b' && first < sec))
	{
		if (*a && *b && 
			(((*a)->stack == 'a' && (*b)->content < (*b)->next->content) ||
			((*a)->stack == 'b' && (*b)->content > (*b)->next->content)))
			swap_both(a, b);//try without when sorting 100
		else
			swap(a, 'y');
	}
}

void	sort_three(t_stack **a, t_stack **b)
{
	sort_two(a, b);
	if (has_to_sort(*a) != 0)
	{
		if (get_len(*a) == 3)
			rrotate(a, 'y');
		else
		{
			rotate(a, 'y');
			sort_two(a, b);
			rrotate(a, 'y');
		}
	}
	if (has_to_sort(*a) != 0)
		sort_two(a, b);
}

void	sort_five(t_stack **a, t_stack **b, int sort_len)//max 7
{
	int	pushed;

	if (sort_len == 3)
	{
		sort_three(a, b);
		return ;
	}
	pushed = push_break(a, b, get_median(*a, sort_len), 1);
	if (sort_len - pushed == 4)
	{
		push_break(a, b, get_median(*a, sort_len - pushed), 1);
		sort_two(a, b);
		push(b, a);
		push(b, a);
	}
	sort_three(a, b);
	while (pushed--)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
	// printf("SORT FIVE\n");
}

void	sort_ten(t_stack **a, t_stack **b, int sort_len)//max 12
{
	int	pushed_to_b;
	int	pushed_to_a;
	int	still_in_b;

	if (sort_len <= 7)
	{
		sort_five(a, b, sort_len);
		return ;
	}
	pushed_to_b = push_break(a, b, get_median(*a, sort_len), 1);
	sort_five(a, b, sort_len - pushed_to_b);
	pushed_to_a = push_break(b, a, get_median(*b, pushed_to_b), 1);
	still_in_b = pushed_to_b - pushed_to_a;
	sort_three(a, b);
	while (still_in_b-- && *b)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
	// printf("SORT TEN\n");
}

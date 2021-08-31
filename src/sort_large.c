/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:31:58 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 14:39:49 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_back(t_stack **b, t_stack **a, int sort_len)
{
	int	to_sort;

	while (sort_len > 3)
	{
		if (sort_len <= 14)
			to_sort = push_break(b, a, get_median(*b, sort_len), 1);
		else
			to_sort = push_break(b, a, get_maxnum(*b) - 12, 1);
		sort_ten(a, b, to_sort);
		sort_len -= to_sort;
	}
	while (sort_len--)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
}

void	sort_hundred(t_stack **a, t_stack **b, int sort_len, int total_len)
{
	int	pushed;

	if (has_to_sort(*a) != 0 && sort_len <= 14)
		sort_ten(a, b, sort_len);
	else
	{
		pushed = push_break(a, b, get_median(*a, sort_len), 0);
		sort_hundred(a, b, sort_len - pushed, sort_len);
	}
	if (total_len - sort_len != 0)
		sort_back(b, a, total_len - sort_len);
}

void	sort_back_big(t_stack **b, t_stack **a, int sort_len)
{
	int	to_sort;

	while (sort_len > 3)
	{
		if (sort_len <= 14)
			to_sort = push_break(b, a, get_median(*b, sort_len), 1);
		else if (sort_len <= 50)
			to_sort = push_break(b, a, get_maxnum(*b) - 12, 1);
		else
			to_sort = push_break(b, a, get_maxnum(*b) - 50, 1);
		sort_fiftysix(a, b, to_sort);
		sort_len -= to_sort;
	}
	while (sort_len--)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
}

void	sort_fivehundred(t_stack **a, t_stack **b, int sort_len, int total_len)
{
	int	pushed;

	if (has_to_sort(*a) != 0 && sort_len <= 130)
		sort_hundred(a, b, sort_len, sort_len);
	else
	{
		pushed = push_break(a, b, get_median(*a, sort_len), 0);
		sort_fivehundred(a, b, sort_len - pushed, sort_len);
	}
	if (total_len - sort_len != 0)
		sort_back_big(b, a, total_len - sort_len);
}

void	sort(t_stack **a, t_stack **b, int sort_len, int total_len)
{
	int	pushed;

	if (has_to_sort(*a) != 0 && sort_len <= 56)
		sort_fiftysix(a, b, sort_len);
	else
	{
		pushed = push_break(a, b, get_median(*a, sort_len), 0);
		sort(a, b, sort_len - pushed, sort_len);
	}
	if (total_len - sort_len != 0)
		sort_back(b, a, total_len - sort_len);
	if (has_to_sort(*a) != 0)
		sort_ten(a, b, 10);
}

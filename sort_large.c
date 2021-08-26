/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:31:58 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 16:29:36 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_twentyfive(t_stack **a, t_stack **b, int sort_len, int origin_len)
{
	if (has_to_sort(*a) == 1 && sort_len <= 5)
		sort_five(a, b, sort_len);
	else if (has_to_sort(*a) == 1 && sort_len <= 10)
		sort_ten(a, b);
	else if (sort_len > 10)
	{
		push_smaller_than(a, b, get_minsubcont(*a) + 10, 0);
		sort_twentyfive(a, b, get_len(*a), origin_len);
	}
	if (get_len(*a) != origin_len)
	{
		sort_len = push_larger_than(b, a, get_maxnum(*b) - 10);
		if (has_to_sort(*a) == 1)
			sort_ten(a, b);
	}
}

void	sort_fifty(t_stack **a, t_stack **b, int sort_len, int origin_len)
{
	int	len;

	if (has_to_sort(*a) == 1 && sort_len <= 25)
		sort_twentyfive(a, b, sort_len, sort_len);
	else
	{
		sort_len = push_smaller_than(a, b, get_median(*a, sort_len), 0);
		sort_fifty(a, b, sort_len, origin_len);
	}
	len = get_len(*a);
	if (len != origin_len)
	{
		while (len-- && get_len(*b) > 0)
			push_a(a, b);
		if (has_to_sort(*a) == 1)
			sort_twentyfive(a, b, sort_len, get_len(*a));
	}
}

void	sort_hundred(t_stack **a, t_stack **b, int sort_len, int origin_len)
{
	int	len;

	if (has_to_sort(*a) == 1 && sort_len <= 50)
		sort_fifty(a, b, sort_len, get_len(*a));
	else
	{
		push_smaller_than(a, b, get_median(*a, sort_len), 0);
		sort_hundred(a, b, get_len(*a), origin_len);
	}
	len = get_len(*a);
	if (len != origin_len)
	{
		while (len-- && get_len(*b) > 0)
			push_a(a, b);
		if (has_to_sort(*a) == 1)
			sort_fifty(a, b, sort_len, get_len(*a));
	}
}
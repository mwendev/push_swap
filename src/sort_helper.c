/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:37:56 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 14:50:48 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_twentyeight(t_stack **a, t_stack **b, int sort_len)
{
	int	pushed;

	if (sort_len <= 14)
	{
		sort_ten(a, b, sort_len);
		return ;
	}
	pushed = push_break(a, b, get_median(*a, sort_len), 1);
	sort_ten(a, b, sort_len - pushed);
	while (pushed > 3)
	{
		sort_len = push_break(b, a, get_median(*b, pushed), 1);
		sort_five(a, b, sort_len);
		pushed -= sort_len;
	}
	while (pushed--)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
}

void	sort_fiftysix(t_stack **a, t_stack **b, int sort_len)
{
	int	pushed;

	if (sort_len <= 28)
	{
		sort_twentyeight(a, b, sort_len);
		return ;
	}
	pushed = push_break(a, b, get_median(*a, sort_len), 1);
	sort_twentyeight(a, b, sort_len - pushed);
	while (pushed > 3)
	{
		sort_len = push_break(b, a, get_median(*b, pushed), 1);
		sort_ten(a, b, sort_len);
		pushed -= sort_len;
	}
	while (pushed--)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
}

long int	forcast_med(t_stack **from, long int num, int sort_len)
{
	long int	fmed;
	int			len;

	fmed = 0;
	len = 0;
	if (has_to_push(*from, num, get_len(*from)) != 0)
		return (-1);
	while (sort_len--)
	{
		if (has_to_push(*from, num, get_len(*from) == 1))
		{
			fmed += (*from)->sub_cont;
			len++;
		}
		*from = (*from)->next;
	}
	fmed /= len;
	return (fmed);
}

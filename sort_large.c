/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:31:58 by mwen              #+#    #+#             */
/*   Updated: 2021/08/29 00:16:45 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_back(t_stack **b, t_stack **a, int sort_len)
{
	int	to_sort;
	int	still_in_b;

	// printf("sort %d med %ld blen %d\n", sort_len, get_median(*b, sort_len), get_len(*b));
	to_sort = push_break(b, a, get_median(*b, sort_len), 1);
	// printf("tosort %d\n", to_sort);
	if (to_sort <= 13)
		sort_ten(a, b, to_sort);
	// still_in_b = total_len - to_sort;//A6 B31 || A3 B27
	still_in_b = sort_len - to_sort;//A6 B6 || A3done B3go back
	// printf("still in b %d\n", still_in_b);
	if (still_in_b > 3)
	{
		sort_back(b, a, still_in_b);
		return ;
	}
	while (still_in_b-- && *b)
	{
		sort_two(b, a);
		push(b, a);
		sort_two(a, b);
	}
	// for (int i = 0; i < 25; i++)
	// {
	// 	// printf("cont is %ld sub is %ld\n", a->content, a->sub_cont);
	// 	printf("cont: %ld sub: %ld %c	cont: %ld sub: %ld %c\n", (*a)->content, (*a)->sub_cont, (*a)->stack, (*b)->content, (*b)->sub_cont, (*b)->stack);
	// 	*a = (*a)->next;
	// 	*b = (*b)->next;
	// }
	// exit (1);
}

void	sort_fifty(t_stack **a, t_stack **b, int sort_len, int total_len)
{
	int	pushed;

	// printf("sort_len %d  total %d\n", sort_len, total_len);
	if (has_to_sort(*a) != 0 && sort_len <= 13)
		sort_ten(a, b, sort_len);
	else
	{
		pushed = push_break(a, b, get_median(*a, sort_len), 0);
		if (sort_len % 2 != 0)
			pushed++;
		sort_fifty(a, b, pushed, total_len);
	}
	if (total_len - sort_len != 0)
	{
		if (sort_len == 13)
			sort_len--;
		sort_back(b, a, sort_len);
	}
}

void	sort_back_hundred(t_stack **b, t_stack **a, int sort_len)
{
	int	times;

	times = 0;
	while (sort_len > 13)
	{
		push_break(b, a, get_maxnum(*b) - 13, 1);
		sort_ten(a, b, 13);
		sort_len -= 13;
	}
	while (sort_len-- && *b)
		push(b, a);
	sort_ten(a, b, 11);
}

void	sort_hundred(t_stack **a, t_stack **b, int sort_len, int total_len)
{
	int	pushed;

	if (has_to_sort(*a) != 0 && sort_len <= 50)
		sort_fifty(a, b, sort_len, sort_len);
	else
	{
		pushed = push_break(a, b, get_median(*a, sort_len), 0);
		if (sort_len % 2 != 0)
			pushed++;
		sort_hundred(a, b, pushed, total_len);
	}
	if (get_len(*a) <= 100 && *b)
		sort_back_hundred(b, a, sort_len);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:32:15 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 15:00:44 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	push_multiple(t_stack **from, t_stack **to, int times)
{
	while (times--)
		push(from, to);
}

int	push_rotate(t_stack **from, t_stack **to)
{
	if (*to && (*to)->stack == 'b'
		&& (*to)->sub_cont < get_median(*to, get_len(*to)))
		rotate_both(from, to);
	else
		rotate(from, 'y');
	if (((*from)->stack == 'a'
			&& (*from)->prev->sub_cont < get_median(*from, get_len(*from)))
		|| ((*from)->stack == 'b'
			&& (*from)->prev->sub_cont > get_median(*from, get_len(*from))))
		return (1);
	return (0);
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
		else
			times += push_rotate(from, to);
	}
	if (((*from)->stack == 'a' && rr == 1 && get_len(*from) > 3)
		|| ((*from)->stack == 'b' && get_len(*from) > 5))
		rotate_multiple(from, "rr", times);
	return (pushed);
}

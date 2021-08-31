/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:12 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 12:07:46 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	get_median(t_stack *target, int sort_len)
{
	long int	sum;
	long int	med;
	int			len;

	sum = 0;
	len = sort_len;
	while (len--)
	{
		sum += target->sub_cont;
		target = target->next;
	}
	target = target->next;
	med = sum / sort_len;
	if (target->stack == 'a' && (sort_len % 2 == 0 || sort_len == 7))
		med++;
	return (med);
}

int	get_len(t_stack *stack)
{
	t_stack	*temp;
	int		len;

	if (stack == NULL)
		return (0);
	temp = stack;
	len = 1;
	while (stack->next != temp)
	{
		len++;
		stack = stack->next;
	}
	stack = stack->next;
	return (len);
}

long int	get_mincont(t_stack *stack)
{
	long int	mincont;
	t_stack		*temp;

	temp = stack;
	while (stack->sub_cont != -1)
		stack = stack->next;
	mincont = stack->content;
	while (stack->next != temp)
	{
		if (stack->content < mincont && stack->sub_cont == -1)
			mincont = stack->content;
		stack = stack->next;
	}
	if (stack->content < mincont && stack->sub_cont == -1)
		mincont = stack->content;
	stack = stack->next;
	return (mincont);
}

long int	get_minsubcont(t_stack *stack)
{
	long int	minsubcont;
	t_stack		*temp;

	temp = stack;
	minsubcont = stack->sub_cont;
	while (stack->next != temp)
	{
		if (stack->sub_cont < minsubcont)
			minsubcont = stack->sub_cont;
		stack = stack->next;
	}
	if (stack->sub_cont < minsubcont)
		minsubcont = stack->sub_cont;
	stack = stack->next;
	return (minsubcont);
}

long int	get_maxnum(t_stack *stack)
{
	long int	maxnum;
	t_stack		*temp;

	temp = stack;
	maxnum = stack->sub_cont;
	while (stack->next != temp)
	{
		if (stack->sub_cont > maxnum)
			maxnum = stack->sub_cont;
		stack = stack->next;
	}
	if (stack->sub_cont > maxnum)
		maxnum = stack->sub_cont;
	stack = stack->next;
	return (maxnum);
}

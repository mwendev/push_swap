/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:12 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 15:03:14 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	get_median(t_stack *stack, long int sort_len)
{
	long int	sum;
	long int	med;
	int			alen;
	int			alen_dup;

	sum = 0;
	if (sort_len == 0)
		alen = get_len(stack);
	else
		alen = sort_len;
	alen_dup = alen;
	while (alen_dup--)
	{
		sum += stack->sub_cont;
		stack = stack->next;
	}
	stack = stack->next;
	med = sum / alen;
	if (sort_len % 2 == 0)
		med++;
	// printf("med %ld\n", med);
	return (med);
}

// int	get_position(t_stack **stack, long int med)
// {
// 	long int	first;
// 	long int	check_point;
// 	int			position;
// 	int			ret_position;

// 	first = (*stack)->content;
// 	check_point = (*stack)->next->content;
// 	position = -1;
// 	ret_position = -1;
// 	while ((*stack)->content != check_point)
// 	{
// 		check_point = first;
// 		position++;
// 		if ((*stack)->content > med && ret_position == -1)
// 			ret_position = position;
// 		*stack = (*stack)->next;
// 	}
// 	return (ret_position);
// }

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

// int	get_step(t_stack **stack, int position, long int target, int direction)
// {
// 	t_stack	**temp;
// 	int		step;

// 	temp = stack;
// 	step = 0;
// 	while (position--)
// 		*temp = (*temp)->next;
// 	while ((*temp)->content != target)
// 	{
// 		if (direction == 0)
// 			*temp = (*temp)->prev;
// 		if (direction == 1)
// 			*temp = (*temp)->next;
// 		step++;
// 	}
// 	return (step);
// }

// t_stack	**get_node(t_stack **stack, int node, int alen)//it changes stack
// {
// 	t_stack	**temp;

// 	temp = stack;
// 	while ((*temp)->valid == 0)
// 		*temp = (*temp)->next;
// 	if (node == 1)
// 	{
// 		while ((*temp)->valid == node && --alen)
// 			*temp = (*temp)->next;
// 	}
// 	return (temp);
// }

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
		{
			minsubcont = stack->sub_cont;
		}
		stack = stack->next;
	}
	if (stack->sub_cont < minsubcont)
		{
			minsubcont = stack->sub_cont;
		}
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
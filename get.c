/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:18:12 by mwen              #+#    #+#             */
/*   Updated: 2021/08/03 16:44:51 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	get_median(t_stack *stack, long int pushed)
{
	long int	sum;
	long int	med;
	int			alen;
	int			alen_dup;

	sum = 0;
	if (pushed == 0)
		alen = get_len(stack);
	else
		alen = pushed;
	alen_dup = alen;
	while (alen_dup--)
	{
		sum += stack->sub_cont;
		stack = stack->next;
	}
	stack = stack->next;
	med = sum / alen;
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

long int	get_minnum(t_stack *stack)
{
	long int	minnum;
	t_stack		*temp;

	temp = stack;
	while (stack->sub_cont != -1)
		stack = stack->next;
	minnum = stack->content;		
	while (stack->next != temp)
	{
		if (stack->content < minnum && stack->sub_cont == -1)
			minnum = stack->content;
		stack = stack->next;
	}
	if (stack->content < minnum && stack->sub_cont == -1)
		minnum = stack->content;
	stack = stack->next;
	return (minnum);
}

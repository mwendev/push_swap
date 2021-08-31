/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:57:36 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 12:07:51 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stacknew(long int cont, long int sub_cont)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = cont;
	new->sub_cont = sub_cont;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack	*stacklast(t_stack *stack)
{
	return (stack->prev);
}

t_stack	*stackadd(t_stack *stack, long int cont, long int sub_cont, int front)
{
	t_stack	*new;
	t_stack	*last;

	new = stacknew(cont, sub_cont);
	last = stacklast(stack);
	stack->prev = new;
	last->next = new;
	new->prev = last;
	new->next = stack;
	if (front == 1)
		stack = stack->prev;
	return (stack);
}

void	stackdel(t_stack **stack)
{
	t_stack	*temp;

	temp = stacklast(*stack);
	if (!stack)
		return ;
	else if ((*stack)->next == *stack)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp->next = (*stack)->next;
		(*stack)->next->prev = temp;
		free(*stack);
		*stack = temp->next;
	}
}

t_stack	*init_stack(t_stack *stack, long int cont, long int sub_cont)
{
	if (!stack)
		stack = stacknew(cont, sub_cont);
	else
		stack = stackadd(stack, cont, sub_cont, 0);
	return (stack);
}

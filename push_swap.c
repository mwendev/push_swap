/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:10:54 by mwen              #+#    #+#             */
/*   Updated: 2021/08/03 15:14:34 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*last;
	int		len;

	last = stacklast(stack);
	temp = NULL;
	len = get_len(stack);
	while (temp != last)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	if (len > 1)
		free(stack);
}

t_stack	*assign_subcont(t_stack *stack, int alen)
{
	long int	minnum;
	t_stack		*temp;
	long int	sub_cont;

	temp = stack;
	sub_cont = 0;
	while (++sub_cont <= alen)
	{
		minnum = get_minnum(stack);
		while (stack->next != temp)
		{
			if (stack->content == minnum)
				stack->sub_cont = sub_cont;
			stack = stack->next;
		}
		if (stack->content == minnum)
			stack->sub_cont = sub_cont;
		stack = stack->next;
	}
	return (stack);
}

void	push_swap(t_stack **a, t_stack **b, int alen)
{
	if (alen == 2)
		sort_two(a, b, 'a');
	else if (alen == 3)
		sort_three(a, b, 'a');
	else if (alen <= 5)
		sort_five(a, b);
	else if (alen <= 10)
		sort_ten(a, b);
	else if (alen <= 100)
		sort_hundred(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			alen;
	int			sorted;
	long int	num;
	
	a = NULL;
	b = NULL;
	alen = 0;
	sorted = 1;
	if (argc < 2)
		return (1);
	while (alen < (argc - 1))
	{
		check_numeric(a, argv[alen + 1], alen);
		num = ft_atoi(argv[alen + 1]);
		check_maxint(a, num, alen);
		check_dup(a, num, alen);
		a = init_stack(a, num, -1);
		if (check_sorted(a, alen) == 0)
			sorted = 0;
		++alen;
	}
	a = assign_subcont(a, alen);
	if (sorted == 0)
		push_swap(&a, &b, alen);
	for (int i = 0; i < 50; i++)
	{
		printf("cont is %ld sub is %ld\n", a->content, a->sub_cont);
		// printf("a cont is: %ld sub is: %ld  b cont is: %ld sub is: %ld\n", a->content, a->sub_cont, b->content, b->sub_cont);
		a = a->next;
		// b = b->next;
	}
	free_stack(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:10:54 by mwen              #+#    #+#             */
/*   Updated: 2021/08/28 23:35:04 by mwen             ###   ########.fr       */
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

t_stack	*assign_subcont_stack(t_stack *a, int alen, char c)
{
	long int	minnum;
	t_stack		*temp;
	long int	sub_cont;

	temp = a;
	sub_cont = 0;
	while (++sub_cont <= alen)
	{
		minnum = get_mincont(a);
		while (a->next != temp)
		{
			a->stack = c;
			if (a->content == minnum)
				a->sub_cont = sub_cont;
			a = a->next;
		}
		a->stack = c;
		if (a->content == minnum)
			a->sub_cont = sub_cont;
		a = a->next;
	}
	return (a);
}

void	push_swap(t_stack **a, t_stack **b, int alen)
{
	if (alen <= 13)
		sort_ten(a, b, alen);
	else if (alen <= 50)
		sort_fifty(a, b, get_len(*a), get_len(*a));
	else if (alen <= 100)
		sort_hundred(a, b, get_len(*a), get_len(*a));
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
	a = assign_subcont_stack(a, alen, 'a');
	if (sorted == 0)
	{
		push_swap(&a, &b, alen);
	}
	for (int i = 0; i < 100; i++)
	{
		printf("cont is %ld sub is %ld\n", a->content, a->sub_cont);
		// printf("cont: %ld sub: %ld %c	cont: %ld sub: %ld %c\n", a->content, a->sub_cont, a->stack, b->content, b->sub_cont, b->stack);
		a = a->next;
		// b = b->next;
	}
	free_stack(a);
}

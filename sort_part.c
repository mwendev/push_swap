/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:42:03 by mwen              #+#    #+#             */
/*   Updated: 2021/08/25 23:43:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_part(t_stack **a, t_stack **b, long int num, int plus)//DELL
{
	int	pushed;

	pushed = 0;
	if (plus == 1)
		num++;
	while (has_to_push(*a, num, 0) == 1)
	{
		if ((*a)->sub_cont < num)
		{
			push_b(a, b);
			pushed++;
		}
		else
			rotate(a, 'a');
	}
	return (pushed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:47:14 by mwen              #+#    #+#             */
/*   Updated: 2021/08/02 15:49:09 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_multiple(t_stack **stack, char c, char *func, int times)
{
	while (times--)
	{
		if (ft_strncmp(func, "rr", 2) == 0)
			rrotate(stack, c);
		else if (ft_strncmp(func, "r", 1) == 0)
			rotate(stack, c);
		else if (ft_strncmp(func, "s", 1) == 0)
			swap(stack, c);

	}
}
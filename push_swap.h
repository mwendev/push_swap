/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:54:57 by mwen              #+#    #+#             */
/*   Updated: 2021/08/26 16:28:23 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
#include <stdio.h>

typedef struct		s_node
{
	struct s_node	*prev;
	long int		content;
	long int		sub_cont;
	struct s_node	*next;
}					t_stack;

void	check_dup(t_stack *a, long int num, int alen);
void	check_numeric(t_stack *a, char *input, int alen);
void	check_maxint(t_stack *a, long int num, int alen);
int		check_sorted(t_stack *a, int alen);

void	error(t_stack *a, int alen);
void	free_stack(t_stack *stack);

t_stack	*init_stack(t_stack *stack, long int cont, long int sub_cont);
t_stack	*stacknew(long int cont, long int sub_cont);
t_stack	*stacklast(t_stack *stack);
t_stack	*stackadd(t_stack *stack, long int cont, long int sub_cont, int front);
void	stackdel(t_stack **stack);

long int	get_mincont(t_stack *stack);
long int	get_minsubcont(t_stack *stack);
long int	get_maxnum(t_stack *stack);
int			get_len(t_stack *stack);
long int	get_median(t_stack *stack, long int pushed);

void	sort_two(t_stack **stack_one, t_stack **stack_two, char c);
void	sort_three(t_stack **stack_one, t_stack **stack_two, char c);
void	sort_five(t_stack **stack_one, t_stack **stack_two, int sort_len);
void	sort_ten(t_stack **stack_one, t_stack **stack_two);

void	sort_twentyfive(t_stack **a, t_stack **b, int sort_len, int origin_len);
void	sort_fifty(t_stack **a, t_stack **b, int sort_len, int origin_len);
void	sort_hundred(t_stack **a, t_stack **b, int sort_len, int origin_len);


int	sort_part(t_stack **a, t_stack **b, long int num, int plus);


void	swap(t_stack **stack, char c);
void	swap_both(t_stack **a, t_stack **b);
void	rotate(t_stack **stack, char c);
void	rotate_both(t_stack **a, t_stack **b);
void	rrotate(t_stack **stack, char c);
void	rrotate_both(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);

void	push_multiple(t_stack **a, t_stack **b, char *func, int times);
int		push_smaller_than(t_stack **one, t_stack **two, long int num, int rr);
int		push_larger_than(t_stack **one, t_stack **two, long int pushed);

void	rotate_multiple(t_stack **stack, char c, char *func, int times);
void	swap_multiple(t_stack **a, t_stack **b, char *func, int times);

int	has_to_push(t_stack *stack, long int num, int larger);
int	has_to_sort(t_stack *stack);




#endif
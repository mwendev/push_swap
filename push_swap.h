/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:54:57 by mwen              #+#    #+#             */
/*   Updated: 2021/08/31 15:22:01 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	long int		content;
	long int		sub_cont;
	char			stack;
	struct s_node	*next;
}					t_stack;

void		check_dup(t_stack *a, long int num, int alen);
void		check_numeric(t_stack *a, char *input, int alen);
void		check_maxint(t_stack *a, long int num, int alen);
int			check_sorted(t_stack *a, int alen);

void		error(t_stack *a, int alen);
void		free_stack(t_stack *stack);

t_stack		*init_stack(t_stack *stack, long int cont, long int sub_cont);
t_stack		*stacknew(long int cont, long int sub_cont);
t_stack		*stacklast(t_stack *stack);
t_stack		*stackadd(t_stack *stack, long int cont, long int sub_cont, int d);
void		stackdel(t_stack **stack);

int			get_len(t_stack *stack);
long int	get_mincont(t_stack *stack);
long int	get_minsubcont(t_stack *stack);
long int	get_maxnum(t_stack *stack);
long int	get_median(t_stack *stack, int pushed);

void		sort_two(t_stack **a, t_stack **b);
void		sort_three(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b, int sort_len);
void		sort_ten(t_stack **a, t_stack **b, int sort_len);
void		sort_twentyeight(t_stack **a, t_stack **b, int sort_len);
void		sort_fiftysix(t_stack **a, t_stack **b, int sort_len);
void		sort_hundred(t_stack **a, t_stack **b, int sort_len, int total_len);
void		sort_fivehundred(t_stack **a, t_stack **b, int slen, int tlen);
void		sort(t_stack **a, t_stack **b, int sort_len, int total_len);

void		swap(t_stack **target, char print);
void		swap_both(t_stack **a, t_stack **b);
void		rotate(t_stack **target, char print);
void		rotate_both(t_stack **a, t_stack **b);
void		rrotate(t_stack **target, char print);
void		rrotate_both(t_stack **a, t_stack **b);
void		push(t_stack **from, t_stack **to);

void		push_multiple(t_stack **from, t_stack **to, int times);
int			push_break(t_stack **from, t_stack **to, long int num, int rr);

void		rotate_multiple(t_stack **target, char *func, int times);
void		swap_multiple(t_stack **a, t_stack **b, char *func, int times);

int			has_to_push(t_stack *target, long int num, int len);
int			has_to_sort(t_stack *stack);
int			has_to_rrotate(t_stack **from, long int num);

#endif
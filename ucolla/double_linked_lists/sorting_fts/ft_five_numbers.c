/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:33:56 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/01 17:39:17 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_find_smallest(t_stack *stack)
{
	int		min_value;
	int		current_value;
	t_stack	*tmp;

	min_value = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->value;
		if (current_value < min_value)
			min_value = current_value;
		tmp = tmp->next;
	}
	return (min_value);
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = *stack_a;
	while (a)
	{
		b = *stack_a;
		if (a->value == ft_find_smallest(b))
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(stack_a) / 2)
	{
		while (--i >= 0)
			ra(stack_a);
	}
	else
	{
		while (++i <= ft_list_size(stack_a))
			rra(stack_a);
	}
	printf("head_A: %d\n", (*stack_a)->index);
	pb(stack_b, stack_a);
}

void	ft_else_if(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sa(stack_a);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
}

/* void	ft_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ft_three_numbers(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		if ((*stack_b)->index < ft_list_last(*stack_a)->index)
			sb(stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > ft_list_last(*stack_a)->index)
		ra(stack_a);
	else
		ft_else_if(stack_a);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > ft_list_last(*stack_a)->index)
		ra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index)
	{
		sa(stack_a);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
} */

static int	find_biggest_index(t_stack *stack)
{
	int		max_value;
	int		current_value;
	t_stack	*tmp;

	max_value = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		current_value = tmp->index;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
	}
	return (max_value);
}

static void	push_biggest(t_stack **stack_a, t_stack **stack_b, int value)
{
	int	i;
	t_stack *a;

	i = 0;
	a = *stack_a;
	while (a)
	{
		if (a->index == value)
			break ;
		a = a->next;
		i++;
	}
	if (i <= ft_list_size(stack_a) / 2)
		while (--i >= 0)
			ra(stack_a);
	else
		while (++i <= ft_list_size(stack_a))
			rra(stack_a);
	pb(stack_b, stack_a);
}

void	ft_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_biggest(stack_a, stack_b, find_biggest_index(*stack_a) - 1);
	push_biggest(stack_a, stack_b, find_biggest_index(*stack_a));
	ft_three_numbers(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:05:05 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/18 15:11:37 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	max_value;
	int	current_value;

	max_value = INT_MIN;
	while (stack)
	{
		current_value = stack->index;
		if (current_value > max_value)
			max_value = current_value;
		stack = stack->next;
	}
	return (max_value);
}

int	find_eff1(t_stack *stack, int c)
{
	int	i;
	int	a;
	int	t;
	t_stack *temp;

	temp = stack;
	a = 0;
	i = 0;
	while (temp)
	{
		if (temp->chunk == c)
			break ;
		temp = temp->next;
		i++;
	}
	temp = stack;
	while (temp)
	{
		if (temp->chunk == c)
			t = temp->index;
		temp = temp->next;
	}
	temp = stack;
	while (temp)
	{
		if (temp->index == t)
			a = ft_list_size(temp);
		temp = temp->next;
	}
	if (a > i)
		return (0);
	else
		return (1);
}

int	find_eff2(t_stack *stack)
{
	int	min_value;
	int	current_value;
	int	i;

	i = 0;
	current_value = stack->index;
	min_value = find_biggest(stack);
	while (current_value != min_value)
	{
		current_value = stack->index;
		if (current_value < min_value)
			min_value = current_value;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	a;
	int c;
	t_operator	operator;

	(void)i;
	a = 0;
	c = 1;
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	while (ft_list_size(*stack_a) > 3)
	{
		check_efficiency(*stack_a, *stack_b, c, &operator);
		// ft_printf("rr : %d\n", operator.rr);
		// ft_printf("rrr : %d\n", operator.rrr);
		// ft_printf("ra : %d\n", operator.ra);
		// ft_printf("rb : %d\n", operator.rb);
		// ft_printf("rra : %d\n", operator.rra);
		// ft_printf("rrb : %d\n", operator.rrb);
		while (operator.rr > 0)
		{
			rr(stack_a, stack_b);
			operator.rr--;
		}
		while (operator.rrr > 0)
		{
			rrr(stack_a, stack_b);
			operator.rrr--;
		}
		while (operator.ra > 0)
		{
			ra(stack_a);
			operator.ra--;
		}
		while (operator.rb > 0)
		{
			rb(stack_b);
			operator.rb--;
		}
		while (operator.rra > 0)
		{
			rra(stack_a);
			operator.rra--;
		}
		while (operator.rrb > 0)
		{
			rrb(stack_b);
			operator.rrb--;
		}
		pb(stack_b, stack_a);
		if ((*stack_b)->index == find_smallest(*stack_b))
			rb(stack_b);
		a++;
		if (a == 20)
		{
			a = 0;
			c++;
		}
	}
	three_numbers_a(stack_a);
	while ((*stack_b)->next)
	{
		if ((*stack_b)->index > find_biggest(*stack_a) || (*stack_b)->index < find_smallest(*stack_a))
			while (ft_list_last(*stack_a)->index != find_biggest(*stack_a))
				ra(stack_a);
		else
			while ((*stack_b)->index > (*stack_a)->index)
			ra(stack_a);
		pa(stack_a, stack_b);
	}
	if ((*stack_b)->index > find_biggest(*stack_a))
		while (ft_list_last(*stack_a)->index != find_biggest(*stack_a))
			ra(stack_a);
	else
		while ((*stack_b)->index > (*stack_a)->index)
			ra(stack_a);
	pa(stack_a, stack_b);
	while((*stack_a)->index > find_smallest(*stack_a))
		ra(stack_a);
}

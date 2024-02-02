/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:33:44 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/01 19:33:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	array_size(int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
		i++;
	return (i);
}

int ft_if_in(int index, int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
	{
		if (array[i] == index)
			return (1);
		i++;
	}
	return (0);
}

int	*create_array(t_stack *stack, int size)
{
	int		*array;
	int		i;
	t_stack	*tmp;

	array = (int *)malloc(sizeof(int) * (ft_list_size(stack) + 1));
	i = 0;
	tmp = stack;
	while (tmp && i < size)
	{
		array[i] = tmp->index;
		i++;
		tmp = tmp->next;
	}
	return (array);
}

int	*find_longest_lis(t_lis **lis, int list_size)
{
	int	counter;
	int	current_value;
	int	biggest_length;
	int	*lis_path;
	int	*final_lis;

	counter = 0;
	current_value = 0;
	biggest_length = 0;
	lis_path = NULL;
	final_lis = NULL;
	while (counter < list_size)
	{
		lis_path = ft_circular_lis(lis, list_size);
		biggest_length = array_size(lis_path);
		if (biggest_length > current_value)
		{
			current_value = biggest_length;
			final_lis = lis_path;
		}
		*lis = (*lis)->next;
		counter++;
	}
	return (final_lis);
}


void	lis_init(t_stack **stack)
{
	int		*array_lis;
	t_lis	*lis;
	t_stack *temp;

	lis = index_lis_init(stack, ft_list_size(*stack));
	temp = *stack;
	array_lis = find_longest_lis(&lis, ft_list_size(*stack));
	while (temp)
	{
		if (ft_if_in(temp->index, array_lis) == 1)
			temp->push = 1;
		temp = temp->next;
	}
}

int	find_index(t_stack **stack)
{
	int		min_value;
	int		current_value;
	t_stack	*temp;

	min_value = INT_MAX;
	temp = *stack;
	while (temp)
	{
		current_value = temp->value;
		if (current_value < min_value && temp->has_index == 0)
			min_value = current_value;
		temp = temp->next;
	}
	return (min_value);
}

void	index_init(t_stack **stack)
{
	int		i;
	int		smallest;
	int		c;
	t_stack	*a;
	t_stack	*b;

	c = 1;
	i = 1;
	a = *stack;
	while (a)
	{
		b = *stack;
		smallest = find_index(&b);
		ft_list_find_node(b, smallest)->index = i;
		ft_list_find_node(b, smallest)->has_index = 1;
		ft_list_find_node(b, smallest)->chunk = c;
		a = a->next;
		if (i == ft_list_size(*stack) / 2)
			c++;
		i++;
	}
	lis_init(stack);
}

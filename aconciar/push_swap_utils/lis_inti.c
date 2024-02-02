/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_inti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:33:00 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 16:33:23 by aconciar         ###   ########.fr       */
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

int	ft_if_in(int index, int *array)
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
	t_stack	*temp;

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

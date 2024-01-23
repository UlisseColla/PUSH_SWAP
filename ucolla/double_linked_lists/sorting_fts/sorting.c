/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:22:11 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/23 17:48:20 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* Creazione di array degli int passati come argomento a push_swap */
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

/* Trova il prossimo numero piu' piccolo */
// long	ft_smaller(long *args, long num, long index)
// {
// 	while (index >= 0)
// 	{
// 		if (args[index] < num)
// 			return (args[index]);
// 		index--;
// 	}
// 	return (num);
// }

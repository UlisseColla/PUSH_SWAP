/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:40:20 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/30 15:40:45 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

/* trova valore length piu' grande */
int	find_biggest_length(t_lis *lis, int size)
{
	int		max_value;
	int		current_value;
	int		i;
	t_lis	*tmp;

	max_value = 0;
	tmp = lis;
	i = 0;
	while (i < size)
	{
		current_value = tmp->length;
		if (current_value > max_value)
			max_value = current_value;
		tmp = tmp->next;
		i++;
	}
	if (tmp->length > max_value)
		max_value = tmp->length;
	return (max_value);
}

/* trova il nodo in base al valore length_to_search */
t_lis	*find_biggest_length_node(t_lis *lis, int size, int length_to_search)
{
	int		i;
	t_lis	*tmp;

	tmp = lis;
	i = 0;
	while (i < size)
	{
		if (tmp->length == length_to_search)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	if (tmp->length == length_to_search)
		return (tmp);
	return (NULL);
}

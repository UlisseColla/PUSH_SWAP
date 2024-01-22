/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:49:12 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 18:01:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_list_find_node(t_stack *list, int value)
{
	while (list)
	{
		if (list->value == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

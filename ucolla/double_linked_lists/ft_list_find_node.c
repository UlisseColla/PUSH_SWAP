/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:49:12 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/09 13:31:27 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

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

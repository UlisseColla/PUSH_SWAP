/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:42:07 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/22 14:54:48 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

void	init_moves(t_stack **node)
{
	(*node)->ops->sa = 0;
	(*node)->ops->sb = 0;
	(*node)->ops->ss = 0;
	(*node)->ops->ra = 0;
	(*node)->ops->rb = 0;
	(*node)->ops->rr = 0;
	(*node)->ops->rra = 0;
	(*node)->ops->rrb = 0;
	(*node)->ops->rrr = 0;
}

t_stack	*ft_create_node(int value)
{
	t_stack	*new;
	t_ops	*moves;

	new = (t_stack *)malloc(sizeof(t_stack));
	moves = (t_ops *)malloc(sizeof(t_ops));
	if (new == NULL || moves == NULL)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	new->ops = moves;
	init_moves(&new);
	return (new);
}

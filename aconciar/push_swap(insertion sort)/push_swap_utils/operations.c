/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:15:21 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/03 17:57:08 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack, t_list **node)
{
	t_list *tmp_node;

	tmp_node = (*node)->next;
	ft_lstadd_front(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	pb(t_list **stack, t_list **node)
{
	t_list *tmp_node;

	tmp_node = (*node)->next;
	ft_lstadd_front(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:15:21 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/09 17:11:36 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack, t_list **node)
{
	t_list *tmp_node;

	tmp_node = (*node)->next;
	ft_lstadd_front(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	push_b(t_list **stack, t_list **node)
{
	t_list *tmp_node;

	tmp_node = (*node)->next;
	ft_lstadd_front(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}


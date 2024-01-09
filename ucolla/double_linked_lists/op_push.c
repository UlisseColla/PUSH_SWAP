/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:39 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/09 17:46:53 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

void	push_a(t_stack **stack, t_stack **node)
{
	t_stack *tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pa\n");
}

void	push_b(t_stack **stack, t_stack **node)
{
	t_stack *tmp_node;

	tmp_node = (*node)->next;
	ft_list_addfront(stack, *node);
	*node = tmp_node;
	ft_printf("pb\n");
}
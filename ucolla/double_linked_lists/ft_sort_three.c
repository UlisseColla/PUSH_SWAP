/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:02:54 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/09 14:06:23 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

// void	sort_three(t_list **stack)
// {
// 	// t_list *tmp = NULL;
	
// 	if (*(int *)((*stack)->content) == find_biggest(*stack)) //max all'inizio
// 	{
// 		if (*(int *)((*stack)->next->content) == find_smallest(*stack))
// 			rotate_a(stack);
// 		else
// 		{
// 			swap_a(stack);
// 			reverse_rotate_a(stack);
// 		}
// 	}
// 	else if (*(int *)((*stack)->content) == find_smallest(*stack)) //min all'inizio
// 	{
// 		if (*(int *)((*stack)->next->content) == find_biggest(*stack))
// 		{
// 			reverse_rotate_a(stack);
// 			swap_a(stack);
// 		}
// 	}
// 	else // middle all'inizio
// 	{
// 		if (*(int *)((*stack)->next->content) == find_biggest(*stack))
// 			reverse_rotate_a(stack);
// 		else
// 			swap_a(stack);
// 	}
// }
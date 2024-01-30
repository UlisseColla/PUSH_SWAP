/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:41:00 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/30 18:48:49 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	b = NULL;
	if (initialize_stack(&a, argv, argc) == 1)
		return (1);
	
	ft_printf("STACK_A\n");
	show_stack(&a);
	ft_printf("STACK_B\n");
	show_stack(&b);
	return (0);
}

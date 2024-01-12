/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 12:14:30 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 1 || check_input(argv[1]) == 1)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	else
		a = ft_create_list(argv[1]);
	b = NULL;
	
	index_stack_init(&a);
	show_stack(&a);
	show_stack(&b);

	return (0);	
}
	
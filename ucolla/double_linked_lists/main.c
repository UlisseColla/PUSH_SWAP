/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:23 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 19:18:23 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	int file = open("ARGS", O_RDONLY, 0666);
	(void)argv;
	if (check_input(get_next_line(file)) == 1 || argc < 0)
	{
		ft_putstr_fd("Wrong set of parameters\n", 2);
		return (1);
	}
	else
	{
		int file = open("ARGS", O_RDONLY, 0666);
		a = ft_create_list(get_next_line(file));
	}
	b = NULL;
	
	index_stack_init(&a);
	show_stack(&a);
	show_stack(&c);

	return (0);	
}
	
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:41:00 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/04 18:00:12 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (initialize_stack(&a, argv, argc) == 1)
		return (1);
	if (check_order(&a) == 0 && argc > 1)
	{
		if (ft_list_size(&a) == 2)
			ft_two_numbers(&a);
		else if (ft_list_size(&a) == 3)
			ft_three_numbers(&a);
		else if (ft_list_size(&a) == 4)
			ft_four_numbers(&a, &b);
		else if (ft_list_size(&a) == 5)
			ft_five_numbers(&a, &b);
		else
			sorting(&a, &b);
	}
	printf("a:\n");
	show_stack(&a);
	printf("b:\n");
	show_stack(&b);
	ft_free_list(a);
	ft_free_list(b);
	return (0);
}

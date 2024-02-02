/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/02 21:29:09 by aconciar         ###   ########.fr       */
=======
/*   Updated: 2024/02/02 15:57:06 by ucolla           ###   ########.fr       */
>>>>>>> 6e49d9481d58916aba41d16120530038a99a3689
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_init(argc, argv, &stack_a) == 1)
	{
		ft_free_list(stack_a);
		ft_printf("Error\n");
		return (1);
	}
	index_init(&stack_a);
	if (ft_list_size(stack_a) == 2 && check_order(stack_a) == 1)
		two_numbers_a(&stack_a);
	else if (ft_list_size(stack_a) == 3 && check_order(stack_a) == 1)
		three_numbers_a(&stack_a);
	else if (ft_list_size(stack_a) == 5 && check_order(stack_a) == 1)
		five_numbers(&stack_a, &stack_b);
	if (check_order(stack_a) == 1)
		sorting(&stack_a, &stack_b);
	ft_free_list(stack_a);
	return (0);
}

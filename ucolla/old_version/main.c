/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/09 15:10:12 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*num;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		return (0);
	while (argv[++i])
	{
		num = malloc(sizeof(int));
		*num = atoi(argv[i]);
		ft_lstadd_back(&stack_a, ft_lstnew(num));
	}
	
	/* operazioni */
	// if (argc == 4)
	// 	sort_three(&stack_a);
	// if (argc == 6)
	// 	sort_five(&stack_a, &stack_b);
	push_b(&stack_b, &stack_a);
	while (stack_a)
	{	
		ft_printf("%d\n", (*(int *)(stack_a->content)));
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	while (stack_b)
	{	
		ft_printf("%d\n", (*(int *)(stack_b->content)));
		stack_b = stack_b->next;
	}
	// ft_printf("Stack in ordine\n");
	// show_stacks(&stack_a, &stack_b);
}

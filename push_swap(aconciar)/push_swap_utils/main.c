/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:02 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/03 17:57:17 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**mat;
	int		i;
	int		*num;
	char	*str = NULL;
	char	*str2 = NULL;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (check_input(argv[1]) != 0)
			return (ft_printf("Error\n"));
		mat = ft_split(argv[1], ' ');
		i = 0;
		while (mat[i])
		{
			num = malloc(sizeof(int));
			*num = atoi(mat[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(num));
			i++;
		}
		free_mat(mat);
	}
	else if (argc < 2)
		return (0);
	else
	{
		while (argv[++i])
		{
			str = ft_strjoin(argv[i], " ");
			str2 = ft_strjoingnl(str2, str);
			free(str);
		}
		if (check_input(str2) != 0)
		{
			free(str2);
			return (ft_printf("Error\n"));
		}
		free(str2);
		i = 0;
		while (argv[++i])
		{
			num = malloc(sizeof(int));
			*num = atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(num));
		}
		i--;
	}
	if (i == 2 && check_order(stack_a) == 1)
		two_numbers_a(&stack_a);
	else if (i == 3 && check_order(stack_a) == 1)
		three_numbers_a(&stack_a);
	else if (i == 5 && check_order(stack_a) == 1)
		five_numbers(&stack_a, &stack_b);
	else if (check_order(stack_a) == 1)
		insertion_sort(&stack_a, &stack_b, (i / 2));
	// while (stack_a)
	// {	
	// 	ft_printf("%d\n", (*(int *)(stack_a->content)));
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("\n");
	// while (stack_b)
	// {	
	// 	ft_printf("%d\n", (*(int *)(stack_b->content)));
	// 	stack_b = stack_b->next;
	// }
	ft_lstclear(&stack_a, free);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:16:10 by aconciar          #+#    #+#             */
/*   Updated: 2024/02/02 21:31:13 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	ft_free_list(*stack_a);
	ft_free_list(*stack_b);
	ft_printf("KO\n");
	exit (1);
}

char *ft_check_operations(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "pa") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(stack_b, stack_a, 0);
	else if (ft_strcmp(line, "sa") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
	else
		ft_error(stack_a, stack_b);
	return (get_next_line(0));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	while (line && *line != '\n')
		line = ft_check_operations(stack_a, stack_b, line);
	if (*stack_b)
		ft_error(stack_a, stack_b);
	else if (check_order(*stack_a) == 1)
		ft_error(stack_a, stack_b);
	else
		ft_error(stack_a, stack_b);
	free(line);
}


int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (stack_init(argc, argv, &stack_a) == 1)
		ft_error(&stack_a, &stack_b);
	line = get_next_line(0);
	if (!line && check_order(stack_a) == 1)
		ft_error(&stack_a, &stack_b);
	else if (!line && check_order(stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_check(&stack_a, &stack_b, line);
	ft_free_list(stack_a);
	return (0);
}

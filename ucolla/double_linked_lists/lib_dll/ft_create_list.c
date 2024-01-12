/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:51:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 12:30:38 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_dll.h"

t_stack	*ft_create_list(char *str_args)
{
	t_stack	*list;
	t_stack	*new;
	int		i;
	char	**args;

	list = NULL;
	i = 0;
	args = ft_split(str_args, ' ');
	while (args[i])
	{
		new = ft_create_node(ft_atoi(args[i]));
		if (new == NULL)
		{
			ft_free_list(list);
			return (NULL);
		}
		ft_list_addback(&list, new);
		i++;
	}
	free_mat(args);
	return (list);
}

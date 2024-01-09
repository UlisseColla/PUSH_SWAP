/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:51:04 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/09 13:35:09 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

t_stack	*ft_create_list(int argc, char **argv)
{
	t_stack	*list;
	t_stack	*new;
	int		i;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		new = ft_create_node(ft_atoi(argv[i]));
		if (new == NULL)
		{
			ft_free_list(list);
			return (NULL);
		}
		ft_list_addback(&list, new);
		i++;
	}
	return (list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:52:08 by ucolla            #+#    #+#             */
/*   Updated: 2024/02/01 15:16:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_list(t_stack *list)
{
	t_stack	*tmp;

	if (list == NULL)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

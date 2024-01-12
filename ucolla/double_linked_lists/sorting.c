/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:22:11 by ucolla            #+#    #+#             */
/*   Updated: 2024/01/12 19:12:22 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_dll.h"

/* 
	1. Definire una funzione cost() per calcolare quante mosse mi costa mettere un 
   	elemento al posto giusto nello stack
	2. definire funzione find_longest_route() per trovare la piu' lunga lista di numeri
	gia' oridnata
	3. Pushare gli elementi in B mettendoli in ordine decrescente
	4. Ripushare in A mettendoli al posto giusto, clacolando di volta in volta
	5. Ruotare nella direzione piu' conceninte per riordinare la lista

	2.
	--> a. creare un array di array **int, tanti quanti sono i numeri nello stack
		b. partire dal numero piu' grande al piu' piccolo e calcolare per ognuno
		la lista piu' lunga possibile fino al piu' piccolo
		c. alla fine calcolare quale array e' il piu' lungo e ritornarlo
*/

/* Creazione di array degli int passati come argomento a push_swap */
int	*create_array(t_stack *stack)
{
	int		*array;
	int		i;
	t_stack	*tmp;

	array = (int *)malloc(sizeof(int) * ft_list_size(stack));
	i = 0;
	tmp = stack;
	while (tmp)
	{
		array[i] = tmp->index;
		i++;
		tmp = tmp->next
	}
	return (array);
}

/* Funzione per trovare la sequenza piu' lunga */
int	*find_longest_path(int *args)
{
	int		i;
	int		j;

	i = arr_find_biggest(args);
	j = i;
	while (i > 0)
	{
		
	}
	
}

int	*ret_longest_array(t_stack *stack)
{
	t_stack	*tmp;
	int	i;
	int	**matrix;

	tmp = ft_list_last(stack);
	i = ft_list_size(stack);
	matrix = (int *)malloc(sizeof(int *) * i);
	while (--i >= 0)
	{
		/* Funzione per trovare la sequenza piu' lunga */
		tmp = tmp->prev;
	}
	/* Funzione per trovare l'array piu' lungo */
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:41:58 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/04 17:09:48 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_dlist *list)
{
	int		max;
	t_dlist	*tmp;

	max = INT_MIN;
	tmp = list;
	while (tmp->next->value != -1)
	{
		if (tmp->next->value > max)
			max = tmp->next->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_dlist *list)
{
	int		min;
	t_dlist	*tmp;

	min = INT_MAX;
	tmp = list;
	while (tmp->next->value != -1)
	{
		if (tmp->next->value < min)
			min = tmp->next->value;
		tmp = tmp->next;
	}
	return (min);
}

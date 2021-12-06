/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:10:38 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/05 21:03:18 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	partition1(t_dlist *a, t_dlist *b, t_list *cmd, int pivot)
{
	int	next_index;
	int	tmp_group;
	int	min;

	min = get_min(b);
	tmp_group = a->next->group + 1;
	next_index = above_or_below(b, pivot, false);
	while (next_index > -1)
	{
		while (next_index)
		{
			partition2(a, b, cmd, &min);
			next_index--;
		}
		b->next->group = tmp_group;
		push(a, b);
		ft_lstpush_back(&cmd, PA);
		next_index = above_or_below(b, pivot, false);
	}
}

void	partition2(t_dlist *a, t_dlist *b, t_list *cmd, int *min)
{
	if (b->next->value == *min)
	{
		b->next->group = -1;
		push(a, b);
		ft_lstpush_back(&cmd, PA);
		rotate(a);
		ft_lstpush_back(&cmd, RA);
		(*min)++;
	}
	else
	{
		rotate(b);
		ft_lstpush_back(&cmd, RB);
	}
}

int	above_or_below(t_dlist *list, int pivot, bool is_a)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp->next->value != -1)
	{
		if (is_a)
		{
			if (tmp->next->value < pivot)
				return (i);
		}
		else if (tmp->next->value > pivot)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	is_possible_rotate(t_dlist *a, t_dlist *b, t_list *cmd, int *min)
{
	int	tmp_group;

	tmp_group = a->next->group;
	while (a->next->group == tmp_group && tmp_group != -1)
	{
		if (a->next->value == *min)
			rotate_sort_simple(a, cmd, min);
		else if (a->next->value == *min + 1 && a->next->next->value == *min)
		{
			swap_list(a);
			ft_lstpush_back(&cmd, SA);
			rotate_sort_simple(a, cmd, min);
			rotate_sort_simple(a, cmd, min);
		}
		else
		{
			push(b, a);
			ft_lstpush_back(&cmd, PB);
		}
	}
}

void	rotate_sort_simple(t_dlist *a, t_list *cmd, int *min)
{
	a->next->group = -1;
	(*min)++;
	rotate(a);
	ft_lstpush_back(&cmd, RA);
}

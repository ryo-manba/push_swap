/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:13 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/05 20:58:24 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_pivot(int min, int max)
{
	if ((min + max) % 2)
		return ((min + max) / 2);
	return (((min + max) / 2) + 1);
}

int	push_sort(t_dlist *a, t_dlist *b, t_list *cmd, int pa_times)
{
	int	i;
	int	max_order;

	i = 0;
	max_order = b->next->value;
	if (max_order == -1)
		max_order = a->prev->value;
	while (i < pa_times)
	{
		push(a, b);
		ft_lstpush_back(&cmd, PA);
		i++;
	}
	return (rotate_sort(a, cmd, pa_times, max_order));
}

int	rotate_sort(t_dlist *a, t_list *cmd, int ra_times, int max_order)
{
	int	i;

	i = 0;
	while (i < ra_times)
	{
		a->next->group = -1;
		rotate(a);
		ft_lstpush_back(&cmd, RA);
		i++;
	}
	while (next_rotate_sort(a, cmd, max_order))
		max_order++;
	return (max_order);
}

int	next_rotate_sort(t_dlist *a, t_list *cmd, int max_order)
{
	if (a->next->value == max_order + 1)
	{
		a->next->group = -1;
		rotate(a);
		ft_lstpush_back(&cmd, RA);
		return (1);
	}
	if (a->next->next->value == max_order + 1)
	{
		swap_list(a);
		ft_lstpush_back(&cmd, SA);
		a->next->group = -1;
		rotate(a);
		ft_lstpush_back(&cmd, RA);
		return (1);
	}
	return (0);
}

void	put_cmd(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp->next)
	{
		if (pruning_action(tmp->next->content, tmp->content))
		{
			tmp->content = -1;
			tmp->next->content = -1;
		}
		if ((tmp->next->content == RA && tmp->content == RB) || \
			(tmp->next->content == RB && tmp->content == RA))
		{
			tmp->content = RR;
			tmp->next->content = -1;
		}
		tmp = tmp->next;
	}
	tmp = cmd;
	while (tmp)
	{
		put_action(tmp->content);
		tmp = tmp->next;
	}
}

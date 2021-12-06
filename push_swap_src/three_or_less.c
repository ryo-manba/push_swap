/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_or_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:43:25 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/05 14:37:00 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_or_less(t_dlist *list, t_list *cmd, int sz)
{
	if (sz == 1)
		return ;
	if (sz == 2 && list->next->value < list->next->next->value)
	{
		swap_list(list);
		ft_lstpush_back(&cmd, SB);
	}
	if (sz == 3)
	{
		if ((list->next->next->value < list->next->value) && \
		(list->next->value < list->next->next->next->value))
		{
			rev_rotate(list);
			ft_lstpush_back(&cmd, RRB);
		}
		else if ((list->next->value < list->next->next->next->value) && \
			(list->next->next->next->value < list->next->next->value))
		{
			rotate(list);
			ft_lstpush_back(&cmd, RB);
		}
		else
			three_sort(list, cmd);
	}
}

void	three_sort(t_dlist *list, t_list *cmd)
{
	if ((list->next->value < list->next->next->value) && \
		(list->next->next->value < list->next->next->next->value))
	{
		swap_list(list);
		rev_rotate(list);
		ft_lstpush_back(&cmd, SB);
		ft_lstpush_back(&cmd, RRB);
	}
	else if ((list->next->next->next->value < list->next->value) && \
		(list->next->value < list->next->next->value))
	{
		swap_list(list);
		ft_lstpush_back(&cmd, SB);
	}
	else if ((list->next->next->value < list->next->next->next->value) && \
		(list->next->next->next->value < list->next->value))
	{
		rev_rotate(list);
		swap_list(list);
		ft_lstpush_back(&cmd, RRB);
		ft_lstpush_back(&cmd, SB);
	}
}

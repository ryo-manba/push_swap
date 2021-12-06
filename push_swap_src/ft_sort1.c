/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:32:58 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/05 20:31:04 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_dlist *a, t_dlist *b)
{
	t_list	*cmd;

	cmd = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!cmd)
		exit_fatal(2);
	cmd->content = -1;
	first_separate(a, b, cmd, list_len(a) / 2);
	doc_reverse(a, b, cmd);
	sort_list(a, b, cmd);
	put_cmd(cmd);
	ft_lstclear(&cmd);
}

void	sort_list(t_dlist *a, t_dlist *b, t_list *cmd)
{
	int	b_len;
	int	max;
	int	min;

	b_len = list_len(b);
	while (b_len > 3)
	{
		max = get_max(b);
		min = get_min(b);
		partition1(a, b, cmd, create_pivot(min, max));
		b_len = list_len(b);
	}
	three_or_less(b, cmd, b_len);
	min = push_sort(a, b, cmd, b_len) + 1;
	if (is_sorted(a))
		return ;
	is_possible_rotate(a, b, cmd, &min);
	sort_list(a, b, cmd);
}

void	first_separate(t_dlist *a, t_dlist *b, t_list *cmd, int pivot)
{
	int	next_index;

	next_index = above_or_below(a, pivot, true);
	while (next_index > -1)
	{
		while (next_index > 0)
		{
			rotate(a);
			ft_lstpush_back(&cmd, RA);
			next_index--;
		}
		push(b, a);
		ft_lstpush_back(&cmd, PB);
		if (b->next->value < 3 && list_len(b) > 1)
		{
			rotate(b);
			ft_lstpush_back(&cmd, RB);
		}
		next_index = above_or_below(a, pivot, true);
	}
}

void	doc_reverse(t_dlist *a, t_dlist *b, t_list *cmd)
{
	int	times;
	int	order;

	times = 3;
	order = 0;
	while (times--)
	{
		rev_rotate(b);
		ft_lstpush_back(&cmd, RRB);
		b->next->group = -1;
		while (b->next->value == order)
		{
			push(a, b);
			ft_lstpush_back(&cmd, PA);
			rotate(a);
			ft_lstpush_back(&cmd, RA);
			order++;
		}
	}
	if (order == 1)
		austin_reverse(a, b, cmd);
}

void	austin_reverse(t_dlist *a, t_dlist *b, t_list *cmd)
{
	swap_list(b);
	ft_lstpush_back(&cmd, SB);
	push(a, b);
	ft_lstpush_back(&cmd, PA);
	rotate(a);
	ft_lstpush_back(&cmd, RA);
	push(a, b);
	ft_lstpush_back(&cmd, PA);
	rotate(a);
	ft_lstpush_back(&cmd, RA);
}

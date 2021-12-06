/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:44:15 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/04 16:51:13 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five_or_less(t_dlist *a, t_dlist *b)
{
	t_data	data;
	int		i;

	init_data(&data);
	i = 0;
	dfs(a, b, &data, 0);
	while (i < data.best)
	{
		list_move(data.ans[i], a, b);
		i++;
	}
	put_result(&data);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < MAX_5)
	{
		data->ans[i] = -1;
		data->tmp[i] = -1;
		i++;
	}
	data->best = INT_MAX;
	data->now = -1;
	data->prev = -1;
}

void	dfs(t_dlist *a, t_dlist *b, t_data *data, int depth)
{
	int	action;

	action = -1;
	if (depth >= data->best || depth >= MAX_5)
		return ;
	if (b->next->value == -1 && is_sorted(a))
	{
		data->best = depth;
		while (++action < depth)
			data->ans[action] = data->tmp[action];
		return ;
	}
	action = -1;
	while (++action < 11)
	{
		if (depth >= 1)
			if ((pruning_action(action, data->tmp[depth - 1])))
				continue ;
		if (list_move(action, a, b))
			continue ;
		data->tmp[depth] = action;
		dfs(a, b, data, depth + 1);
		list_move(restore(action), a, b);
	}
}

bool	pruning_action(int now, int prev)
{
	if ((now == PA && prev == PB) || (now == PB && prev == PA) || \
	(now == RA && prev == RRA) || (now == RRA && prev == RA) || \
	(now == RB && prev == RRB) || (now == RRB && prev == RB) || \
	(now == RRR && prev == RR) || (now == RR && prev == RRR) || \
	(now == SA && prev == SA) || (now == SB && prev == SB))
		return (true);
	return (false);
}

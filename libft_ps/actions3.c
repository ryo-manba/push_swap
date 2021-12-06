/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:18:18 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/04 17:00:36 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	restore(int action)
{
	if (action == PA)
		return (PB);
	if (action == PB)
		return (PA);
	if (action == RA)
		return (RRA);
	if (action == RB)
		return (RRB);
	if (action == RR)
		return (RRR);
	if (action == RRA)
		return (RA);
	if (action == RRB)
		return (RB);
	if (action == RRR)
		return (RR);
	return (action);
}

bool	list_move(int action, t_dlist *a, t_dlist *b)
{
	if (action == SA)
		return (swap_list(a));
	if (action == SB)
		return (swap_list(b));
	if (action == SS)
		return (double_swap(a, b));
	if (action == PA)
		return (push(a, b));
	if (action == PB)
		return (push(b, a));
	if (action == RA)
		return (rotate(a));
	if (action == RB)
		return (rotate(b));
	if (action == RR)
		return (double_rotate(a, b));
	if (action == RRA)
		return (rev_rotate(a));
	if (action == RRB)
		return (rev_rotate(b));
	if (action == RRR)
		return (double_rev_rotate(a, b));
	return (false);
}

void	put_action(int action)
{
	if (action == SA)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	if (action == SB)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	if (action == SS)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	if (action == PA)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	if (action == PB)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	if (action == RA)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	if (action == RB)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	if (action == RR)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	if (action == RRA)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	if (action == RRB)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	if (action == RRR)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	put_result(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->best)
		put_action(data->ans[i]);
}

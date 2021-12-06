/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:38:53 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/11 07:32:19 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_len(t_dlist *list)
{
	int		len;
	t_dlist	*tmp;

	tmp = list;
	len = 0;
	while (tmp->next->value != -1)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	list_clear(t_dlist **list)
{
	t_dlist	*tmp;

	if (!list)
		return ;
	(*list)->prev->next = NULL;
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

bool	is_sorted(t_dlist *list)
{
	t_dlist	*tmp;

	tmp = list;
	while (tmp->next->value != -1)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_dlist	*create_list(void)
{
	t_dlist	*dlist;

	dlist = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (!dlist)
		exit_fatal(2);
	dlist->value = -1;
	dlist->group = -1;
	dlist->dummy = 1;
	dlist->next = dlist;
	dlist->prev = dlist;
	return (dlist);
}

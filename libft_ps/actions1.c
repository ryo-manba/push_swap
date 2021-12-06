/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:25:53 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/04 16:59:51 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rotate(t_dlist *list)
{
	t_dlist	*p;
	t_dlist	*n1;
	t_dlist	*n2;

	if (list->next->next->value == -1)
		return (true);
	p = list->prev;
	n1 = list->next;
	n2 = list->next->next;
	list->next = n2;
	n2->prev = list;
	list->prev = n1;
	n1->prev = p;
	p->next = n1;
	n1->next = list;
	return (false);
}

bool	double_rotate(t_dlist *a, t_dlist *b)
{
	bool	ans1;
	bool	ans2;

	ans1 = rotate(a);
	ans2 = rotate(b);
	if (ans1 && ans2)
		return (true);
	return (false);
}

bool	swap_list(t_dlist *list)
{
	t_dlist	*n1;
	t_dlist	*n2;
	t_dlist	*n3;

	if (list->next->next->value == -1)
		return (true);
	n1 = list->next;
	n2 = list->next->next;
	n3 = list->next->next->next;
	list->next = n2;
	n2->next = n1;
	n1->next = n3;
	n3->prev = n1;
	n1->prev = n2;
	n2->prev = list;
	return (false);
}

bool	double_swap(t_dlist *a, t_dlist *b)
{
	bool	ans1;
	bool	ans2;

	ans1 = swap_list(a);
	ans2 = swap_list(b);
	if (ans1 && ans2)
		return (true);
	return (false);
}

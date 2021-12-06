/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 07:50:39 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/31 08:34:18 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rev_rotate(t_dlist *list)
{
	t_dlist	*n;
	t_dlist	*p1;
	t_dlist	*p2;

	if (list->next->next->value == -1)
		return (true);
	n = list->next;
	p1 = list->prev;
	p2 = list->prev->prev;
	list->next = p1;
	p1->next = n;
	n->prev = p1;
	p1->prev = list;
	list->prev = p2;
	p2->next = list;
	return (false);
}

bool	double_rev_rotate(t_dlist *a, t_dlist *b)
{
	bool	ans1;
	bool	ans2;

	ans1 = rev_rotate(a);
	ans2 = rev_rotate(b);
	if (ans1 && ans2)
		return (true);
	return (false);
}

bool	push(t_dlist *list1, t_dlist *list2)
{
	t_dlist	*list1_n;
	t_dlist	*list2_n1;
	t_dlist	*list2_n2;

	if (list2->next->value == -1)
		return (true);
	list1_n = list1->next;
	list2_n1 = list2->next;
	list2_n2 = list2->next->next;
	list2->next = list2_n2;
	list2_n2->prev = list2;
	list1->next = list2_n1;
	list2_n1->next = list1_n;
	list1_n->prev = list2_n1;
	list2_n1->prev = list1;
	return (false);
}

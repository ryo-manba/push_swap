/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:18:40 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/04 21:28:49 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	a = make_dlist(argc - 1, argv);
	if (is_sorted(a))
	{
		list_clear(&a);
		return (0);
	}
	b = create_list();
	if (argc - 1 <= 5)
		five_or_less(a, b);
	else
		ft_sort(a, b);
	list_clear(&a);
	list_clear(&b);
	return (0);
}

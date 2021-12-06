/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:51:20 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/11 07:32:38 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlist	*make_dlist(int sz, char **argv)
{
	int		sorted[STACK_MAX];
	int		i;
	t_dlist	*list;

	list = create_list();
	i = -1;
	while (++i < sz)
	{
		sorted[i] = ft_atoi_ps(argv[i + 1]);
		dlist_add_back(list, sorted[i]);
	}
	quick_sort(sorted, 0, sz - 1);
	check_overlapping(sorted, sz);
	apply_order(list, sorted);
	return (list);
}

void	dlist_add_back(t_dlist *list, int value)
{
	t_dlist	*new_list;
	t_dlist	*tmp;

	new_list = (t_dlist *)ft_calloc(1, sizeof(t_dlist));
	if (!new_list)
		exit_fatal(2);
	new_list->value = value;
	new_list->dummy = 0;
	tmp = list->prev;
	tmp->next = new_list;
	new_list->next = list;
	list->prev = new_list;
	new_list->prev = tmp;
}

void	check_overlapping(int num[], int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < size)
	{
		if (num[i] == num[j])
			exit_fatal(1);
		i++;
		j++;
	}
}

void	apply_order(t_dlist *list, int sorted[])
{
	t_dlist	*tmp;
	int		i;

	tmp = list;
	tmp = tmp->next;
	while (tmp->dummy != 1)
	{
		i = 0;
		while (sorted[i] != tmp->value)
			i++;
		tmp->value = i;
		tmp = tmp->next;
	}
}

int	ft_atoi_ps(char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	if (ft_strlen(s) == 0)
		exit_fatal(1);
	while (ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (n - 1) > INT_MAX))
			exit_fatal(1);
		s++;
	}
	if (*s)
		exit_fatal(1);
	n *= sign;
	return (n);
}

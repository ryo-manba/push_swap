/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:18:34 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/08 07:38:31 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checker(int argc, char **argv)
{
	t_dlist		*a;
	t_dlist		*b;
	t_info		*info;
	t_info		*head;

	a = make_dlist(argc - 1, argv);
	b = create_list();
	info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!info)
		exit_fatal(2);
	head = info;
	info->ret = get_next_line(0, &info->ans);
	while (info->ret == 1)
	{
		run_action(info, a, b);
		info_addback(info);
		info = info->next;
		info->ret = get_next_line(0, &info->ans);
	}
	if (info->ret == -1)
		exit_fatal(1);
	put_result_and_free(a, b, head);
	return (0);
}

void	put_result_and_free(t_dlist *a, t_dlist *b, t_info *info)
{
	if (is_sorted(a) && list_len(b) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	list_clear(&a);
	list_clear(&b);
	info_clear(&info);
}

void	run_action(t_info *info, t_dlist *a, t_dlist *b)
{
	if (!(ft_strcmp(info->ans, "sa")))
		swap_list(a);
	else if (!(ft_strcmp(info->ans, "sb")))
		swap_list(b);
	else if (!(ft_strcmp(info->ans, "ss")))
		double_swap(a, b);
	else if (!(ft_strcmp(info->ans, "pa")))
		push(a, b);
	else if (!(ft_strcmp(info->ans, "pb")))
		push(b, a);
	else if (!(ft_strcmp(info->ans, "ra")))
		rotate(a);
	else if (!(ft_strcmp(info->ans, "rb")))
		rotate(b);
	else if (!(ft_strcmp(info->ans, "rr")))
		double_rotate(a, b);
	else if (!(ft_strcmp(info->ans, "rra")))
		rev_rotate(a);
	else if (!(ft_strcmp(info->ans, "rrb")))
		rev_rotate(b);
	else if (!(ft_strcmp(info->ans, "rrr")))
		double_rev_rotate(a, b);
	else
		exit_fatal(1);
}

void	info_clear(t_info **info)
{
	t_info	*tmp;

	if (!info)
		return ;
	while (*info)
	{
		tmp = (*info)->next;
		free((*info)->ans);
		free(*info);
		*info = tmp;
	}
}

void	info_addback(t_info *info)
{
	t_info	*new_info;

	new_info = (t_info *)ft_calloc(1, sizeof(t_info));
	if (!new_info)
		exit_fatal(2);
	info->next = new_info;
	new_info->next = NULL;
}

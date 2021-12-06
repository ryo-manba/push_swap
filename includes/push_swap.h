/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:18:44 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/08 07:38:06 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define STACK_MAX 10000
# define MAX_5 12

typedef struct s_info
{
	char			*ans;
	int				ret;
	struct s_info	*next;
}				t_info;

typedef struct s_dlist
{
	int				value;
	int				dummy;
	int				group;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dlist;

typedef struct s_data
{
	int		best;
	int		now;
	int		prev;
	int		ans[MAX_5];
	int		tmp[MAX_5];
}				t_data;

typedef enum e_actions
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_actions;

/* checker */
int		checker(int argc, char **argv);
void	put_result_and_free(t_dlist *a, t_dlist *b, t_info *info);
void	run_action(t_info *data, t_dlist *a, t_dlist *b);
void	info_clear(t_info **info);
void	info_addback(t_info *info);

/* actions1 */
bool	rotate(t_dlist *list);
bool	double_rotate(t_dlist *a, t_dlist *b);
bool	swap_list(t_dlist *list);
bool	double_swap(t_dlist *a, t_dlist *b);

/* actions2 */
bool	rev_rotate(t_dlist *list);
bool	double_rev_rotate(t_dlist *a, t_dlist *b);
bool	push(t_dlist *list1, t_dlist *list2);

/* actions3 */
int		restore(int action);
bool	list_move(int action, t_dlist *a, t_dlist *b);
void	put_action(int action);
void	put_result(t_data *data);

/* exit_fatal */
void	exit_fatal(int	n);

/* make_dlist */
int		ft_atoi_ps(char *s);
void	dlist_add_back(t_dlist *list, int value);
void	check_overlapping(int num[], int size);
void	apply_order(t_dlist *list, int sorted[]);
t_dlist	*make_dlist(int argc, char **argv);

/* push_swap */
int		push_swap(int argc, char **argv);

/* quick_sort */
void	ft_swap(int *x, int *y);
void	quick_sort(int *array, int left, int right);

/* utils1 */
int		list_len(t_dlist *list);
bool	is_sorted(t_dlist *list);
void	list_clear(t_dlist **list);
t_dlist	*create_list(void);

/* utils2 */
int		get_max(t_dlist *list);
int		get_min(t_dlist *list);

/* ft_sort1 */
void	ft_sort(t_dlist *a, t_dlist *b);
void	sort_list(t_dlist *a, t_dlist *b, t_list *cmd);
void	doc_reverse(t_dlist *a, t_dlist *b, t_list *cmd);
void	austin_reverse(t_dlist *a, t_dlist *b, t_list *cmd);
void	first_separate(t_dlist *a, t_dlist *b, t_list *cmd, int pivot);

/* ft_sort2 */
int		above_or_below(t_dlist *list, int pivot, bool is_a);
void	partition1(t_dlist *a, t_dlist *b, t_list *cmd, int pivot);
void	partition2(t_dlist *a, t_dlist *b, t_list *cmd, int *min);
void	is_possible_rotate(t_dlist *a, t_dlist *b, t_list *cmd, int *min);
void	rotate_sort_simple(t_dlist *a, t_list *cmd, int *min);

/* ft_sort3 */
int		create_pivot(int min, int max);
int		push_sort(t_dlist *a, t_dlist *b, t_list *cmd, int ret);
int		rotate_sort(t_dlist *a, t_list *cmd, int len, int max_order);
int		next_rotate_sort(t_dlist *a, t_list *cmd, int max_order);
void	put_cmd(t_list *cmd);

/* three_or_less */
void	three_or_less(t_dlist *list, t_list *cmd, int sz);
void	three_sort(t_dlist *list, t_list *cmd);

/* five_or_less */
bool	pruning_action(int now, int prev);
void	five_or_less(t_dlist *a, t_dlist *b);
void	init_data(t_data *data);
void	dfs(t_dlist *a, t_dlist *b, t_data *data, int depth);

#endif
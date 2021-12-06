/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 22:08:36 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/02 22:22:15 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list **lst, int value)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = ft_lstnew(value);
	else
	{
		last = ft_lstlast(*lst);
		if (last != NULL)
			last->next = ft_lstnew(value);
	}
}

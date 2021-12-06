/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fatal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:07:59 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/06/05 17:32:39 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_fatal(int n)
{
	if (n == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (n == 2)
		ft_putstr_fd("Malloc Error\n", STDERR_FILENO);
	if (n == 3)
		ft_putstr_fd("Too many args\n", STDERR_FILENO);
	exit(1);
}

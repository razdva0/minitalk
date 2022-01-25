/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:41:40 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/18 13:41:42 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static int	pass_chr(pid_t pid, char c)
{
	int	status;
	int	bit;
	int	i;

	status = 0;
	i = 0;
	bit = 1;
	while (i < 8)
	{
		status = kill(pid, ((c & bit) >> i) + 30);
		if (status == -1)
			return (-1);
		bit <<= 1;
		i++;
		usleep(100);
	}
	return (status);
}

static void	pass_msg(pid_t pid, char *msg)
{
	int	status;
	int	i;

	i = 0;
	while (msg[i])
	{
		status = pass_chr(pid, msg[i]);
		if (status == -1)
		{
			ft_putstr_fd("Error! Bad signal, stop execution...\n", 2);
			return ;
		}
		i++;
	}
	status = pass_chr(pid, msg[i]);
	if (status == -1)
	{
		ft_putstr_fd("Error! Bad signal, stop execution...\n", 2);
		return ;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("Error! Correct format: ./client [PID] [MSG]\n", 2);
		return (1);
	}
	else
		pass_msg(ft_atoi(av[1]), av[2]);
	return (0);
}

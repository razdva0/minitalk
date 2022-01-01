/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:41:46 by mtitan            #+#    #+#             */
/*   Updated: 2021/11/18 13:41:48 by mtitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	listen(void)
{
	while (1)
	{
		pause();
		if (g_ch.bit == 8)
		{
			if (g_ch.ch == '\0')
				ft_putchar_fd('\n', 1);
			else
				ft_putchar_fd(g_ch.ch, 1);
			g_ch.bit = 0;
			g_ch.ch = 0;
		}
	}
}

static void	msg_1(int signum)
{
	if (signum == SIGUSR1)
		g_ch.bit++;
}

static void	msg_2(int signum)
{
	if (signum == SIGUSR2)
	{
		g_ch.ch ^= 1 << g_ch.bit;
		g_ch.bit++;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	g_ch.bit = 0;
	g_ch.ch = 0;
	ft_putstr_fd("Process is running... PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, msg_1);
	signal(SIGUSR2, msg_2);
	listen();
}

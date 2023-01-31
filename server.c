/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:58:00 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/31 01:34:33 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < y)
	{
		j *= x;
		i++;
	}
	return (j);
}

int	array[8];
// 76543210
// 01000001
/*
	1 * 2^0+
	0 * 2^1+
	.
	.
	1 * 2^6
	pow(2, 6)
*/

void	handler(int a, siginfo_t *info, void *uap)
{
	static int		i;
	int				res;
	int				j;
	(void)			uap;
	static pid_t	n;

	if (n != info->si_pid)
	{
		i = 0;
		n = info->si_pid;
	}
	array[i++] = a - SIGUSR1;
	res = 0;
	if (i == 8)
	{
		i = 0;
		j = 0;
		while(j < 8)
		{
			res += (array[j]) * ft_pow(2, j);
			j++;
		}
		write(1, &res, 1);
	}
}

int	main()
{
	int	pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	struct sigaction	sa;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}

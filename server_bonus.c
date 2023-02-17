/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:39:34 by aziyani           #+#    #+#             */
/*   Updated: 2023/02/17 20:06:19 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_pow(int x, int y)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while(i < y)
    {
        j *= x;
        i++;
    }
    return (j);
}

int g_array[32];

void	handler(int a, siginfo_t *info, void *uap)
{
	static int		i;
	int				res;
	int				j;
	static pid_t	n;

	(void) uap;
	if (n != info->si_pid)
	{
		i = 0;
		n = info->si_pid;
	}
	g_array[i++] = a - SIGUSR1;
	res = 0;
	if (i == 32)
	{
		i = 0;
		j = 0;
		while (j < 32)
		{
			res += (g_array[j]) * ft_pow(2, j);
			j++;
		}
		write(1, &res, 1);
        kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%i\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}

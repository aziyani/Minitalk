/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:16:39 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/21 15:23:03 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// ---------------------------------------------------------

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

// ----------------------------------------------------------

int array[32];
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

void handler(int a, siginfo_t *info, void *uap)
{
	int g;
	static int i;
	int some;
	int j;
	(void) uap;
	static pid_t n;
	int b;
	
	b = 0;
	if(n == 0)
		n = info->si_pid;
	
	if(n != info->si_pid)
	{
	// 	while(b < 8)
	// 	{
	// 		array[b] = 0;
	// 		b++;
	// 	}
		i = 0;
		n = 0;
	}

	
	if(a == SIGUSR1)
		g = 0;
	if(a == SIGUSR2)
		g = 1;
	array[i++] = g;
	some = 0;
	if (i == 32)
	{
		i = 0;
		j = 0;
		while(j < 32)
		{
			some += (array[j]) * ft_pow(2, j);
			j++;
		}
		if(some == 0)
			kill(n, SIGUSR1);
		write(1, &some, 1);
	}
}

// -------------------------------------------------------------

int main()
{
	int pid;

	pid = getpid();
	ft_printf("%i\n", pid);
	struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	return (0);
}
// --------------------------------------------------------------

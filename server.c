/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:24:08 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/17 20:32:11 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <math.h>

char array[8];
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
void print(int a)
{
	int g;
	static int i;
	int some;
	int j;
	
	if(a == SIGUSR1)
		g = '0';
	if(a == SIGUSR2)
		g = '1';
	array[i++] = g;
	some = 0;
	if (i == 8)
	{
		i = 0;
		j = 0;
		while(j < 8)
		{
			some += (array[j] - '0') * pow(2, j);
			j++;
		}
		printf("%c\n", some);
	}
}

int main()
{
	int pid;

	pid = getpid();
	printf("%i\n", pid);
	while(1)
	{
		signal(SIGUSR1, print);    
		signal(SIGUSR2, print);
		pause();
	}
	
	
	return (0);
}
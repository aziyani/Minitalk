/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:13:19 by aziyani           #+#    #+#             */
/*   Updated: 2023/02/17 22:12:40 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signe);
}

void	ft_full(char *s)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		s[i] = '0';
		i++;
	}
}

void	conv_t_b_send(int pid, unsigned char c)
{
	int		i;
	char	s[8];

	i = 0;
	ft_full(s);
	while (c)
	{
		s[i] = (c % 2) + 48;
		c = c / 2;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (s[i] == '0')
			kill(pid, SIGUSR1);
		if (s[i] == '1')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	check_digit(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 2)
		return (0);
	if (!(check_digit(argv[1])))
		return (0);
	if (ft_atoi(argv[1]) == -1)
	{
		write(1, "ikhan\n", 7);
		exit(1);
	}
	if (argc == 3)
	{
		while (argv[2][i])
		{
			conv_t_b_send(ft_atoi(argv[1]), (argv[2][i]));
			i++;
		}
	}
	return (0);
}

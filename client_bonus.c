/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:16:25 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/21 16:37:12 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// -----------------------------------------------------------------------
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
// -------------------------------------------------------------------------
void conv_t_b_send(int pid, unsigned char c)
{
    int i;
    char s[32];
    
    i = 0;
    while (i < 32)
    {
        s[i] = '0';
        i++;
    }
    i = 0;
    while (c)
    {
        s[i] = (c % 2) + 48;
        
        c = c / 2;
        i++;
    }
    i = 0;
    while (i < 32)
    {
        if (s[i] == '0')
            kill(pid, SIGUSR1);
        if(s[i] == '1')
            kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}
// ---------------------------------------------------------------------------

void handler(int a)
{
    (void)a;
    ft_printf("done");
}

// ---------------------------------------------------------------------------
int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)
    {
        signal(SIGUSR1, &handler);
        while (i <= strlen(argv[2]))
        {
            conv_t_b_send(ft_atoi(argv[1]), (unsigned char)(argv[2][i]));
            i++;
        }
    }
    return (0);
}
// ------------------------------------------------------------------------------

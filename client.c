/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziyani <aziyani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:24:00 by aziyani           #+#    #+#             */
/*   Updated: 2023/01/17 20:22:56 by aziyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void convert_tob_send(int pid, int c)
{
    int i;
    char s[8];
    
    i = 0;
    while (i < 8)
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
    while (i < 8)
    {
        if (s[i] == '0')
        {
            if(kill(pid, SIGUSR1) == -1)
                printf("yeah");
        }
        else if(s[i] == '1')
        {
            if (kill(pid, SIGUSR2) == -1)
                printf("yeah");
        }
        usleep(100);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)
    {
        while (argv[2][i])
        {
            // printf("%i", argv);
            convert_tob_send(atoi(argv[1]), argv[2][i]);
            i++;
        }
    }
    return (0);
}
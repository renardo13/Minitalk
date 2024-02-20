/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:03:13 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/20 17:50:49 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver;

int	is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			exit(ft_printf("STOP, INVALID PID.\n"));
		i++;
	}
	return (1);
}

void	ft_communication(int sig, siginfo_t *info, void *ucontext)
{
	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		g_receiver = 1;
	if (sig == SIGUSR2)
		ft_printf("SERVER : RECEIVE 5/5 👍 \n");
}

int	ft_send_char(char c, int pid)
{
	int	j;
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j = 0;
		i--;
		usleep(800);
		while (g_receiver == 0 && c != '\0')
		{
			j++;
			if ((long)j > 1000000000)
				exit(ft_printf("SERVER TIME OUT\n"));
		}
		g_receiver = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char				*s;
	int					pid;
	int					i;
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_flags = 0;
		sa.sa_sigaction = &ft_communication;
		sigemptyset(&sa.sa_mask);
		s = av[1];
		if (is_digit(av[2]))
			pid = atoi(av[2]);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(-1);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(-1);
		i = 0;
		while (s[i])
		{
			ft_send_char(s[i], pid);
			i++;
		}
		ft_send_char('\0', pid);
	}
}

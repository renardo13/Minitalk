/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:29 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/20 17:34:11 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_reconstitute(char *c, siginfo_t *info)
{
	static char	*s;

	if (*c == '\0')
	{
		ft_printf("%s\n", s);
		kill(info->si_pid, SIGUSR2);
		free(s);
		s = NULL;
		return ;
	}
	if (!s)
		s = ft_strdup(c);
	else
		s = ft_strjoin(s, c);
}

void	ft_sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;

	(void)info;
	(void)ucontext;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_reconstitute(&c, info);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_sig_handler;
	sigemptyset(&sa.sa_mask);
	ft_printf("Hello, my PID is : %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(-1);
	while (1)
	{
		pause();
	}
	return (0);
}

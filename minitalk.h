/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:19:23 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/19 14:00:41 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// client fonctions

int		ft_send_char(char c, int pid);

// server fonctions

void	ft_sig_handler(int sig, siginfo_t *info, void *ucontext);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_atoi(const char *s);

#endif
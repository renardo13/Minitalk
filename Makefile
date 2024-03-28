# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 14:07:00 by melmarti          #+#    #+#              #
#    Updated: 2024/02/19 17:02:31 by melmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g3

SRC_C = client.c ft_atoi.c
SRC_S = server.c ft_strjoin.c ft_strdup.c
FT_PRINTF = ft_printf/ft_printf.a
		
OBJ_C = $(SRC_C:.c=.o) $(FT_PRINTF)
OBJ_S = $(SRC_S:.c=.o) $(FT_PRINTF)

NAME_C = client 
NAME_S = server

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJ_C)
	$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C)

$(NAME_S): $(OBJ_S)
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJ_S)
	
$(FT_PRINTF):
	make -C ft_printf

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re 
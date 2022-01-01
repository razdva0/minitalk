# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtitan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 13:41:33 by mtitan            #+#    #+#              #
#    Updated: 2021/11/18 13:41:34 by mtitan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
CLIENT_SRC	= ft_client.c
CLIENT_OBJ	= $(addprefix obj/, $(CLIENT_SRC:.c=.o))

SERVER		= server
SERVER_SRC	= ft_server.c
SERVER_OBJ	= $(addprefix obj/, $(SERVER_SRC:.c=.o))

UTILS_SRC	= ft_utils.c
UTILS_OBJ	= $(addprefix obj/, $(UTILS_SRC:.c=.o))

FLAGS		= -Wall -Wextra -Werror

.PHONY		: all clean fclean re

all			: obj/ $(UTILS_OBJ) $(CLIENT) $(SERVER)

obj/ :
	@mkdir obj/

$(CLIENT)	: $(CLIENT_OBJ)
	gcc $(FLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT)

$(SERVER)	: $(SERVER_OBJ)
	gcc $(FLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER)

obj/%.o		: %.c ft_minitalk.h
	@gcc $(FLAGS) -c $< -o $@

clean		:
	rm -rf obj/

fclean		: clean
	rm -rf $(CLIENT) $(SERVER)

re			: fclean all

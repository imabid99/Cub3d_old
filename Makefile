# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imabid <imabid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 11:20:17 by imabid            #+#    #+#              #
#    Updated: 2022/06/08 15:13:07 by imabid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
LIB =  -lm -lmlx -framework OpenGL -framework AppKit 
# CC_FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =  cub3d.c \
		lets_draw.c \
		lets_init.c \
		lines_draw.c 


OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)

%.o: %.c *.h
	$(CC) $(CC_FLAGS)  -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CC_FLAGS)  $^ -o $@ $(LIB)



clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all
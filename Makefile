##
## Makefile for  in /home/planch_j/rendu/CPE_2015_Pushswap
## 
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
## 
## Started on  Thu Nov 19 19:30:15 2015 Jean PLANCHER
## Last update Fri Dec 18 00:06:04 2015 Jean PLANCHER
##

CC	= cc

RM	= rm -f

CFLAGS	+= -W -Wall -Werror -ansi -pedantic
CFLAGS	+= -I./include/

NAME	= bsq

SRCS	= my_bsq.c \
	  functions1.c \
	  functions2.c \
	  functions3.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

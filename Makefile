##
## Makefile for pushswap in /home/wyzlic_a
##
## Made by Dimitri Wyzlic
## Login   <wyzlic_a@epitech.net>
##
## Started on  Thu Apr 21 15:01:37 2016 Dimitri Wyzlic
## Last update Sun Aug 21 03:23:12 2016 wyzlic_a
##

NAME	= tetris

SRC	= src/main.c \
	  src/get_next_line.c \
	  src/my_getnbr.c \
	  src/my_putchar.c \
	  src/my_putstr.c \
	  src/my_strlen.c \
	  src/parse_tetri.c \
	  src/str_to_tab.c \
	  src/read_dir.c \
	  src/concastr.c \
	  src/print_tetriminos.c \
	  src/gen_shape.c \
	  src/is_equal.c \
	  src/main_opt.c \
	  src/print_debug.c \
	  src/my_put_nbr.c \
	  src/pickopt.c \
	  src/help.c \
	  src/is_in.c \
	  src/create_grid.c \
	  src/error.c \
	  src/time.c \
	  src/init_screen.c \
	  src/gen_new_shape.c \
	  src/print_map.c \
	  src/print_scores.c \
	  src/putigrid.c \
	  src/fall_tetris.c \
	  src/handle_keys.c \
	  src/check_lines.c \
	  src/pause.c \
	  src/make_turn.c \
	  src/cp_tetrimino.c \
	  src/color.c \
	  src/key_default.c \
	  src/fix_key.c \
	  src/purge_null.c \
	  src/purge_null_norme.c \
	  src/check_error.c \
	  src/main_loop.c

OBJ	= $(SRC:.c=.o)

CFLAGS = -g -Wall -Werror -I inc -ggdb -g3

all	: $(NAME)

$(NAME)	: $(OBJ)
	cc $(OBJ) -o $(NAME) -lncurses

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all

check-syntax:
	gcc -I inc -W -Wall -Werror -o nul -S ${CHK_SOURCES}

.PHONY :	all clean fclean re

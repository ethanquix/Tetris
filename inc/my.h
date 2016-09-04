/*
** my.h for my_ls in /home/wyzlic_a/.live-packs/wyzlic_a-pack
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Apr 27 15:42:14 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:58:40 2016 wyzlic_a
*/

#include <dirent.h>
#include <ncurses.h>
#include <stdio.h>

#ifndef MY_H_
# define MY_H_

# define BUFF_SIZE 4096

typedef struct	s_tmino
{
char		*name;
int del;
int		h;
int		w;
int		color;
char		**grid;
}		t_mino;

typedef struct	s_ll
{
t_mino		**tab;
struct s_ll	*next;
}		t_ll;

typedef struct	s_opt
{
  WINDOW	*w;
  char		**base_keys;
  int		level;
  int		kleft;
  int		kright;
  int		kturn;
  int		kdrop;
  int		kexit;
  int		kpause;
  int		*gsize;
  char		hide;
  int		debug;
  int		**grid;
  int		**grid_temp;
  int		hscore;
  int		score;
  int		lines;
  long int	time_start;
  int		time_min;
  int		time_sec;
  t_mino	**tcur;
  t_mino	**tnext;
  int		curpos;
  int		curx;
  int		cury;
  int		posay;
  int		stop;
  int		max_list;
  int		refresh;
  int		wait;
  int		nb_tetris;
  int		dellines;
}		t_opt;

void	my_putchar(char);
void	my_putstr(char *);
int	my_getnbr(char *);
char	**strtab(char *, int *);
char	**strtab_char(char *, char);
int	my_strlen(char *);
t_mino	*parse_file(int, int);
t_ll	*round_files(t_opt *, DIR *, int, char *);
int	is_in(char *, char *);
char	*my_conca(char *, char *);
void	print_tetriminos(t_mino **);
t_mino	**get_shape(t_mino *);
void	mprint_tetri(t_ll *);
t_opt	*main_opt(t_opt *, int, char**);
int	iseq(char *, char *);
int	isinopt(char *, char *);
char	pickopt(char *, char *);
void	print_dbg(t_opt *, t_ll *);
int	my_putnbr(int);
int	help(char **, int);
int	*pickgsize(char *);
int	**make_grid(int, int);
int	merror(char *, int);
int	init_scr(t_opt *);
int	print_map(t_opt *, int, int);
void	print_border_map(int, int, int, int);
void	get_time(t_opt *);
int	len_llist(t_ll *);
t_mino	**gen_new_shape(t_opt *, t_ll *);
char	*mitc(int);
void	print_one_tetri(t_mino *, int, int);
int	main_loop(t_opt *, t_ll *, int, int);
void	print_all_ui(t_opt *);
int	put_in_grid(t_opt *, t_mino *);
void	fall_tetris(t_opt *, t_mino *, int , int);
int	handle_keys(t_opt *, int);
void	blit_tetris(t_opt *, t_mino *, int, int);
int	**check_lines(t_opt **, int **, int, int);
int	make_pause(t_opt *);
int	make_turn(t_opt *);
t_mino	**cp_tetri(t_mino **);
void	minit_color();
char	**set_def_keys(char **);
void	fix_key(t_opt *);
t_ll	*purge_ll(t_ll *, int);
t_ll	*add_ll(t_ll *, t_mino **);
t_ll	*sort_alpha(t_ll *);
int	check_error_key(t_opt *);
t_ll	*pre_round_files(t_opt *);
t_ll	*del_ll(t_ll *, int);
int	is_bigger(char *, char *);

#endif /* !MY_H_ */

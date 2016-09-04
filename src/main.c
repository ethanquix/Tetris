/*
** main.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jul 27 16:15:18 2016 Dimitri Wyzlic
** Last update Sun Aug 21 04:03:40 2016 wyzlic_a
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"
#include "ntm.h"

char	*init_kp()
{
  char	*out;

  out = malloc(sizeof(char) * 6);
  if (out == NULL)
    return (NULL);
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  out[3] = 0;
  out[4] = 0;
  out[5] = 0;
  return (out);
}

t_opt	*fill_opt(t_opt *opt, char **env)
{
  if (opt == NULL)
    return (NULL);
  opt->base_keys = set_def_keys(env);
  if (opt->base_keys == NULL)
    return (NULL);
  opt->level = 1;
  opt->kleft = 0;
  opt->kright = 0;
  opt->kturn = 0;
  opt->kdrop = 0;
  opt->kexit = 0;
  opt->kpause = 0;
  opt->gsize = malloc(sizeof(int) * 2);
  if (opt->gsize == NULL)
    return (NULL);
  opt->gsize[0] = 20;
  opt->gsize[1] = 10;
  opt->hide = 1;
  opt->debug = 0;
  return (opt);
}

void	fill_score(t_opt *opt)
{
  opt->hscore = 100;
  opt->score = 0;
  opt->lines = opt->gsize[0];
}

int	main_norme(char **str, char **env, t_ll **all, t_opt **opt)
{
  if ((*opt)->gsize == NULL || *opt == NULL)
    return (1);
  (*opt)->gsize[0] = ((*opt)->gsize[0] > 0) ? (*opt)->gsize[0] : 20;
  (*opt)->gsize[1] = ((*opt)->gsize[1] > 0) ? (*opt)->gsize[1] : 10;
  (*opt)->grid = make_grid((*opt)->gsize[0], (*opt)->gsize[1]);
  if ((*opt)->grid == NULL)
    return (1);
  (*opt)->level = ((*opt)->level < 0) ? 1 : (*opt)->level;
  if (check_term((*opt)->gsize[0], (*opt)->gsize[1] + 20) == 1)
    return (1);
  if (check_error_key(*opt) == 1)
    return (1);
  if ((*opt)->debug == 1)
    print_dbg(*opt, *all);
  fix_key(*opt);
  *all = purge_ll((*all), 0);
  if ((*all) == NULL)
    return (1);
  (*opt)->max_list = len_llist(*all);
  if ((*opt)->max_list == 0)
    return (1);
  (*opt)->tcur = gen_new_shape(*opt, *all);
  (*opt)->tnext = gen_new_shape(*opt, *all);
  opt->dellines = 1;
  return (0);
}

int	main(int nb, char **str, char **env)
{
  t_ll	*all;
  t_opt	*opt;

  srand(time(NULL));
  opt = malloc(sizeof(t_opt));
  if (opt == NULL || (opt = fill_opt(opt, env)) == NULL)
    return (1);
  all = pre_round_files(opt);
  if (help(str, nb) == 1)
    return (0);
  if (nb > 1 && str != NULL)
    opt = main_opt(opt, nb, str);
  if (main_norme(str, env, &all, &opt) != 0)
    return (1);
  if (opt->tcur == NULL || opt->tnext == NULL)
    return (1);
  opt->posay = 0;
  opt->stop = 0;
  opt->refresh = 1;
  opt->posay = 1;
  opt->time_start = time(NULL);
  opt->tcur = NULL;
  if (init_scr(opt) == 1)
    return (1);
  return (main_loop(opt, all, 0, ERR));
}

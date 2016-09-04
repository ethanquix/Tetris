/*
** main.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jul 27 16:15:18 2016 Dimitri Wyzlic
** Last update Sat Aug 20 23:48:55 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

int	check_error_key(t_opt *opt)
{
  if (opt->kleft == -66)
    return (merror("Invalid parameter\n", 1));
  if (opt->kright == -66)
    return (merror("Invalid parameter\n", 1));
  if (opt->kturn == -66)
    return (merror("Invalid parameter\n", 1));
  if (opt->kdrop == -66)
    return (merror("Invalid parameter\n", 1));
  if (opt->kexit == -66)
    return (merror("Invalid parameter\n", 1));
  if (opt->kpause == -66)
    return (merror("Invalid parameter\n", 1));
  return (0);
}

void	fix_key(t_opt *opt)
{
  if (opt->kleft == 0)
    opt->kleft = KEY_LEFT;
  if (opt->kright == 0)
    opt->kright = KEY_RIGHT;
  if (opt->kturn == 0)
    opt->kturn = ' ';
  if (opt->kdrop == 0)
    opt->kdrop = 'x';
  if (opt->kexit == 0)
    opt->kexit = 'q';
  if (opt->kpause == 0)
    opt->kpause = 'p';
}

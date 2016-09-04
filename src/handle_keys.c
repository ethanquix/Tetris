/*
** handle_keys.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Aug 12 14:58:07 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:53:44 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

int	apply_key_side(t_opt *opt, t_mino *mino,  int dir)
{
  int	i;
  int	j;

  i = 0;
  if (((opt->cury + dir) < 0) || ((opt->cury + dir) >= opt->gsize[1]))
    return (0);
  while (i < mino->h)
    {
      j = 0;
      while (j < mino->w)
        {
          if ((opt->grid[i + opt->curx][j + opt->cury + dir] != 0) &&
	      (mino->grid[i][j] != 0))
              return (0);
          j = j + 1;
        }
      i = i + 1;
    }
  opt->cury = opt->cury + dir;
  opt->refresh = 2;
  return (0);
}

int	apply_key_drop(t_opt *opt)
{
  while (opt->posay != 1)
    fall_tetris(opt, opt->tcur[opt->curpos], opt->curx, opt->cury);
  return (0);
}

int	handle_keys(t_opt *opt, int ch)
{
  if (ch == opt->kdrop)
    return (apply_key_drop(opt));
  if (ch == opt->kleft)
    return (apply_key_side(opt, opt->tcur[opt->curpos], -1));
  if (ch == opt->kright)
    return (apply_key_side(opt, opt->tcur[opt->curpos], 1));
  if (ch == opt->kpause)
    return (make_pause(opt));
  if (ch == opt->kturn)
    return (make_turn(opt));
  if (ch == opt->kexit)
    {
      opt->stop = 1;
      opt->refresh = 1;
    }
  return (0);
}

/*
** make_turn.h for my_ls in /home/wyzlic_a/.live-packs/wyzlic_a-pack
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Apr 27 15:42:14 2016 Dimitri Wyzlic
** Last update Sun Aug 21 02:35:47 2016 wyzlic_a
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

int	make_turn(t_opt *opt)
{
  int	newpos;
  int	i;
  int	j;

  i = 0;
  newpos = (opt->curpos + 1 >= 4) ? 0 : opt->curpos + 1;
  while (i < (opt->tcur[newpos])->h)
    {
      j = 0;
      while (j < (opt->tcur[newpos])->w)
        {
          if (((opt->tcur[newpos])->grid[i][j] != 0)
              && (opt->grid[i + opt->curx][j + opt->cury] != 0))
            return (0);
          j = j + 1;
        }
      i = i + 1;
    }
  opt->curpos = newpos;
  opt->refresh = 1;
  return (0);
}

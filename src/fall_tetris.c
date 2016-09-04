/*
** fall_tetris.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Aug 12 05:39:30 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:31:29 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

void	blit_tetris(t_opt *opt, t_mino *mino, int posx, int posy)
{
  int	i;
  int	j;

  i = 0;
  opt->refresh = 1;
  while (i < mino->h)
    {
      j = 0;
      while (j < mino->w)
	{
	  if (mino->grid[i][j] != 0)
	    opt->grid[i + posx][j + posy] = mino->color;
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	norme_fall(t_opt *opt, t_mino *mino, int posx, int posy)
{
  opt->posay = 1;
  return (blit_tetris(opt, mino, posx - 1, posy));
}

void	fall_tetris(t_opt *opt, t_mino *mino, int posx, int posy)
{
  int	i;
  int	j;

  i = 0;
  posx = posx + 1;
  while (i < mino->h)
    {
      if (i + posx >= opt->gsize[0])
	return (norme_fall(opt, mino, posx, posy));
      j = 0;
      while (j < mino->w)
	{
	  if ((mino->grid[i][j] == '*' && opt->grid[i + posx][j + posy] != 0) ||
	      (mino->grid[i][j] == '*' && (i + posx) >= opt->gsize[0]))
	    return (norme_fall(opt, mino, posx, posy));
	  j = j + 1;
	}
      i = i + 1;
    }
  opt->curx = opt->curx + 1;
}

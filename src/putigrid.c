/*
** putigrid.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Aug 12 00:44:12 2016 Dimitri Wyzlic
** Last update Fri Aug 12 01:31:40 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int	*cp_line_grid(t_opt *opt, int i)
{
  int	j;
  int	*out;

  out = malloc(sizeof(int) * opt->gsize[1]);
  if (out == NULL)
    return (NULL);
  j = 0;
  while (j < opt->gsize[1])
    {
      out[j] = opt->grid[i][j];
      j = j + 1;
    }
  return (out);
}

int	**cp_grid(t_opt *opt)
{
  int	**out;
  int	i;

  i = 0;
  out = malloc(sizeof(int *) * (opt->gsize[0]));
  if (out == NULL)
    return (NULL);
  while (i < opt->gsize[0])
    {
      out[i] = cp_line_grid(opt, i);
      if (out[i] == NULL)
	return (NULL);
      i = i + 1;
    }
  return (out);
}

int	put_in_grid(t_opt *opt, t_mino *cur)
{
  int	**grid_temp;
  int	i;
  int	j;

  grid_temp = cp_grid(opt);
  if (grid_temp == NULL)
    return (1);
  i = 0;
  while (i < cur->h)
    {
      j = 0;
      while (j < cur->w)
	{
          if (grid_temp[i + opt->curx][j + opt->cury] == 0)
            grid_temp[i + opt->curx][j + opt->cury] = cur->color;
	  j = j + 1;
	}
      i = i + 1;
    }
  opt->grid_temp = grid_temp;
  return (0);
}

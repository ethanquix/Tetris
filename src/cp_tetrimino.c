/*
** main_loop.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:28:33 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

char	*cp_grid_line_dos(char *src, int y)
{
  int	i;
  char	*out;

  out = malloc(sizeof(char) * y);
  if (out == NULL)
    return (NULL);
  i = 0;
  while (i < y)
    {
      out[y] = src[y];
      i = i + 1;
    }
  return (out);
}

char	**cp_grid_dos(char **src, int x, int y)
{
  int	i;
  char	**out;

  out = malloc(sizeof(char *) * x);
  if (out == NULL)
    return (NULL);
  i = 0;
  while (i < x)
    {
      out[i] = cp_grid_line_dos(src[i], y);
      if (out[i] == NULL)
        return (NULL);
      i = i + 1;
    }
  return (out);
}

t_mino		*gen_part_mino(t_mino *src)
{
  t_mino	*out;

  out = malloc(sizeof(t_mino) * 1);
  if (out == NULL)
    return (NULL);
  out->name = src->name;
  out->h = src->h;
  out->w = src->w;
  out->color = src->color;
  out->grid = cp_grid_dos(src->grid, src->h, src->w);
  if (out->grid == NULL)
    return (NULL);
  return (out);
}

t_mino		**cp_tetri(t_mino **src)
{
  t_mino	**out;
  int		i;

  i = 0;
  if (src == NULL)
    return (NULL);
  out = malloc(sizeof(t_mino *) * 4);
  if (out == NULL)
    return (NULL);
  while (i < 4)
    {
      out[i] = gen_part_mino(src[i]);
      if (out[i] == NULL)
        return (NULL);
      i = i + 1;
    }
  return (out);
}

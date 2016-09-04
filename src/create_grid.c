/*
** create_grid.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Aug  8 22:45:59 2016 Dimitri Wyzlic
** Last update Fri Aug 12 06:19:26 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	*make_grid_line(int w)
{
  int	i;
  int	*out;

  i = 0;
  out = malloc(sizeof(int) * w);
  if (out == NULL)
    return (NULL);
  while (i < w)
    {
      out[i] = 0;
      i = i + 1;
    }
  return (out);
}

int	**make_grid(int h, int w)
{
  int	**out;
  int	i;

  i = 0;
  out = malloc(sizeof(int *) * h);
  if (out == NULL)
    return (NULL);
  while (i < h)
    {
      out[i] = make_grid_line(w);
      if (out[i] == NULL)
	return (NULL);
      i = i + 1;
    }
  return (out);
}

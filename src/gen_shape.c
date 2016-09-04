/*
** gen_shape.c for tetis in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Aug  4 05:54:23 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:50:43 2016 wyzlic_a
*/

#include <stdlib.h>
#include <my.h>

void	norme_gen_shape(t_mino *out, t_mino *src, int yop)
{
  if (yop == 0)
    {
      out->h = src->h;
      out->w = src->w;
      out->color = src->color;
    }
  else
    {
      return;
    }
}

t_mino		*get_rot_right(t_mino *src, int i, int j, int x)
{
  t_mino	*out;
  char		**grid;
  char		*temp;

  if (((out = malloc(sizeof(t_mino))) == NULL) ||
      ((grid = malloc(sizeof(char *) * src->h)) == NULL))
    return (NULL);
  norme_gen_shape(out, src, 0);
  while (i < src->h)
    {
      j = 0;
      x = src->w - 1;
      if ((temp = malloc(sizeof(char) * src->w)) == NULL)
	return (NULL);
      while (j < src->w)
	{
	  temp[j] = src->grid[i][x];
	  j = j + 1;
	  x = x - 1;
	}
      grid[i] = temp;
      i = i + 1;
    }
  out->grid = grid;
  return (out);
}

t_mino		*get_rot_top(t_mino *src, int i, int j, int w)
{
  t_mino	*out;
  char		**grid;
  char		*temp;

  if (((out = malloc(sizeof(t_mino))) == NULL) ||
      ((grid = malloc(sizeof(char *) * src->h)) == NULL))
    return (NULL);
  norme_gen_shape(out, src, 0);
  while (i < src->h)
    {
      j = 0;
      if ((temp = malloc(sizeof(char) * src->w)) == NULL)
	return (NULL);
      while (j < src->w)
	{
	  temp[j] = src->grid[i][j];
	  j = j + 1;
	}
      grid[w] = temp;
      i = i + 1;
      w = w - 1;
    }
  out->grid = grid;
  return (out);
}

t_mino		*gen_right(t_mino *src, int i, int j)
{
  t_mino	*out;
  char		**grid;
  char		*temp;

  if ((out = malloc(sizeof(t_mino))) == NULL)
    return (NULL);
  out->h = src->w;
  out->w = src->h;
  out->color = src->color;
  if ((grid = malloc(sizeof(char *) * (out->h + 10))) == NULL)
    return (NULL);
  while (i < src->w)
    {
      j = 0;
      if ((temp = malloc(sizeof(char *) * (src->h + 10))) == NULL)
	return (NULL);
      while (j < src->h)
	{
	  temp[j] = src->grid[j][i];
	  j = j + 1;
	}
      grid[i++] = temp;
    }
  out->grid = grid;
  return (out);
}

t_mino	**get_shape(t_mino *src)
{
  t_mino	**out;

  if (src == NULL)
    return (NULL);
  out = malloc(sizeof(t_mino *) * 4);
  if (out == NULL)
    return (NULL);
  out[0] = src;
  out[3] = gen_right(out[0], 0, 0);
  out[2] = get_rot_top(out[0], 0, 0, src->h - 1);
  out[1] = get_rot_right(out[3], 0, 0, 0);
  return (out);
}

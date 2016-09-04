/*
** print_map.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 00:01:10 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:01:51 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

void	print_lat_map(int x, int y, int h)
{
  int	i;

  i = 0;
  while (i < h)
    {
      mvprintw(x + i, y, "|");
      i = i + 1;
    }
}

void	print_top_map(int x, int y, int w)
{
  int	i;

  i = 0;
  while (i < w)
    {
      mvprintw(x, y + i, "-");
      i = i + 1;
    }
}

void	print_border_map(int h, int w, int x, int y)
{
  print_top_map(x, y, w);
  print_top_map(x + h - 1, y, w);
  print_lat_map(x, y, h);
  print_lat_map(x, y + w - 1, h);
}

int	print_map(t_opt * all, int x, int y)
{
  int	i;
  int	j;

  i = 0;
  if (all == NULL)
    return (-1);
  if (all->grid_temp == NULL)
    return (-1);
  while (i < all->gsize[0])
    {
      j = 0;
      while (j < all->gsize[1])
	{
	  if (all->grid_temp[i][j] != 0)
	    {
	      attron(COLOR_PAIR(all->grid_temp[i][j] + 1));
	      mvprintw(i + x, y + j, "*");
	      attroff(COLOR_PAIR(all->grid_temp[i][j] + 1));
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

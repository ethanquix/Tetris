/*
** check_lines.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:59:07 2016 wyzlic_a
*/

#include "my.h"

int	is_line_todel(int **grid, int x, int y)
{
  int	i;
  int	j;
  int	verif;

  i = 0;
  while (i < x)
    {
      j = 0;
      verif = 1;
      while (j < y)
        {
          if (grid[i][j] == 0)
            verif = 0;
          j = j + 1;
        }
      if (verif == 1)
        return (i);
      i = i + 1;
    }
  return (-1);
}

int	*fill_zeros_line(int *line, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      line[i] = 0;
      i = i + 1;
    }
  return (line);
}

int	**del_from_grid(int **grid, int x, int y, int todel)
{
  int	i;
  int	j;

  i = todel;
  grid[todel] = fill_zeros_line(grid[todel], y);
  if (todel == 0)
    return (grid);
  while (i > 0)
    {
      j = 0;
      while (j < y)
        {
          grid[i][j] = grid[i - 1][j];
          j = j + 1;
        }
      i = i - 1;
    }
  grid[0] = fill_zeros_line(grid[0], y);
  return (grid);
}

int	**check_lines(t_opt **opt, int **grid, int x, int y)
{
  int	i;
  int	todel;

  i = 0;
  while (i < x)
    {
      if ((todel = is_line_todel(grid, x, y)) != -1)
        {
          i = -1;
	  (*opt)->dellines = (*opt)->dellines + 1;
          grid = del_from_grid(grid, x, y, todel);
        }
      i = i + 1;
    }
  return (grid);
}

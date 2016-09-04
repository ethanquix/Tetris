/*
** parse_tetri.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jul 27 16:18:49 2016 Dimitri Wyzlic
** Last update Sun Aug 21 02:43:45 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

char	*mfill(int len, char car, char *str)
{
  int	i;

  i = 0;
  while (i < len)
    {
      str[i] = car;
      i = i + 1;
    }
  return (str);
}

char	*new_line_parse(char *str, int w)
{
  char	*out;
  int	i;

  i = 0;
  out = malloc(sizeof(char) * w);
  if (out == NULL || str == NULL)
    return (NULL);
  out = mfill(w, ' ', out);
  while (i < my_strlen(str) && i < w)
    {
      if (str[i] == '*')
	out[i] = '*';
      i = i + 1;
    }
  return (out);
}

t_mino		*parse_file(int fd, int i)
{
  t_mino	*all;
  char		**line;
  int		nbwords;
  char		**grid;

  if ((all = malloc(sizeof(t_mino))) == NULL)
    return (NULL);
  line = strtab(get_next_line(fd), &nbwords);
  if (nbwords != 3 || line == NULL)
    return (NULL);
  all->w = my_getnbr(line[0]);
  all->h = my_getnbr(line[1]);
  all->color = my_getnbr(line[2]);
  if (all->h <= 0 || all->w <= 0 || all->color < 0)
    return (NULL);
  if ((grid = malloc(sizeof(char *) * all->h)) == NULL)
    return (NULL);
  while (i < all->h)
    if ((grid[i++] = new_line_parse(get_next_line(fd), all->w)) == NULL)
      return (NULL);
  all->grid = grid;
  return (all);
}

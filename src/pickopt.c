/*
** pickopt.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug  6 05:43:01 2016 Dimitri Wyzlic
** Last update Sun Aug 21 02:45:37 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

int	findemp(char *src, char tof)
{
  int	i;

  i = 0;
  while (src[i] && src[i] != tof)
    i = i + 1;
  if (src[i] == tof)
    return (i + 1);
  else
    return (-1);
}

char	pickopt(char *todel, char *all)
{
  int	lena;
  int	lenb;

  lena = my_strlen(todel);
  lenb = my_strlen(all);
  if (lena + 1 != lenb)
    return (-66);
  return (all[lenb - 1]);
}

int	takefrom(char *str, int emp)
{
  char	*out;
  int	i;
  int	max;

  i = 0;
  if (str == NULL || emp < 0 || emp >= my_strlen(str))
    return (0);
  max = my_strlen(str);
  out = malloc(sizeof(char) * max);
  if (out == NULL)
    return (0);
  while (emp < max && str[emp] >= '0' && str[emp] <= '9')
    {
      out[i] = str[emp];
      i = i + 1;
      emp = emp + 1;
    }
  out[i] = 0;
  return (my_getnbr(out));
}

int	*pickgsize(char *src)
{
  int	*out;
  int	emp;

  out = malloc(sizeof(int) * 2);
  if (out == NULL)
    return (NULL);
  out[0] = 20;
  out[1] = 10;
  emp = findemp(src, '=');
  if (emp == -1)
    return (out);
  out[0] = takefrom(src, emp);
  emp = findemp(src, ',');
  if (emp == -1)
    return (out);
  out[1] = takefrom(src, emp);
  return (out);
}

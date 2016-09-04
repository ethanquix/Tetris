/*
** is_equal.c for faitchier in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug  6 03:50:14 2016 Dimitri Wyzlic
** Last update Sat Aug  6 05:28:06 2016 Dimitri Wyzlic
*/

#include "my.h"

int	iseq(char *a, char *b)
{
  int	maxa;
  int	maxb;
  int	i;

  i = 0;
  if (a == NULL || b == NULL)
    return (0);
  maxa = my_strlen(a);
  maxb = my_strlen(b);
  if (maxa != maxb)
    return (0);
  while (i < maxa)
    {
      if (a[i] != b[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

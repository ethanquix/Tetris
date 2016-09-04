/*
** my_getnbr.c for alum in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Jul 21 12:34:18 2016 Dimitri Wyzlic
** Last update Sat Aug  6 06:58:06 2016 Dimitri Wyzlic
*/

#include <stdio.h>
#include "my.h"

int	my_strlen_modif(char *in)
{
  int	i;

  i = 0;
  if (in == NULL)
    return (-1);
  while (in[i])
    {
      if (in[i] > '9' || in[i] < '0')
	return (-1);
      i = i + 1;
    }
  return (i);
}

int	my_getnbr(char *in)
{
  int	out;
  int	pow;
  int	max;

  out = 0;
  pow = 1;
  max = my_strlen_modif(in) - 1;
  if (max < 0)
      return (-1);
  while (max >= 0)
    {
      out = out + (in[max] - 48) * pow;
      max = max - 1;
      pow = pow * 10;
    }
  return (out);
}

/*
** concastr.c for monishell in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri Jun 24 01:02:05 2016 Dimitri Wyzlic
** Last update Wed Aug 10 20:01:50 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

char	*my_conca(char *a, char *b)
{
  char	*out;
  int	i;
  int	j;

  i = 0;
  j = 0;
  out = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 10));
  if (a == NULL || b == NULL || out == NULL)
    return (NULL);
  while (a[i])
    {
      out[i] = a[i];
      i = i + 1;
    }
  while (b[j])
    {
      out[i + j] = b[j];
      j = j + 1;
    }
  out[i + j] = 0;
  return (out);
}

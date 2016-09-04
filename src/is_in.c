/*
** is_in.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug  3 14:34:34 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:52:33 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

int	is_in(char *tof, char *all)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if (tof == NULL || all == NULL)
    return (0);
  while (all[i] != 0)
    {
      k = i;
      j = 0;
      while (all[k] == tof[j] && tof[j] != 0 && all[k] != 0)
	{
	  k = k + 1;
	  j = j + 1;
	}
      if (tof[j] == 0)
	return (1);
      i = i + 1;
    }
  return (0);
}

int	isinopt(char *tof, char *all)
{
  int	i;

  i = 0;
  if (tof == NULL || all == NULL)
    return (0);
  while (all[i] == tof[i] && all[i] && tof[i])
    {
      i = i + 1;
    }
  if (all[i] == 0)
    return (1);
  return (0);
}

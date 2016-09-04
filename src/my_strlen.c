/*
** my_strlen.c for day04 in /home/wyzlic_a/rendu/j04
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Mar  3 11:34:41 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:49:54 2016 Dimitri Wyzlic
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

/*
** error.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Aug  8 23:26:48 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:51:30 2016 wyzlic_a
*/

#include <unistd.h>
#include "my.h"

void	my_putchar_error(char c)
{
  if (c)
    write(2, &c, 1);
}

int	merror(char *str, int ret)
{
  int	i;

  if (str == NULL)
    return (ret);
  i = 0;
  while (str[i])
    {
      my_putchar_error(str[i]);
      i = i + 1;
    }
  return (ret);
}

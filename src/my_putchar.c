/*
** my_putchar.c for lib in /home/wyzlic_a/blih/Piscine_C_LIB/c_files
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Mar 14 12:03:59 2016 Dimitri Wyzlic
** Last update Mon Jun  6 13:12:16 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  if (c)
    write(1, &c, 1);
}

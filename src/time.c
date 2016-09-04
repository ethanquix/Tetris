/*
** time.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 17:02:08 2016 Dimitri Wyzlic
** Last update Fri Aug 12 00:01:44 2016 Dimitri Wyzlic
*/

#include <stdio.h>
#include <time.h>
#include "my.h"

void		get_time(t_opt *opt)
{
  long int	cur;

  cur = time(NULL) - opt->time_start;
  if (cur == 0)
    {
      opt->time_min = 0;
      opt->time_sec = 0;
      return ;
    }
  opt->time_min = cur / 60;
  opt->time_sec = cur % 60;
}

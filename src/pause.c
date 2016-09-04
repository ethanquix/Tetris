/*
** pause.c for my_ls in /home/wyzlic_a/.live-packs/wyzlic_a-pack
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Apr 27 15:42:14 2016 Dimitri Wyzlic
** Last update Sun Aug 21 02:44:59 2016 wyzlic_a
*/

#include <time.h>
#include "my.h"

int		make_pause(t_opt *opt)
{
  int		out;
  long int	cur;

  out = 0;
  cur = time(NULL);
  while (out == 0)
    out = (getch() == opt->kpause) ? 1 : 0;
  cur = time(NULL) - cur;
  opt->time_start = opt->time_start + cur;
  return (0);
}

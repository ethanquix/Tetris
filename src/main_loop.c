/*
** main_loop.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 04:00:15 2016 wyzlic_a
*/

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "my.h"

int	gen_new_tetriminos(t_opt *opt, t_ll *lminos)
{
  if (opt->tcur == NULL)
    {
      opt->tnext = gen_new_shape(opt, lminos);
      opt->tcur = opt->tnext;
      if (opt->tcur == NULL || opt->tnext == NULL)
        return (1);
      opt->posay = 0;
      return (0);
    }
  opt->tcur = opt->tnext;
  opt->tnext = gen_new_shape(opt, lminos);
  if (opt->tcur == NULL || opt->tnext == NULL)
    return (1);
  opt->posay = 0;
  return (0);
}

int	end_loop_main()
{
  clear();
  endwin();
  return (0);
}

int	main_loop(t_opt *opt, t_ll *lminos, int i, int ch)
{
  while (opt->stop != 1)
    {
      opt->wait = 1500000 / opt->level;
      if ((opt->posay == 1) && (gen_new_tetriminos(opt, lminos) == 1))
	return (1);
      if ((ch = getch()) != ERR)
        {
          if (handle_keys(opt, ch) != 0)
            return (1);
          if (opt->stop == 1)
	    return (end_loop_main());
        }
      if (opt->refresh == 1 || opt->refresh == 2 || i >= opt->wait)
	{
          get_time(opt);
          if (opt->refresh == 1 || i >= opt->wait)
            fall_tetris(opt, opt->tcur[opt->curpos], opt->curx, opt->cury);
	  if (put_in_grid(opt, opt->tcur[opt->curpos]) != 0)
	    return (1);
	  print_all_ui(opt);
	}
      i = (i >= opt->wait) ? 0 : i + 1;
    }
  return (end_loop_main());
}

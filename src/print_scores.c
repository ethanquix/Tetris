/*
** print_scores.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:33:46 2016 Dimitri Wyzlic
** Last update Sun Aug 21 04:03:00 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

int	check_lost(int *line, int y)
{
  int	i;

  i = 0;
  while (i < y)
    {
      if (line[i] != 0)
        return (1);
      i = i + 1;
    }
  return (0);
}

void	print_next_minos(t_mino *mino, int w)
{
  print_border_map(mino->h + 2, mino->w + 2, 1, w);
  print_one_tetri(mino, 2, w + 1);
}

void	print_scores(t_opt *opt)
{
  print_border_map(10, 20, 5, 0);
  mvprintw(6, 1, "High Score");
  mvprintw(6, 12, "%d", opt->hscore);
  mvprintw(7, 1, "Score");
  mvprintw(7, 12, "%d", (opt->dellines - 1) * (opt->gsize[0] + opt->gsize[1]));
  mvprintw(9, 1, "Lines");
  mvprintw(9, 12, "%d", opt->dellines - 1);
  mvprintw(10, 1, "Level");
  mvprintw(10, 12, "%d", (opt->level + opt->dellines / 10));
  mvprintw(11, 1, "Timer");
  mvprintw(11, 12, "%d", opt->time_min);
  mvprintw(11, 13, ":");
  mvprintw(11, 14, "%d", opt->time_sec);
}

void	print_all_ui(t_opt *all)
{
  all->grid = check_lines(&all, all->grid, all->gsize[0], all->gsize[1]);
  all->refresh = 0;
  clear();
  if (all->hide == 1)
    print_next_minos(all->tnext[all->curpos], 24 + all->gsize[1]);
  print_scores(all);
  print_border_map(all->gsize[0] + 2, all->gsize[1] + 2, 1 , 21);
  print_map(all, 2, 22);
  all->stop = check_lost(all->grid[0], all->gsize[1]);
  refresh();
}

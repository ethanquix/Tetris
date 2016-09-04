/*
** graph.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Aug  8 23:08:55 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:53:00 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

int		init_scr(t_opt *all)
{
  WINDOW	*w;

  w = initscr();
  all->w = w;
  keypad(stdscr, TRUE);
  noecho();
  timeout(0);
  move(0,0);
  curs_set(0);
  minit_color();
  clear();
  (void) all;
  return (0);
}

/*
** main_loop.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:27:07 2016 wyzlic_a
*/

#include <ncurses.h>
#include "my.h"

void	minit_color()
{
  start_color();
  init_pair(1, 0, COLOR_BLACK);
  init_pair(2, 1, COLOR_BLACK);
  init_pair(3, 2, COLOR_BLACK);
  init_pair(4, 3, COLOR_BLACK);
  init_pair(5, 4, COLOR_BLACK);
  init_pair(6, 5, COLOR_BLACK);
  init_pair(7, 6, COLOR_BLACK);
  init_pair(8, 7, COLOR_BLACK);
}

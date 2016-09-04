/*
** help.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug  6 06:14:36 2016 Dimitri Wyzlic
** Last update Sat Aug 20 01:39:58 2016 wyzlic_a
*/

#include "my.h"

int	ishelp(char **str, int max)
{
  int	i;

  i = 0;
  while (i < max)
    {
      if (iseq(str[i], "--help") == 1)
	return (1);
      i = i + 1;
    }
  return (0);
}

int	help(char **str, int max)
{
  if (str == NULL || max <= 1)
    return (0);
  if (ishelp(str, max) == 0)
    return (0);
  my_putstr("Usage: ./tetris [options]\n");
  my_putstr("Options:\n  --help                 Display this help\n  -l --l");
  my_putstr("evel={num}       Start Tetris at level num\n  -kl --key-left={K}");
  my_putstr("     Move tetrimino on LEFT with key K\n  -kr --key-right={K}  ");
  my_putstr("  Move tetrimino on RIGHT with key K\n  -kt --key-turn={K} ");
  my_putstr("    Turn tetrimino with key K\n  -kd --key-drop={K}     ");
  my_putstr("Set default DROP on key K\n  -kq --key-quit={K}     Quit ");
  my_putstr("program when press key K\n  -kp --key-pause={K}    Pause and");
  my_putstr(" restart game when press key K\n  --map-size={row,col}   Set g");
  my_putstr("ame size at row, col\n  -w --without-next      Hide next tetri");
  my_putstr("mino\n  -d --debug             Debug mode\n");
  return (1);
}

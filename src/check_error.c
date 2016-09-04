/*
** check_error.c for tetris in /home/caracole
**
** Made by wyzlic_a
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug 20 01:04:25 2016 wyzlic_a
** Last update Sun Aug 21 03:51:57 2016 wyzlic_a
*/

#include <termios.h>
#include <sys/ioctl.h>
#include "my.h"

int			check_term(int mc, int ml)
{
  static struct termios	old;
  struct termios	new;

  if (tigetnum("cols") < mc || tigetnum("lines") < ml ||
      ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
    return (merror("Please make your term bigger dude\n", 1));
  new.c_lflag &= ~ECHO;
  new.c_lflag &= ~ICANON;
  new.c_cc[VMIN] = 0;
  new.c_cc[VTIME] = 1;
  if (ioctl(0, TCSETS, &new) == 1)
    return (1);
  return (0);
}

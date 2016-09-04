/*
** print_debug.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug  6 05:49:43 2016 Dimitri Wyzlic
** Last update Sun Aug 21 02:47:24 2016 wyzlic_a
*/

#include <unistd.h>
#include "my.h"

void	my_putchard(char a)
{
  if (!a)
    return ;
  if (a == ' ')
    my_putstr("(space)");
  else
    my_putchar(a);
}

void	disp_key(char *in)
{
  int	i;

  i = 0;
  if (in[0] == ' ')
    {
      my_putstr("(space)");
      return;
    }
  while (in[i])
    {
      if (in[i] == 27)
        my_putstr("^E");
      else
        my_putchar(in[i]);
      i = i + 1;
    }
}

void	print_dbg_next(t_opt *opt, t_ll *all)
{
  char	buff[100];

  if (opt->hide == 0)
    my_putstr("No");
  else
    my_putstr("Yes");
  my_putstr("\nLevel : ");
  my_putnbr(opt->level);
  my_putstr("\nSize : ");
  my_putnbr(opt->gsize[0]);
  my_putstr("*");
  my_putnbr(opt->gsize[1]);
  my_putstr("\nTetriminos : ");
  my_putnbr(opt->nb_tetris);
  my_putstr("\n");
  mprint_tetri(all);
  my_putstr("Press a key to start Tetris\n");
  buff[0] = 0;
  while (buff[0] == 0)
    read(1, &buff, 99);
}

void	print_dbg_prev(t_opt *opt, t_ll *all)
{
  my_putstr("\nKey Quit : ");
  if (opt->kexit == 0)
    disp_key(opt->base_keys[4]);
  else
    my_putchar(opt->kexit);
  my_putstr("\nKey Pause : ");
  if (opt->kpause == 0)
    disp_key(opt->base_keys[5]);
  else
    my_putchar(opt->kpause);
  my_putstr("\nNext : ");
}

void	print_dbg(t_opt *opt, t_ll *all)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_putstr("Key Left : ");
  if (opt->kleft == 0)
    disp_key(opt->base_keys[0]);
  else
    my_putchar(opt->kleft);
  my_putstr("\nKey Right : ");
  if (opt->kright == 0)
    disp_key(opt->base_keys[1]);
  else
    my_putchar(opt->kright);
  my_putstr("\nKey Turn : ");
  if (opt->kturn == 0)
    disp_key(opt->base_keys[2]);
  else
    my_putchar(opt->kturn);
  my_putstr("\nKey Drop : ");
  if (opt->kdrop == 0)
    disp_key(opt->base_keys[3]);
  else
    my_putchar(opt->kdrop);
  print_dbg_prev(opt, all);
  return (print_dbg_next(opt, all));
}

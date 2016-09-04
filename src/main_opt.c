/*
** main_opt.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Aug  6 05:17:26 2016 Dimitri Wyzlic
** Last update Sat Aug 20 02:21:05 2016 wyzlic_a
*/

#include "my.h"

char	opint(int max, int *i, char **str)
{
  if (*i + 1 < max)
    {
      *i = *i + 1;
      return (str[*i][0]);
    }
  return (-66);
}

t_opt	*parse_opt_next(t_opt *src, char **str, int *i)
{
  if (isinopt(str[*i], "--level=") == 1)
    src->level = pickopt("--level=", str[*i]);
  if (isinopt(str[*i], "--key-left=") == 1)
    src->kleft = pickopt("--key-left=", str[*i]);
  if (isinopt(str[*i], "--key-right=") == 1)
    src->kright = pickopt("--key-right=", str[*i]);
  if (isinopt(str[*i], "--key-turn=") == 1)
    src->kturn = pickopt("--key-turn=", str[*i]);
  if (isinopt(str[*i], "--key-drop=") == 1)
    src->kdrop = pickopt("--key-drop=", str[*i]);
  if (isinopt(str[*i], "--key-exit=") == 1)
    src->kexit = pickopt("--key-exit=", str[*i]);
  if (isinopt(str[*i], "--key-pause=") == 1)
    src->kpause = pickopt("--key-pause=", str[*i]);
  if (isinopt(str[*i], "--key-without-next=") == 1)
    src->hide = 1;
  if (isinopt(str[*i], "--debug=") == 1)
    src->debug = 1;
  if (isinopt(str[*i], "--map-size=") == 1)
    src->gsize = pickgsize(str[*i]);
  return (src);
}

t_opt	*parse_opt(t_opt *src, char **str, int *i, int max)
{
  if (iseq(str[*i], "-l"))
    src->level = my_getnbr(str[(*i + 1) % max]);
  if (iseq(str[*i], "-kl"))
    src->kleft = opint(max, i, str);
  if (iseq(str[*i], "-kr"))
    src->kright = opint(max, i, str);
  if (iseq(str[*i], "-kt"))
    src->kturn = opint(max, i, str);
  if (iseq(str[*i], "-kd"))
    src->kdrop = opint(max, i, str);
  if (iseq(str[*i], "-kq"))
    src->kexit = opint(max, i, str);
  if (iseq(str[*i], "-kp"))
    src->kpause = opint(max, i, str);
  if (iseq(str[*i], "-w"))
    src->hide = 1;
  if (iseq(str[*i], "-d"))
    src->debug = 1;
  return (parse_opt_next(src, str, i));
}

t_opt	*main_opt(t_opt *src, int max, char **str)
{
  int	i;

  i = 1;
  while (i < max)
    {
      src = parse_opt(src, str, &i, max);
      i = i + 1;
    }
  return (src);
}

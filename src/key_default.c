/*
** check_lines.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:58:01 2016 wyzlic_a
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <term.h>
#include "ntm.h"

char	*my_term(char **env)
{
  char	**out;
  int	i;

  i = -1;
  if (env[0] == NULL)
    return (NULL);
  while (env[++i] != NULL)
    {
      out = strtab_char(env[i], '=');
      if (out == NULL)
        return (NULL);
      if (is_in("TERM", out[0]) == 1 && out[0][0] != 'C')
        return (out[1]);
      i = i + 1;
    }
  (void) out;
  return (NULL);
}

char	**set_def_keys(char **env)
{
  char	**key;
  int	ptr;
  char	*temp;

  temp = my_term(env);
  if (setupterm(temp, 1, &ptr) < 0)
    return (NULL);
  key = malloc(sizeof(char *) * 10);
  if (key == NULL)
    return (NULL);
  key[0] = tigetstr("kcub1");
  key[1] = tigetstr("kcuf1");
  key[2] = tigetstr("kcuu1");
  key[3] = tigetstr("kcud1");
  key[4] = "q";
  key[5] = "p";
  if (key[0] == NULL || key[1] == NULL || key[2] == NULL || key[3] == NULL
      || key[4] == NULL || key[5] == NULL)
    return (NULL);
  return (key);
}

/*
** check_lines.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:19:36 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

int	get_bigger_ll(t_ll *ll)
{
  char	*cur;
  int	i;
  t_ll	*temp;
  int	out;

  out = 0;
  temp = malloc(sizeof(t_ll));
  if (temp == NULL)
    return (-1);
  temp = ll;
  cur = NULL;
  i = 0;
  while (temp != NULL)
    {
      if (is_bigger(cur, temp->tab[0]->name) == 0)
        {
          cur = temp->tab[0]->name;
          out = i;
        }
      i = i + 1;
      temp = temp->next;
    }
  return (out);
}

t_ll	*add_ll_x(t_ll *ll, int x, t_ll *to_add)
{
  t_ll	*t;

  t = malloc(sizeof(t_ll));
  if (t == NULL)
    return (NULL);
  t = ll;
  while (t != NULL)
    {
      if (x == 0)
        return (add_ll(to_add, t->tab));
      t = t->next;
      x = x - 1;
    }
  return (NULL);
}

t_ll	*sort_alpha(t_ll *ll)
{
  int	x;
  t_ll	*out;

  if (ll == NULL)
    return (NULL);
  out = malloc(sizeof(ll));
  if (out == NULL)
    return (NULL);
  out = NULL;
  while (ll != NULL)
    {
      x = get_bigger_ll(ll);
      if (x == -1)
        return (NULL);
      out = add_ll_x(ll, x, out);
      ll = del_ll(ll, x);
      if (out == NULL)
        return (NULL);
    }
  return (out);
}

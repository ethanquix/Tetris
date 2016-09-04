/*
** check_lines.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 01:20:56 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:25:10 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

t_ll	*purge_ll(t_ll *all, int del)
{
  t_ll	*new;
  t_ll	*out;

  new = malloc(sizeof(t_ll));
  if (new == NULL)
    return (NULL);
  new = all;
  out = NULL;
  while (new != NULL)
    {
      if (del == 0)
        {
          if (new->tab[0]->h != -50 )
            out = add_ll(out, new->tab);
        }
      if (del == 1)
        {
          if (new->tab[0]->del != 666)
            out = add_ll(out, new->tab);
        }
      new = new->next;
    }
  return (out);
}

t_ll	*del_ll(t_ll *all, int del)
{
  t_ll	*temp;

  temp = malloc(sizeof(t_ll));
  if (temp == NULL)
    return (NULL);
  temp = all;
  while (temp != NULL)
    {
      temp->tab[0]->del = 0;
      if (del == 0)
        {
          temp->tab[0]->del = 666;
          return (purge_ll(all, 1));
        }
      del = del - 1;
      temp = temp->next;
    }
  return (all);
}

int	is_bigger(char *a, char *b)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (a == NULL)
    return (0);
  while (a[i] && b[j])
    {
      if (a[i] > b[j])
        return (1);
      if (a[i] < b[j])
        return (0);
      i = i + 1;
      j = j + 1;
    }
  return (0);
}

int	is_sort(t_ll *ll)
{
  char	*cur;
  t_ll	*temp;

  temp = malloc(sizeof(t_ll));
  if (temp == NULL)
    return (1);
  temp = ll;
  cur = NULL;
  while (temp != NULL)
    {
      if (is_bigger(cur, temp->tab[0]->name) == 1)
        return (0);
      cur = temp->tab[0]->name;
      temp = temp->next;
    }
  return (1);
}

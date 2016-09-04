/*
** gen_new_shape.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug 10 17:26:28 2016 Dimitri Wyzlic
** Last update Sun Aug 21 01:33:10 2016 wyzlic_a
*/

#include <stdlib.h>
#include "my.h"

int	len_llist(t_ll *ll)
{
  t_ll	*temp;
  int	out;

  out = 0;
  temp = malloc(sizeof(t_ll));
  if (temp == NULL || ll == NULL)
    return (0);
  temp = ll;
  while (temp != NULL)
    {
      out = out + 1;
      temp = temp->next;
    }
  return (out);
}

t_mino	**extract_llist(t_ll *ll, int nb)
{
  t_ll	*temp;

  temp = malloc(sizeof(t_ll));
  if (temp == NULL || ll == NULL)
    return (NULL);
  temp = ll;
  while (temp != NULL && nb > 0)
    {
      nb = nb - 1;
      temp = temp->next;
    }
  return (temp->tab);
}

t_mino		**gen_new_shape(t_opt *opt, t_ll *ll)
{
  int		rd;
  t_mino	**shape;

  rd = rand() % opt->max_list;
  shape = extract_llist(ll, rd);
  if (shape == NULL)
    return (NULL);
  rd = rand() % 4;
  opt->curpos = rd;
  opt->curx = 0;
  opt->cury = 0;
  return (shape);
}

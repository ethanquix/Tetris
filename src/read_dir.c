/*
** read_dir.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Jul 27 15:47:20 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:52:45 2016 wyzlic_a
*/

#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

t_ll	*add_ll(t_ll *all, t_mino **mino)
{
  t_ll	*new;

  new = malloc(sizeof(t_ll));
  if (new == NULL)
    return (NULL);
  if (all == NULL)
    new->next = NULL;
  else
    new->next = all;
  new->tab = mino;
  return (new);
}

t_ll	*pre_round_files(t_opt *opt)
{
  DIR	*dir;

  opt->nb_tetris = 0;
  dir = opendir("tetriminos");
  if (dir == NULL)
    return (NULL);
  return (round_files(opt, dir, 0, ""));
}

t_mino		**tab_norme()
{
  t_mino	**tab;

  if ((tab = malloc(sizeof(t_mino *) * 4)) == NULL)
    return (NULL);
  if ((tab[0] = malloc(sizeof(t_mino))) == NULL)
    return (NULL);
  tab[0]->h = -50;
  return (tab);
}

t_ll		*round_files(t_opt *opt, DIR *dir, int fd, char *name)
{
  struct dirent	*ent;
  t_ll		*ll;
  t_mino	*temp;
  t_mino	**tab;

  ll = NULL;
  while ((ent = readdir(dir)) != NULL && (name = ent->d_name) != NULL)
    {
      if (is_in(".tetrimino", name) == 1)
	{
	  if ((name = my_conca("tetriminos/", name)) == NULL)
	    return (NULL);
	  if ((fd = open(name, O_RDONLY)) < 0)
	    return (NULL);
	  temp = parse_file(fd, 0);
	  if ((tab = get_shape(temp)) == NULL)
	    if ((tab = tab_norme()) == NULL)
	      return (NULL);
          tab[0]->name = name;
          opt->nb_tetris = opt->nb_tetris + 1;
	  if ((ll = add_ll(ll, tab)) == NULL)
            return (NULL);
	}
    }
  return (sort_alpha(ll));
}

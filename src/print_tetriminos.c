/*
** print_tetriminos.c for tetris in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Aug  3 14:51:07 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:52:24 2016 wyzlic_a
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

void	print_one_tetri(t_mino *shape, int xi, int xy)
{
  int	i;
  int	j;

  i = 0;
  while (i < shape->h)
    {
      j = 0;
      while (j < shape->w)
	{
	  if (shape->grid[i][j] == '*')
	    {
	      init_pair(1, shape->color, COLOR_BLACK);
	      attron(COLOR_PAIR(1));
	      mvprintw(i + xi, xy + j, "*");
	      attroff(COLOR_PAIR(1));
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}

int	print_name_tetris(char *name)
{
  int	i;

  i = 0;
  if (name == NULL)
    return (-1);
  while (name[i] != '/' && name[i])
    i = i + 1;
  i = i + 1;
  while (name[i] && name[i] != '.')
    {
      my_putchar(name[i]);
      i = i + 1;
    }
  return (0);
}

int	calc_last_pos_x(char *tab, int max)
{
  int	i;
  int	out;

  i = 0;
  out = 0;
  while (i < max)
    {
      if (tab[i] == '*')
	out = i;
      i = i + 1;
    }
  return (out + 1);
}

void	print_tetriminos(t_mino **all)
{
  int	i;
  int	j;

  i = 0;
  my_putstr("Size ");
  my_putnbr(all[0]->w);
  my_putchar('*');
  my_putnbr(all[0]->h);
  my_putstr(" : Color ");
  my_putnbr(all[0]->color);
  my_putstr(" :\n");
  while (i < all[0]->h)
    {
      j = 0;
      while (j < calc_last_pos_x(all[0]->grid[i], all[0]->w))
        {
	  my_putchar((all[0])->grid[i][j]);
          j = j + 1;
        }
      my_putchar('\n');
      i = i + 1;
    }
}

void	mprint_tetri(t_ll *src)
{
  t_ll	*tmp;

  tmp = malloc(sizeof(t_ll));
  if (tmp == NULL)
    return ;
  tmp = src;
  while (tmp != NULL)
    {
      my_putstr("Tetriminos : Name ");
      print_name_tetris(tmp->tab[0]->name);
      my_putstr(" : ");
      if (tmp->tab[0]->h == -50)
        my_putstr("Error\n");
      else
        print_tetriminos(tmp->tab);
      tmp = tmp->next;
    }
}

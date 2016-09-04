/*
** my_put_nbr.c for day03 in /home/wyzlic_a/rendu/j03
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Mar  2 17:56:10 2016 Dimitri Wyzlic
** Last update Sat Aug  6 06:07:13 2016 Dimitri Wyzlic
*/

#include "my.h"

int	fucking_number()
{
  my_putchar('-');
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
  return (0);
}

int	my_putnbr(int nb)
{
  if (nb == -2147483648)
    {
      fucking_number();
      return (0);
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}

/*
** true.c for gnl in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sun Jun 19 04:51:19 2016 Dimitri Wyzlic
** Last update Sun Jun 26 00:57:56 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*malloc_ret()
{
  char	*buff_ret;
  int	i;

  buff_ret = malloc(sizeof(*buff_ret) * (READ_SIZE + 1));
  if (buff_ret == NULL)
    return (NULL);
  i = 0;
  while (i < READ_SIZE + 1)
    {
      buff_ret[i] = '\0';
      i = i + 1;
    }
  return (buff_ret);
}

int	mread(const int fd, char *buff, int len, int *gi)
{
  int	i;

  i = 0;
  *gi = 0;
  while (i < READ_SIZE)
    {
      buff[i] = '\0';
      i = i + 1;
    }
  i = read(fd, buff, len);
  if (i <= 0)
    return (-1);
  buff[i] = '\0';
  return (i);
}

char	*mrealloc(char *src, int len)
{
  char	*out;
  int	i;

  out = malloc(sizeof(*src) * (READ_SIZE + 1 + len));
  if (out == NULL || len < 1 || src == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      out[i] = src[i];
      i = i + 1;
    }
  free (src);
  return (out);
}

char	*mread_return(char *src, int len, int *i)
{
  *i = 0;
  src[len] = '\0';
  if (len <= 0 || src[0] == '\0')
    return ('\0');
  return (src);
}

char		*get_next_line(const int fd)
{
  static char	buff_rd[READ_SIZE];
  static int	i;
  int		j;
  char		*buff_ret;
  int		len;

  j = 0;
  if ((buff_ret = malloc_ret()) == NULL)
    return (NULL);
  if (i > READ_SIZE + 1)
    i = 0;
  if (buff_rd[0] == 0 && (len = mread(fd, buff_rd, READ_SIZE, &i) < 0))
    return (NULL);
  while (buff_rd[i] != '\n')
    {
      if (buff_rd[i] == 0 && (len = mread(fd, buff_rd, READ_SIZE, &i) < 0))
	return (NULL);
      if (j != 0 && ( j % READ_SIZE) == 0
	  && ((buff_ret = mrealloc(buff_ret, j)) == NULL))
	return (NULL);
      buff_ret[j++] = buff_rd[i++];
    }
  i = i + 1;
  buff_ret[j] = 0;
  return (buff_ret);
}

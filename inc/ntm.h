/*
** my.h for my_ls in /home/wyzlic_a/.live-packs/wyzlic_a-pack
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Wed Apr 27 15:42:14 2016 Dimitri Wyzlic
** Last update Sun Aug 21 03:53:38 2016 wyzlic_a
*/

#ifndef NTM_H_
# define NTM_H_

void	my_putstr(char *);
int	my_getnbr(char *);
char	**strtab(char *, int *);
char	**strtab_char(char *, char);
int	my_strlen(char *);
int	is_in(char *, char *);
char	*my_conca(char *, char *);
int	iseq(char *, char *);
int	isinopt(char *, char *);
char	pickopt(char *, char *);
int	check_term(int, int);

#endif /* !NTM_H_ */

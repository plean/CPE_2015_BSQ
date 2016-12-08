/*
** functions2.c for  in /home/planch_j/rendu/CPE_2015_BSQ
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Nov 30 12:16:26 2015 Jean PLANCHER
** Last update Sat Dec 19 16:34:36 2015 Jean PLANCHER
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}

int	get_number(char *str, int nb, int i)
{
  while (str[++i] != 0)
    nb = nb * 10 + (str[i] - 48);
  return (nb);
}

int	my_getnbr(char *str)
{
  if (str[0] == '-')
    return(get_number(str, 0, 0) * -1);
  else if (str[0] == 48 && str[1] == 0)
    return (0);
  return(get_number(str, 0, -1));
}

int	*init_buffer(int *buffer, int x)
{
  int	i;

  i = 0;
  buffer = malloc(sizeof(int*) * x);
  while (i++ != x)
    buffer[i] = 0;
  return (buffer);
}

void	my_error()
{
  my_putstr_errors("Error: Invalide map.\n");
  exit (84);
}

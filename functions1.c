/*
** functions.c for  in /home/planch_j/rendu/CPE_2015_BSQ
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Nov 30 12:16:35 2015 Jean PLANCHER
** Last update Tue Dec 15 14:29:19 2015 Jean PLANCHER
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putchar_errors(char c)
{
  write (2, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

void	my_putstr_errors(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar_errors(str[i]);
      i = i + 1;
    }
}

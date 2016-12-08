/*
** functions3.c for  in /home/planch_j/rendu/CPE/CPE_2015_BSQ
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Thu Dec 17 23:56:40 2015 Jean PLANCHER
** Last update Wed Jan 13 17:33:37 2016 Jean PLANCHER
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	my_printbsq_suite(char *buffer, int ret, int fd, int x)
{
  while (ret != 0)
    {
      ret = read(fd, buffer, x + 1);
      buffer[ret] = 0;
      write(1, buffer, ret);
    }
}

void	my_printbsq(t_bsq_params *params, int fd, int x)
{
  char	*buffer;
  int	ret;
  int	i;
  int	j;

  buffer = malloc(sizeof(char*) * (x + 1));
  i = j = -1;
  while (++j != params->y)
    {
      ret = read(fd, buffer, x + 1);
      buffer[ret] = 0;
      write(1, buffer, ret);
    }
  while (++j <= params->y + params->air)
    {
      i = -1;
      ret = read(fd, buffer, x + 1);
      while(++i <= x)
	if (i < params->x || i >= params->x + params->air)
	  my_putchar(buffer[i]);
	else
	  my_putchar('x');
    }
  my_printbsq_suite(buffer, ret, fd, x);
  free(buffer);
}

int	my_getsquare(t_bsq_params *params, int k, int i)
{
  int	e;

  e = 0;
  while (++e < k)
    {
      if (params->buffer[i + e] < k)
	return (0);
    }
  return (1);
}

void	my_testbuf(t_bsq_params *params, int x, int y)
{
  int	i;

  i = -1;
  while (++i <= x - params->air)
    {
      if (params->buffer[i] > params->air && 
	  my_getsquare(params, params->air + 1, i) == 1)
	{
	  params->air = params->air + 1;
	  params->x = i;
	  params->y = y - params->air;
	}
    }
}

void		my_errors(int ac, char *str)
{
  struct stat	sb;

  if (ac < 2)
    {
      my_putstr_errors("Error: Incorret number of arguments.\n");
      exit(84);
    }
  if (stat(str, &sb) == -1)
    {
      my_putstr_errors("Error: File not found.\n");
      exit(84);
    }
  if (!S_ISREG(sb.st_mode))
    {
      my_putstr_errors("Error: Inccorect type of map.\n");
      exit(84);
    }
}

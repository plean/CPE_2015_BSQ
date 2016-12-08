/*
** my_bsq.c for  in /home/planch_j/rendu/CPE_2015_BSQ
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Mon Nov 30 11:59:52 2015 Jean PLANCHER
** Last update Thu Jan 14 12:59:04 2016 Jean PLANCHER
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	first_line(int fd)
{
  char	un[2];
  int	ret;
  int	i;

  i = 0;
  ret = read(fd, un, 1);
  while (ret != 0)
    {
      un[ret] = 0;
      if (un[0] == '\n')
	return (i);
      ret = read(fd, un, 1);
      i = i + 1;
    }
  return (1);
}

int	get_fnb(int fd)
{
  char	un[1];
  int	ret;
  int	nb;

  nb = 0;
  ret = read(fd, un, 1);
  while (ret != 0)
    {
      if (un[0] == '\n')
	return (nb);
      if (un[0] >= 48 && un[0] <= 57)
	nb = nb * 10 + un[0] - 48;
      else
	my_error();
      ret = read(fd, un, 1);
    }
  return (nb);
}

void	my_bsq_suite(t_bsq_params *params, char *buffer,  int i, int x)
{
  i = 0;
  while (i++ != x)
    if (buffer[i - 1] == 'o')
      params->buffer[i - 1] = 0;
    else if (buffer[i - 1] == '.')
      params->buffer[i - 1] = params->buffer[i - 1] + 1;
    else
      my_error();
}

void	my_bsq(t_bsq_params params, int x, int y, int fd, char *str)
{
  char	*buffer;
  int	j;

  buffer = malloc(sizeof(char*) * x + 1);
  params.buffer = init_buffer(params.buffer, x);
  params.x = params.y = params.air = j = 0;
  while (j++ != y)
    {
      read(fd, buffer, x + 1);
      my_bsq_suite(&params, buffer, 0, x);
      my_testbuf(&params, x, j);
    }
  close(fd);
  fd = open(str, O_RDONLY);
  if (fd == -1)
    {
      my_putstr_errors("Error: File not found.\n");
      exit(84);
    }
  get_fnb(fd);
  my_printbsq(&params, fd, x);
  close(fd);
  free(buffer);
  free(params.buffer);
}

int		main(int ac, char **av)
{
  t_bsq_params	params;
  int		y;
  int		x;
  int		fd;

  my_errors(ac, av[1]);
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      my_putstr_errors("Error: File not found.\n");
      exit(84);
    }
  y = get_fnb(fd);
  x = first_line(fd);
  close(fd);
  fd = open(av[1], O_RDONLY);
  get_fnb(fd);
  my_bsq(params, x, y, fd, av[1]);
  return (0);
}

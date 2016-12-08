/*
** my.h for  in /home/planch_j/rendu/CPE/CPE_2015_BSQ
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Tue Dec 15 14:24:01 2015 Jean PLANCHER
** Last update Wed Jan 13 17:34:28 2016 Jean PLANCHER
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_bsq_params
{
  int		*buffer;
  int		y;
  int		x;
  int		air;
}		t_bsq_params;

void	my_putchar(char c);
void	my_putchar_errors(char c);
void	my_putstr(char *str);
void	my_putstr_errors(char *str);
int	my_strlen(char *str);
int	get_number(char *str, int nb, int i);
int	my_getnbr(char *str);
int	*init_buffer(int *buffer, int x);
void	my_error();
void	my_testbuf(t_bsq_params *params, int x, int y);
void	my_printbsq(t_bsq_params *params, int fd, int x);
void	my_errors(int ac, char *str);

#endif /* !MY_H_ */

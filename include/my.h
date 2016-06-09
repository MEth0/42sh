/*
** my.h for my in /home/rousse_i/rendu/Piscine_C_J09/include
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Thu Oct  8 11:27:45 2015 mathis rousselot
** Last update Wed Jun  8 10:53:54 2016 mathis rousselot
*/

#ifndef MY_H_
# define MY_H_

# include <string.h>

char    *my_strcat_real(char *src_1, char *src_2);
char    *my_strdup(char *tmp);
void	my_putarray(char **array);
int	compare(char *str_1, char *str_2);
char	*str_copy_end(char *str, char *str2, int flag);
char	**copy_double_array(char **str);
void    my_putstr_err(char *str);
void    my_putchar_err(char c);
int	my_arraylen(char **str);
void	my_putchar(char c);
int	my_isneg(int nb);
void	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
void	my_putstr(char *str);
size_t	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strcat(char *dest, char *src);
void	my_signal();
int     char_in_str(char c, char *str);
char    *nbr_to_str(int nb);
int     str_in_str(char *src, char *str);

#endif /* !MY_H_ */

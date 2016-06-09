/*
** my_strcmp.c for $ in /home/simon-z/rendu/PSU/PSU_2015_minishell2
**
** Made by Morgan SIMON
** Login   <simon-z@epitech.net>
**
** Started on  Wed Apr  6 14:57:45 2016 Morgan SIMON
** Last update Mon Apr 11 14:57:26 2016 Morgan SIMON
*/

int     my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2++)
    {
      if (*s1++ == 0)
	return (0);
    }
  return (1);
}

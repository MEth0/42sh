/*
** my_getnbr.c for getnbr in /home/simon-z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <simon-z@epitech.net>
**
** Started on  Mon Apr 11 14:55:09 2016 Morgan SIMON
** Last update Mon Apr 11 14:55:16 2016 Morgan SIMON
*/

int     my_getnbr(char *p)
{
  int   i;
  char  *n;

  i = 0;
  n = (*p == '-' ? p++ : 0);
  while (*p)
    i = i * 10 + *p++ - '0';
  return (n ? -i : i);
}

/*
** match.c for match in /home/simon_z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Wed Jun  1 15:01:38 2016 Morgan SIMON
** Last update Wed Jun  1 15:01:58 2016 Morgan SIMON
*/

int     match(char *s1, char *s2)
{
  if ((*s1 == '\0') && (*s2 == '\0'))
    return (1);
  if ((*s1 == '\0') && (*s2 == '*'))
    return (match(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    return (match(s1 + 1, s2 + 1));
  if (*s1 != '\0' && *s2 == '*')
    return (match(s1 + 1, s2) || match(s1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

/*
** char_in_str.c for 42sh in /home/desria-m/rendu/PSU/PSU_2015_42sh
**
** Made by Desriac
** Login   <desria-m@epitech.net>
**
** Started on  Fri Jun  3 21:54:43 2016 Desriac
** Last update Sun Jun  5 00:04:53 2016 Desriac
*/

int	char_in_str(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int	str_in_str(char *src, char *str)
{
  int	i;
  int	j;

  i = j = 0;
  while (src[i] && str[j])
    {
      if (src[i] == str[j])
	j++;
      else
	j = 0;
      i++;
    }
  if (!str[j])
    return (1);
  return (0);
}

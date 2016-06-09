/*
** which.c for which in /home/simon_z/rendu/PSU/PSU_2015_42sh
**
** Made by Morgan SIMON
** Login   <morgan.simon@epitech.eu>
**
** Started on  Wed Jun  1 14:20:41 2016 Morgan SIMON
** Last update Sat Jun  4 14:52:39 2016 Morgan SIMON
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sh.h"

static int	ret_error(char *file, char *msg, int ret, int flag)
{
  if (flag == 0)
    {
      my_putstr(file);
      write(1, ": ", 2);
      my_putstr(msg);
      write(1, "\n", 1);
    }
  else if (flag == 1)
    {
      my_putstr_err(file);
      write(2, ": ", 2);
      my_putstr_err(msg);
      write(2, "\n", 1);
    }
  return (ret);
}

static void	print_path(char *path)
{
  my_putstr(path);
  write(1, "\n", 1);
}

int		my_which(t_env *env)
{
  char		*path;
  int		curs;
  int		i;
  int		ret[2];

  if (my_arraylen(env->current) == 1)
    return (ret_error("which", "Too few arguments.", 1, 1));
  (1 ? i = 1, ret[1] = 0 : 0);
  while (env->current[i])
    {
      (1 ? curs = 0, ret[0] = 0 : 0);
      while (g_func[curs].name != NULL)
	if (my_strcmp(g_func[curs++].name, env->current[i]) == 0)
	  ret[0] = ret_error(env->current[i], "shell built-in command.", 2, 0);
      if ((path = get_path(env, env->current[i])) == NULL && ret[0] != 2)
	ret[0] = ret_error(env->current[i], "Command not found.", 1, 0);
      if (path != NULL)
	if (access(path, X_OK) == -1)
	  ret[0] = ret_error(env->current[i], "Command not found.", 1, 0);
      (ret[0] == 0 ? print_path(path) : (ret[1] = ret[0]));
      free(path);
      i++;
    }
  return (ret[1] == 1 ? 1 : 0);
}

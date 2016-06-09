/*
** my_pipe.c for my_pipe in /home/rousse_i/rendu/PSU/PSU_2015_minishell2/src/str_manip/redir
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Apr  4 17:22:00 2016 mathis rousselot
** Last update Sun Jun  5 17:28:28 2016 mathis rousselot
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_sh.h"

void	write_on_pipe(int pipefd[2], t_env *env, int curs)
{
  int	check;
  char	*str;
  char	*all_sent;

  1 ? (check = 0, close(pipefd[0])) : 0;
  if ((all_sent = malloc(sizeof(char) * 1)) == NULL)
    fatal_error_exit("Malloc failed.\n");
  all_sent[0] = '\0';
  while (check == 0)
    {
      my_putstr("?> ");
      if ((str = get_next_line(0)) == NULL)
       	fatal_error_exit("GNL failed\n");
      if (my_strcmp(str, env->arg[ARG].arg[curs + 1]) == 0)
	check++;
      if ((all_sent = my_strcat_real(all_sent, str)) == NULL)
	fatal_error_exit("Malloc failed.\n");
      free(str);
    }
  if (write(pipefd[1], all_sent, my_strlen(all_sent)) == -1)
    fatal_error_exit("Write failed.\n");
  (1) ? (close(pipefd[1]), free(all_sent)) : 0;
  my_putchar('\n');
  exit(0);
}

int	check_keyword(t_env *env, int curs)
{
  int	pipefd[2];
  int	pid;
  int	status;

  if (check_missing_name(env, curs) == -1)
    return (-1);
  if (check_fd_in(env, curs) == -1)
    return (-1);
  if (pipe(pipefd) == 1)
    fatal_error_exit("Pipe failed\n");
  if ((pid = fork()) == -1)
    fatal_error_exit("Fork fails\n");
  if (pid == 0)
    write_on_pipe(pipefd, env, curs);
  waitpid(pid, &status, 0);
  close(pipefd[1]);
  env->fd.fd_in_const = pipefd[0];
  env->command[COM].in = READ_STD;
  return (0);
}

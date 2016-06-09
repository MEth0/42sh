/*
** struct_sh.h for struct_sh in /home/rousse-i/rendu/PSU/PSU_2015_42sh/include
**
** Made by mathis rousselot
** Login   <rousse-i@epitech.net>
**
** Started on  Thu Jun  2 11:43:17 2016 mathis rousselot
** Last update Sun Jun  5 17:34:22 2016 Desriac
*/

#ifndef STRUCT_SH_H_
# define STRUCT_SH_H_

typedef struct          s_command
{
  char                  **current;
  int                   in;
  int                   out;
  int                   type;
  char                  *dir;
}                       t_command;

typedef struct		s_argument
{
  char			**arg;
  int			flag;
  int			exit;
  int			value;
}			t_argument;

typedef struct		s_fd
{
  int			pipefd[2];
  int			pipefd2[2];
  int			pipe;
  int			pipe2;
  int			fd_in;
  int			fd_out;
  int			fd_in_const;
  int			fd_out_const;
  int			fd_hist;
}			t_fd;

typedef struct		s_alias
{
  char			*s_command;
  char			**command;
  int			size;
}			t_alias;

typedef struct		s_env
{
  t_command             *command;
  t_argument            *arg;
  t_fd                  fd;
  t_alias		*alias;
  int			nb_alias;
  char                  **env;
  char                  **current;
  int                   exit;
  int                   value;
  int                   current_com;
  int                   path;
  int                   nb_arg;
  int                   stop_curr;
  int                   retrn;
  int			group;
}			t_env;

#endif /* !STRUCT_SH_H_ */

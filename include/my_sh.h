/*
** my_proto.h for MY_SH in /home/rousse_i/rendu/PSU/PSU_2015_minishell1/include
**
** Made by mathis rousselot
** Login   <rousse_i@epitech.net>
**
** Started on  Mon Jan 18 12:41:13 2016 mathis rousselot
** Last update Sun Jun  5 17:39:25 2016 mathis rousselot
*/

#ifndef MY_SH_H_
# define MY_SH_H_

# include "struct_sh.h"
# include "define_sh.h"
# include "my.h"

# define ABS(x) ((x < 0) ? (-x) : (x))
# define MALLOC "malloc failed.\n"

typedef struct          s_redir
{
  int                   (*func)(t_env *env, int curs);
  char                  *name;
}                       t_redir;

typedef struct          s_func
{
  int                   (*func)(t_env *env);
  char                  *name;
}                       t_func;

extern t_func		g_func[];

char		**get_env_start(char **env, t_env *my_env);
void		send_error(int id);
void		send_it(t_env *env, int curs);

/*
** Utilities
*/

void		check_pipe(t_env *env);
void		close_fd(t_env * env);
void		fatal_error_exit(char *str);
char		*no_command(char *str);
void		forked_exit(t_env *env);
void		my_signal_forked();

/*
** Shape the arg
*/

int		parsing(char *str, t_env *env);
char            *get_next_line(const int fd);
void		no_spaces(char *str, int space);
void		no_quote(char **arg);
char		*no_ascii(char *str, char *search,
			  int curs, int delete);
void		send_redir(t_env *env);
int		special_array(int *arg, char *str, char **prog, int *curs);
int		normal_array(int *arg, char *str, char **prog, int *curs);
t_argument     	*str_to_tab(char *str, t_argument *tab, int curs);

/*
** Search the prog
*/

int		prepare_command(t_env *env, int *curs);
void		pre_analyse(t_env *env);
int		analyse(t_env *env, int curs);
char		*get_path(t_env *env, char *file);
char		*lobby(t_env *env, int curs);
int		existence_is_paused(char *str);

/*
** exec
*/

void		final_command(t_env *env, int curs);
void		keep_going(t_env *env, int curs);
void		command(char *dir, t_env *env);
void		good_pipe(t_env *env, int pipefd[2], int pipe_check);
int		close_pipe(int *pipe_check, int pipefd[2]);
void		change_fd(t_env *env);
int		built_in(t_env *env);
char		*dir_malloc_path(char *prog, char *path, int curs);
char		*dir_malloc_prog(char *prog, char *path, int curs, char *dir);

/*
** Built-in
*/

int		message_exit(t_env *env);
int		my_unsetenv(t_env *env);
int		display_env(t_env *env);
void		read_double(t_env *env);
int		my_cd(t_env *env);
int		pre_setenv(t_env *env);
int		my_setenv(char **av, t_env *env);
int		set_env_check_name(char *name);
int		my_echo(t_env *env);
int		match(char *s1, char *s2);
int		my_builtins(t_env *env);
int		my_yes(t_env *env);
int		my_which(t_env *env);
int		my_alias(t_env *env);
int		rp_alias(t_env *env, t_command *command);
int		aff_all_alias(t_env *env);
int		aff_alias(t_env *env, char **av);
int		accessible(char *str, char *dir);

/*
** My_
*/

int		acces_dir(char *str, t_env *env);
int		go_root(t_env *env);
int		go_oldpath(t_env *env);
int		go_since_home(t_env *env);
char		*get_directory(char *arg, char *env_line);
void		problem_cd(char *str);

/*
** Free func
*/

void		go_free(char ***arg);
void		free_double(char **derp);
void		free_arg(t_argument *arg);
void		free_command(t_command *com);

/*
** Str analyse
*/

int		nbr_check(char *str);
char		*get_str_name(char *env);
int		get_name(char **env, char *srch);

/*
** Redir
*/

int		check_missing_name(t_env *env, int curs);
int		check_fd_in(t_env *env, int curs);
int		check_fd_out(t_env *env, int curs);
int		open_file(t_env *env, int curs);
int		new_file(t_env *env, int curs);
int		my_pipe(t_env *env, int curs);
int		end_of_file(t_env *env, int curs);

/*
** Token
*/

int		do_token(char ***pre_token);
int		add_spaces(char ***separate);
int		compare_redirect(char *str);
int		tokeniser(char  ****token, char *str);
int		free_token(char ***token);

/*
** check
*/

int		check_end(char *str, int curs);
int		check_end_size(char *str, int curs);
int		check_end_copy(char *str, int curs);
int		check_keyword(t_env *env, int curs);
int		check_validity_arg(t_env *env);
void		end_arg(char *str, int *curs, int *flag);

/*
** Exit
*/

void		close_prog(t_env *env);
void		close_final(t_env *env);
void		check_exit(t_env *env);
void		free_alias(t_env *env);

/*
** Fork right
*/

void		set_right_fd(int pgid);

/*
** bonus
*/

int		globbin(t_env *env, t_command *command);
int		shrc(t_env *env);
int		my_history(t_env *env, char *str);
char		**get_dir(char *path);

#endif /* !MY_SH_H_ */

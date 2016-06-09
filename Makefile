##
## Makefile for 42sh in /home/simon-z/rendu/PSU/PSU_2015_42sh
## 
## Made by Morgan SIMON
## Login   <simon-z@epitech.net>
## 
## Started on  Thu Apr 12 09:58:45 2016 Morgan SIMON
## Last update Sun Jun  5 17:41:20 2016 mathis rousselot
##

NAME	=	42sh

CC	=	gcc

MY	=	src/my/

TOKEN	=	src/tokeniser/

B-IN	=	src/built_in/

STR	=	src/str_manip/

UTIL	=	src/utilities/

ANALY	=	src/analyse/

EXEC	=	src/exec/

BONUS	=	src/bonus/

SRCMY	=	$(MY)my_putchar.c       	\
                $(MY)my_strlen.c        	\
                $(MY)my_putstr.c        	\
		$(MY)my_strcat.c		\
		$(MY)get_next_line.c		\
		$(MY)my_strcmp.c		\
		$(MY)my_getnbr.c		\
		$(MY)my_arraylen.c		\
		$(MY)my_str_copy_end.c		\
		$(MY)my_wordtab_copy.c		\
		$(MY)my_compare.c		\
		$(MY)char_in_str.c		\
		$(MY)nbr_to_str.c		\
		$(MY)my_putarray.c		\

SRC	=	src/main.c			\
		src/set_first_env.c		\
		$(ANALY)analyse.c		\
		$(ANALY)pre_analyse.c		\
		$(ANALY)send_analyse.c		\
		$(ANALY)prepare.c		\
		$(UTIL)my_signal.c		\
		$(UTIL)exit_error.c		\
		$(UTIL)close_fd.c		\
		$(UTIL)exit_prog.c		\
		$(STR)parsing.c			\
		$(STR)free.c			\
		$(STR)no_character.c		\
		$(STR)str_to_tab.c		\
		$(STR)check_str_to_tab.c	\
		$(STR)copy_array.c		\
		$(STR)check_existence.c		\
		$(STR)validity_arg.c		\
		$(STR)redir.c			\
		$(STR)redir/check_keyword.c	\
		$(STR)redir/end_of_file.c	\
		$(STR)redir/my_pipe.c		\
		$(STR)redir/new_file.c		\
		$(STR)redir/open_file.c		\
		$(STR)redir/check_fd.c		\
		$(EXEC)get_prog.c		\
		$(EXEC)exec.c			\
		$(EXEC)pipe_handle.c		\
		$(EXEC)malloc_dir.c		\
		$(B-IN)built_in.c		\
		$(B-IN)exit.c			\
		$(B-IN)cd/cd.c			\
		$(B-IN)cd/redir.c		\
		$(B-IN)cd/directory.c		\
		$(B-IN)env/env.c		\
		$(B-IN)env/set_env.c		\
		$(B-IN)env/unsetenv.c		\
		$(B-IN)env/set_env_check_name.c	\
		$(B-IN)echo.c			\
		$(B-IN)alias/alias.c		\
		$(B-IN)alias/aff_alias.c	\
		$(B-IN)which.c			\
		$(B-IN)get_path.c		\
		$(B-IN)builtins.c		\
		$(BONUS)42shrc.c		\
		$(BONUS)history.c		\
		$(BONUS)globin.c		\
		$(BONUS)get_dir.c		\
		$(BONUS)match.c			\
		$(SRCMY)

CFLAGS	+=	-Wall -Wextra -W
CFLAGS	+=	-I./include/

LDFLAGS	=

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

ECHO	=	/bin/echo -e


all:		flag $(NAME)

flag:
		@$(ECHO) "\n\033[0;31mFLAGS : \033[00m" $(CFLAGS) "\n"

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		@$(ECHO) "\n\e[1;32m >> 42sh OK <<\e[00m\n"
		@./extra/ascii.sh

clean:
		@$(RM) $(OBJ)
		@$(ECHO) "\033[0;32mClean OBJ    Files\033[00m"

fclean:		clean
		@$(RM) $(NAME)
		@$(ECHO) "\033[0;32mClean Binary Files\033[00m"

re:		fclean all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) "\033[0;32m ◉  »\033[1;34m" $< "\033[00m" || \
		 $(ECHO) "\033[0;31m ⊗  »\033[1;34m" $< "\033[00m"

.PHONY:		all clean fclean re

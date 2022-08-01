#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libohw/includes/libft.h"

typedef struct s_global_set{
	char	*g_path;
	int		temp[2];
	int		flag;
	int		errno_temp;
}	t_global_set;

typedef enum e_node_type
{
	PIPE,
	PRC,
	REDIR,
	CL,
}	t_node_type;

typedef struct s_meta
{
	char	*src;
	int		from;
	int		to;
}	t_meta;

typedef struct s_node
{
	t_node_type		type;
	char			**data;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_tree
{
	t_node	*root;
	t_list	*queue;
}	t_tree;

typedef struct s_param
{
	char	*s;
	int		*i;
	char	**env;
}	t_param;

void	init_term(char **envp_new[], char *envp[]);
int		cd(char *envp[], char **command);
int		pwd(void);
int		echo(char **command);
void	shell_exit(int status, char *envp[]);
void	exit_shell(char *envp[], char **command);
int		isdigit_string(char *str);
int		isstring_string(char *str);
char	*cat_env(char *key, char *val, char *envp[]);
char	*get_value(char *envp[], char *key);
char	*cut_value(char *str, char *envp[]);
char	**get_paths(char const *s, char c, char *command, char *envp[]);
void	execute_tree(t_tree *tree, char **envp[]);
void	execute_pipe(t_node *node, char **envp[], int *former_fd);
void	redir(t_node *node, char *envp[]);
void	single_command(t_node *node, char **envp[]);
void	back_command(t_node *node, char **envp[], int *fd);
void	front_command(t_node *node, char **envp[], int *fd);
int		execute_command(char **envp[], char **command);
int		execute_fork(char *envp[], char **command);
void	free_arr(char **arr);
int		env_export(char ***envp, char **command);
int		env_export_string(char ***envp, char *command);
int		env(char *envp[], char **command);
int		count_env(char *envp[]);
void	init_env(char **envp_new[], char *envp[]);
int		is_exist(char *envp[], char *key);
void	unset(char ***envp, char **command);
int		is_built_in(char **command);
void	tree_heredoc(t_list *queue, char *envp[]);
void	sig_handler(int signum);

t_tree	*new_tree(void);
t_node	*new_node(t_node_type nt, char **data);
t_meta	*new_meta(char *s, int f, int t);

char	**lst_to_arr(t_list *l);
void	destroy_strings(char **strs);
void	destroy_nodes(t_node *n);
void	destroy_tree(t_tree *t);
void	destroy_lst(t_list *l, bool rm_content);

char	*dequeue(t_list *l);
void	enqueue(t_list *l, char *s);

int		find_c(char *s, int from, char c);

bool	is_redir(char *s);

char	*extract(char *s, int *p_from, char *envp[]);
t_node	*create_prc(char *s, int *i, char *envp[]);

char	*translate(char *s, char *envp[]);

t_tree	*parse(char *s, char *envp[]);

void	print_errmsg(char *s);

bool	is_blank(char c);
bool	is_sep(char c);
void	ignore_space(char *s, int *i);
void	ignore_until_c(char *s, int *i, char c);

char	*join_and_rm_all(char *s1, char *s2);

#endif // MINISHELL_H
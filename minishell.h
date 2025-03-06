/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:29:10 by abel-all          #+#    #+#             */
/*   Updated: 2023/04/13 12:18:44 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

# define WHITE_SP " \t\n"
# define SPECIEL_CHARS "|<>/+-=%@^*[]{}~"
# define STOP_WORD "<>$|\'\"\t\n "
# define PIPE_ERR_MSG "minishell: syntax error near unexpected token `|'\n"
# define RED_ERR_MSG "minishell: syntax error near unexpected token `newline'\n"

extern int	g_child_status;

typedef enum tokens{
	WORD,
	PIPE,
	SPACE,
	D_QUOTES,
	S_QUOTES,
	ROOT,
	INP_REDIRECTION,
	OUT_REDIRECTION,
	GREATGREAT,
	LESSLESS,
	DOLAR,
	ENV_VAR,
	RM,
	DELIMITER,
	DELIMITER_Q,
	CMD
}			t_tokens;

typedef struct s_env
{
	char			*key;
	int				flag;
	char			*value;
	char			*declare;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_var
{
	int		equal;
	int		plus;
	int		i;
	int		num;
	char	***values;
}				t_var;

typedef struct s_tnp
{
	t_env	*tmp;
	t_env	*tmp2;
	char	**key;
}				t_tnp;

typedef struct s_token
{
	t_tokens			tok;
	char				*str;
	struct s_token		*next;
	struct s_token		*prev;
}				t_token;

typedef struct s_cmds
{
	char			**cmd;
	int				in_fd;
	int				out_fd;
	struct s_cmds	*next;
	struct s_cmds	*prev;
}				t_cmds;

typedef struct s_data
{
	int		i;
	char	**enva;
	t_env	*env;
	t_env	*exp;
	int		d_qoute;
	int		s_qoute;
	int		env_s;
	int		env_d;
	int		in_fd;
	int		out_fd;
	int		list_len;
}				t_data;

typedef struct s_exec
{
	t_cmds	*tmp;
	int		**pipefd;
	int		i;
	int		pid;
	int		pipes;
	int		status;
}				t_exec;

typedef struct s_exfu
{
	int		pid;
	int		j;
	t_data	*y;
}				t_exfu;

/* ---------- PARSING ---------- */

void	join_delimiter_q(t_token **tmp);
t_env	*ft_lstnew_env(char *key, char *value, int flag);
void	ft_create_node_env(t_env **head, char *key, char *value, int flag);
void	ft_lstaddback_env(t_env **head, t_env *new);
void	env_exp_init(char **enva, t_data *x);
void	tokenizer(char *cmdline, t_data *x);
int		check_qoutation(t_data *x);
int		index_of_next_d_qoutation(char *s, int *i);
int		index_of_next_s_qoutation(char *s, int *i);
int		nbr_of_qoutes(char *cmdline, t_data *x);
void	tokenizer_helper_(char *cmdline, int *i, t_token **tokens);
int		check_left_of_pipe(t_token *tokens);
void	ft_error(char *s);
void	heredoc_signal(int sigint);
char	*ft_check_and_replace(char *str, t_data *x, int end);
char	*handle_hdc_helper(char *str, t_token *head, t_data *x, int i);
int		ft_handle_heredoc(t_token *head, t_data *x);
void	join_quotes_helper(t_token *tmp);
void	join_quotes_helper_(t_token *tmp);
t_token	*ft_join_qoutes_node(t_token *tokens);
t_token	*ft_remove_env(t_token *tmp);
t_token	*ft_clean_nodes(t_token *tokens);
void	free_2d_tabb(char **p, int size);
void	free_2d_tab(char **p);
void	free_2d_tab_int(int **p, int j);
void	free_tab(char **tab);
int		ft_lstsize_tok(t_token *tokens);
t_token	*init_for_parcer(t_token *tokens, t_data *x);
void	parser_helper_outred(t_token **tmp, t_data *x, int type);
t_token	*ft_lstnew_tok(char *content, int tok);
void	ft_lstaddback_tok(t_token *head, t_token *new);
void	ft_create_node_tok(t_token *head, char *content, int type);
int		check_syntax(t_token **tokens, t_data *x);
void	expander(t_token **tokens, t_data *x);
t_cmds	*ft_lstnew_cmds(char **cmds, int in_fd, int out_fd);
void	ft_lstaddback_cmds(t_cmds *head, t_cmds *new);
void	ft_create_node_cmds(t_cmds *head, char **cmds, int in_fd, int out_fd);
void	parser(t_token **tokens, t_data *x);
t_token	*delete_node(t_token *tokens);
t_token	*delete_next_node(t_token *tokens);
int		ft_pipes_num(t_cmds **head);
int		**alloc(int pipe_nums);
void	open_pipes(int	*pipefd);
char	*getpath(t_env **env, char *str);
void	executer(t_cmds **head, t_data **x);
int		solo_command(t_cmds *tmp, t_data **x);
void	first_command(t_cmds *tmp, t_data **x, int *i, int **pipefd);
int		last_command(t_cmds *tmp, t_data **x, int *i, int **pipefd);
void	middle_command(t_cmds *tmp, t_data **env, int *i, int **pipefd);
void	our_cd(char *str, t_env **env);
void	ft_echo(char **arg);
void	ft_print_env(t_env **env);
void	our_pwd(char *str);
void	our_exit(char **str, int flag);
int		choose_cmd(t_cmds **head, t_env **env, t_env **exp);
int		execute_builtins_solo(t_cmds **tmp, t_env **env, t_env **exp);
int		execute_builtins_first(t_cmds **tmp, t_env **env, \
t_env **exp, int *pipefd);
int		execute_builtins_last(t_cmds **tmp, t_env **env, int *pipefd);
int		execute_builtins_middle(t_cmds **tmp, t_env **env, int *pipefd);
void	ft_unset(t_env **env, t_env **exp, char *key);
void	ft_export(t_env **env, t_env **exp, char **key);
int		check_existant(t_tnp *y, char *key, char *value, int plus);
int		check_in_out(t_cmds *tmp);
char	**ft_split_exp(char const *s, char c, int i, int j);
char	*check_env(char *s, t_data *x, int *end);
int		check_existant_exp(t_tnp *y, char *key);
char	**free_2dtab(char **p, int j);
char	*ft_strjoin_tok(char *s1, char *s2);
char	*ft_strjoin_par(char *s1, char *s2);
char	*ft_strjoin_par2(char *s1, char *s2);
void	free_2d_tab(char **p);
void	ft_lstclear(t_token **lst);
void	ft_lstclear_(t_cmds **lst);
int		check_builtins(t_cmds **head);
void	ft_exec_func(t_cmds *tmp, t_data *y);
void	ft_exec_ms(t_cmds *tmp, t_data *y);
void	ft_errors(void);
char	*join_path(char *str, char **s);
int		ft_pipes_num(t_cmds **head);
int		**alloc(int pipe_nums);
void	free_2d_tab_int(int **p, int j);
void	ft_lstclear__(t_env **lst);
void	closing(t_cmds **head);
void	ft_add_export(t_tnp y, t_var var);
int		ft_lstsize_tok(t_token *tokens);
int		clean_list(t_cmds *cmds, int i);
int		choose_cd_exit(t_cmds **head, t_env **exp);
char	*ft_strjoin_exec(char *s1, char *s2);
/* EXPORT */
int		check_regex(char *key, int equal);
int		check_plus(char *str, int equal);
int		ft_isalpha_(int c);
char	*get_without_plus(char *key);
int		num_of_var(char **key);
void	ft_final_export(t_tnp y, t_var var);
void	ft_final_export_(t_tnp y, t_var var);
char	***get_variables(char **key);
void	ft_add_export(t_tnp y, t_var var);
void	ft_add_export_value(t_tnp y, t_var var);
int		choose_export(t_cmds **head, t_env **env, t_env **exp);
void	ft_exec_func_solo(t_cmds *tmp, t_data *y);
int		change_value(t_env *env, char *value);
void	change_value_(t_env *env, char *value);
void	free3d_atab(char ***str, int l);
void	parser_helper_inred(t_token **tmp, t_data *x, int type);
/* EXPORT */
void	ft_link_node(t_env **tmp, t_env *save);
void	ft_link_node_exp(t_env **tmp2, t_env *save2);
void	ft_link_node_env_(t_env **tmp);
void	ft_link_node_exp_(t_env **tmp2);
void	ft_delete_node(t_env **env);

#endif

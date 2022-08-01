/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:54:27 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/24 11:45:56 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_jobqueue(t_list *l, t_node *n)
{
	if (n == NULL || l == NULL)
		return ;
	heredoc_jobqueue(l, n->left);
	if (n->data && n->data[0] && ft_strcmp(n->data[0], "<<") == 0)
		enqueue(l, n->data[1]);
	heredoc_jobqueue(l, n->right);
}

void	stop(char *s, t_tree *t, char *msg)
{
	if (msg != NULL)
		print_errmsg(msg);
	if (s != NULL)
		free(s);
	if (t != NULL)
		destroy_tree(t);
	s = NULL;
	t = NULL;
}

void	add_subtree(t_tree *org, t_node *sub)
{
	t_node	*n;

	if (sub == NULL)
		return ;
	if (org->root->left == NULL)
		org->root->left = sub;
	else if (org->root->right == NULL)
		org->root->right = sub;
	else
	{
		n = new_node(PIPE, NULL);
		n->left = org->root;
		n->right = sub;
		org->root = n;
	}
}

int	_parse_body(t_param *p, t_tree *t, bool *flag)
{
	t_node	*tmp;

	if (p->s[*(p->i)] != '|')
	{
		tmp = create_prc(p->s, p->i, p->env);
		if (tmp == NULL)
		{
			stop(p->s, t, NULL);
			return (1);
		}
		add_subtree(t, tmp);
		*flag = false;
	}
	else
	{
		if (*flag)
		{
			stop(p->s, t, "|");
			return (1);
		}
		*flag = true;
		(*(p->i))++;
	}
	return (0);
}

t_tree	*parse(char *s, char *envp[])
{
	t_tree		*t;
	int			i;
	bool		flag;
	t_param		p;

	flag = true;
	t = new_tree();
	i = 0;
	p.s = s;
	p.i = &i;
	p.env = envp;
	while (s[i])
	{
		ignore_space(s, &i);
		if (_parse_body(&p, t, &flag))
			return (NULL);
	}
	free(s);
	if (t != NULL)
		heredoc_jobqueue(t->queue, t->root);
	return (t);
}

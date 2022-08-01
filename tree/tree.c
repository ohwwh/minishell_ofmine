/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:06:23 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/24 20:28:23 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_node	*conn_node(t_node *org, t_node *new)
{
	t_node	*n;

	if (org == NULL)
		return (new);
	n = new_node(REDIR, NULL);
	n->left = org;
	n->right = new;
	return (n);
}

t_node	*create_rd(t_param *p)
{
	char	*cmd;
	char	**data;

	cmd = extract(p->s, p->i, p->env);
	if (cmd == NULL)
		return (NULL);
	data = (char **)malloc(sizeof(char *) * 3);
	if (data == NULL)
		return (NULL);
	ignore_space(p->s, p->i);
	data[0] = cmd;
	data[1] = extract(p->s, p->i, p->env);
	data[2] = NULL;
	if (data[1] == NULL || is_redir(data[1]))
	{
		print_errmsg(data[1]);
		destroy_strings(data);
		return (NULL);
	}
	return (new_node(REDIR, data));
}

int	_cr_body(t_param *p, t_node *prc, t_list *l, int to)
{
	t_node	*tmp;

	if (p->s[*(p->i)] == '>' || p->s[*(p->i)] == '<')
	{
		tmp = create_rd(p);
		if (tmp == NULL)
		{
			destroy_lst(l, true);
			return (1);
		}
		prc->left = conn_node(prc->left, tmp);
	}
	else
		if (*(p->i) <= to)
			ft_lstadd_back(l, (void *)extract(p->s, p->i, p->env));
	return (0);
}

int	create_subnode(t_node *prc, t_meta *m, int *p_from, char *envp[])
{
	int		i;
	t_list	*cl_list;
	t_param	p;

	if (prc == NULL)
		return (0);
	cl_list = ft_lstnew();
	i = *p_from;
	p.s = m->src;
	p.i = &i;
	p.env = envp;
	while (i <= m->to)
	{
		ignore_space(m->src, &i);
		if (_cr_body(&p, prc, cl_list, m->to))
			return (1);
	}
	if (cl_list->len != 0)
		prc->right = new_node(CL, lst_to_arr(cl_list));
	*p_from = i;
	destroy_lst(cl_list, false);
	return (0);
}

t_node	*create_prc(char *s, int *i, char *envp[])
{
	t_node	*n;
	t_meta	m;

	m.src = s;
	m.from = *i;
	m.to = find_c(s, *i, '|') - 1;
	if (m.to < m.from)
		return (NULL);
	n = new_node(PRC, NULL);
	if (create_subnode(n, &m, i, envp) || \
			(n->left == NULL && n->right == NULL))
	{
		destroy_nodes(n);
		return (NULL);
	}
	return (n);
}

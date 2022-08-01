/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:12:43 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/17 11:39:05 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	destroy_strings(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

void	destroy_nodes(t_node *n)
{
	if (n == NULL)
		return ;
	destroy_nodes(n->left);
	destroy_nodes(n->right);
	destroy_strings(n->data);
	free(n);
}

void	destroy_tree(t_tree *t)
{
	if (t == NULL)
		return ;
	destroy_nodes(t->root);
	destroy_lst(t->queue, true);
	free(t);
}

void	destroy_lst(t_list *lst, bool rm_content)
{
	t_list_node	*n;
	t_list_node	*target;

	if (lst == NULL)
		return ;
	n = lst->front;
	while (n)
	{
		target = n;
		n = n->next;
		if (rm_content)
			free(target->content);
		free(target);
		target = NULL;
	}
	free(lst);
	lst = NULL;
}

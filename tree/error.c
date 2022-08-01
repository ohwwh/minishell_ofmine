/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:01:08 by jiheo             #+#    #+#             */
/*   Updated: 2022/07/19 11:22:56 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_errmsg(char *s)
{
	if (!s)
		printf("minishell: syntax error near unexpected token `newline'\n");
	else
		printf("minishell: syntax error near unexpected token `%c'\n", s[0]);
}

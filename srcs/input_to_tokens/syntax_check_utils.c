/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:29:09 by makhtar & a       #+#    #+#             */
/*   Updated: 2022/05/24 11:42:12 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	token_contains_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	is_token_redir(char *str)
{
	if (ft_strlen (str) == 2)
	{
		if (ft_strnstr(str, "<<", 2) || ft_strnstr(str, ">>", 2))
			return (1);
	}
	if (ft_strlen (str) == 1)
	{
		if (ft_strnstr(str, "<", 1) || ft_strnstr(str, ">", 1))
		{
			return (1);
		}
	}
	return (0);
}

int	is_token_pipe(char *str)
{
	if (ft_strlen (str) == 1)
	{
		if (ft_strchr(str, '|'))
			return (1);
	}
	if (ft_strlen(str) > 1)
	{
		if (*str == '|')
			return (0);
	}
	return (1);
}

int	is_special_charater_correct(char *str)
{
	if (ft_strlen (str) != 2)
	{
		if (ft_strnstr(str, "<<", 2) || ft_strnstr(str, ">>", 2))
			return (0);
	}
	if (ft_strlen (str) != 1)
	{
		if ((ft_strchr(str, '<') && !ft_strnstr(str, "<<", 2)) \
		|| (ft_strchr(str, '>') && !ft_strnstr(str, ">>", 2)) \
		|| (ft_strchr(str, '|') && !ft_strnstr(str, "||", 2)))
			return (0);
	}
	return (1);
}

int	check_pipe_conditions(char **tokens, int i)
{
	if (tokens[i] && tokens[i][0] == '|' && tokens[i + 1] \
		&& tokens[i + 1][0] == '|')
		return (1);
	if (tokens[i] && tokens[i][0] == '>' && tokens[i + 1] \
		&& tokens[i + 1][0] == '|')
		return (1);
	if (tokens[i] && tokens[i][0] == '|' && i == 0)
		return (1);
	return (0);
}

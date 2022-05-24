/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:35:13 by makhtar           #+#    #+#             */
/*   Updated: 2022/05/24 11:35:14 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	free_path_close(t_pars_tokens *pa_tkns, int i, char **path)
{
	close_out_in_files_fd(pa_tkns, i);
	free_me(path);
}

void	closing_pipes(t_pars_tokens *pa_tkns, int i, int **p)
{
	if (pa_tkns[i].pipe)
	{
		close(p[i][0]);
		close(p[i][1]);
	}
	if (pa_tkns[i].pipe != 1 && pa_tkns[i].pipe)
		close(p[i + 1][1]);
}

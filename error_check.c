/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:20:57 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/31 16:46:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **check_params(int ac, char **av)
{
	check_args(ac, av);
	
}

void check_args(int ac, char **av)
{
	char *ext;
	int i;

	i = 0;
	ext = ".ber";
	if (ac != 2)
	{
		ft_fprintf(2, "Error\nInvalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	while (av[1][i])
		i++;
	if (i < 5)
	{
		ft_fprintf(2, "Error\nInvalid map name\n");
		exit(EXIT_FAILURE);
	}
	else if (ft_strncmp(&av[1][i - 4], ext, 4))
	{
		ft_fprintf(2, "Error\nInvalid map name\n");
		exit(EXIT_FAILURE);
	}
}

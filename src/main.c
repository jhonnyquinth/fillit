/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:50 by sbrynn            #+#    #+#             */
/*   Updated: 2019/11/21 16:18:40 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		readit(int fd, char ***fill, int *i)
{
	int		r;
	char	buff[22];
	char	*s;
	int		*hesh;
	int		bef;

	*i = 0;
	while ((r = read(fd, buff, SQR_SIZE + 5)) >= 20 && *i <= 26)
	{
		bef = r;
		buff[r] = '\0';
		hesh = ft_memalloc(sizeof(int) * 4);
		if (validit(r, buff, hesh))
		{
			s = normit(hesh);
			(*fill)[*i] = s;
			(*i)++;
			free(hesh);
			continue;
		}
		free(hesh);
		return (0);
	}
	(*fill)[*i] = 0;
	return ((*i > 26 || (r != 20 && r != 0) || (bef != 20 && r == 0)) ? 0 : 1);
}

void	cleanit(char ***fill, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free((*fill)[i]);
		i++;
	}
	free(*fill);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**fill;
	int		i;

	if (ac == 2)
	{
		fill = ft_memalloc(sizeof(char*) * 26);
		fd = open(av[1], O_RDONLY);
		if (!readit(fd, &fill, &i) || i == 0)
		{
			ft_putstr("error\n");
			cleanit(&fill, i);
			return (0);
		}
		else
			ft_main(fill);
		cleanit(&fill, i);
	}
	else
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	return (0);
}

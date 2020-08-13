/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 23:00:12 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/18 20:19:46 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_create_map(void)
{
	int		i;
	int		k;
	char	**tmp;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char*) * (g_size + 1))))
		return (NULL);
	while (i < g_size)
	{
		tmp[i] = malloc(sizeof(char) * (g_size + 1));
		i++;
	}
	i = -1;
	while (++i < g_size)
	{
		k = 0;
		while (k < g_size)
		{
			tmp[i][k] = '0';
			k++;
		}
		tmp[i][k] = '0';
	}
	tmp[i] = NULL;
	return (tmp);
}

void		ft_printmap(char **map)
{
	int		i;
	int		k;

	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == '0')
				map[i][k] = '.';
			k++;
		}
		i++;
	}
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int			ft_clean(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

char		**ft_copy(char **map, int i, int k)
{
	char	**str;

	if (!(str = (char **)malloc(sizeof(char *) * (g_size + 1))))
		return (NULL);
	str[g_size] = NULL;
	while (++i < g_size)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (g_size + 1))))
			return (NULL);
		str[i][g_size] = '\0';
	}
	str[i] = NULL;
	i = -1;
	while (++i < g_size)
	{
		k = 0;
		while (k < g_size)
		{
			str[i][k] = map[i][k];
			k++;
		}
	}
	return (str);
}

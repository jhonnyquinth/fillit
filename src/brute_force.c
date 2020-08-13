/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:30:01 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/21 16:14:02 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	bctrkng(t_bctrk *bc, char **map, t_piece *tetro)
{
	while (++(bc)->i < g_size)
	{
		bc->k = -1;
		while (++(bc)->k < g_size)
		{
			if (!(bc->tmp_map = ft_copy(map, -1, 0)))
				return (-1);
			if ((bc->err = ft_put(bc->tmp_map, bc->i, bc->k, tetro->data)) == 1)
			{
				if ((bc->err = ft_backtracking(tetro->next, bc->tmp_map)) == 1)
					return (1);
				else if (bc->err == -1)
					return (-1);
			}
			ft_clean(bc->tmp_map);
		}
	}
	return (0);
}

int			ft_backtracking(t_piece *tetro, char **map)
{
	t_bctrk *bc;

	if (!(tetro))
	{
		ft_printmap(map);
		exit(0);
	}
	if (!(bc = (t_bctrk*)malloc(sizeof(t_bctrk))))
		exit(0);
	bc->i = -1;
	bctrkng(bc, map, tetro);
	free(bc);
	return (0);
}

static void	slc(t_slice *sl)
{
	sl->k = -1;
	while (sl->arr[sl->i][++(sl)->k])
		if (sl->arr[sl->i][sl->k] != '.' && sl->max_l - 1 < sl->k)
			sl->max_l = sl->k + 1;
	if (sl->arr[sl->i][0] != '.' || sl->arr[sl->i][1] != '.' ||
		sl->arr[sl->i][2] != '.' || sl->arr[sl->i][3] != '.')
		sl->max_h = sl->i + 1;
	sl->i++;
}

int			ft_slice(t_piece *tetro)
{
	t_slice *sl;

	if (!(sl = (t_slice*)malloc(sizeof(t_slice))))
		exit(0);
	sl->tmp = tetro;
	while (sl->tmp)
	{
		sl->arr = sl->tmp->data;
		sl->i = 0;
		sl->max_h = 0;
		sl->max_l = 0;
		while (sl->arr[sl->i])
			slc(sl);
		sl->i = 0;
		while (sl->i < sl->max_h)
		{
			sl->arr[sl->i][sl->max_l] = '\0';
			sl->i++;
		}
		free(sl->arr[sl->i]);
		sl->arr[sl->i] = NULL;
		sl->tmp = sl->tmp->next;
	}
	free(sl);
	return (1);
}

int			ft_main(char **fill)
{
	int		i;
	char	**map;
	t_piece	*tetro;

	if (!(tetro = ft_transfer(fill)) || !(ft_slice(tetro)))
		return (-1);
	i = 1;
	g_size = 1;
	ft_clean(fill);
	while (1)
	{
		if (!(map = ft_create_map()))
			return (-1);
		if (ft_backtracking(tetro, map) == -1)
		{
			ft_clean(map);
			return (-1);
		}
		ft_clean(map);
		g_size++;
	}
}

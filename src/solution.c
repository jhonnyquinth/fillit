/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 04:45:22 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/18 10:43:30 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	func(t_trans **tr, char **fill, t_piece **tetr, t_piece **tmp)
{
	if (!(*tr = (t_trans*)malloc(sizeof(t_trans))))
		exit(0);
	(*tr)->i = 0;
	(*tr)->c = 0;
	while (fill[(*tr)->i])
	{
		(*tr)->c++;
		(*tr)->i += 1;
	}
	if (!(*tetr = (t_piece*)malloc(sizeof(t_piece))))
		exit(0);
	if (!((*tetr)->data = malloc(sizeof(char*) * 5)))
		exit(0);
	((*tetr)->data)[4] = NULL;
	*tmp = *tetr;
	(*tr)->j = 0;
}

static void	func2(t_trans **tr, t_piece **tetr, t_piece **tmp)
{
	while ((*tr)->j < (*tr)->c - 1)
	{
		if (!((*tmp)->next = (t_piece *)malloc(sizeof(t_piece) * 1)))
			exit(0);
		if (!((*tmp)->next->data = malloc(sizeof(char*) * 5)))
			exit(0);
		((*tmp)->next->data)[4] = NULL;
		*tmp = (*tmp)->next;
		(*tr)->j += 1;
	}
	(*tmp)->next = NULL;
	*tmp = *tetr;
	(*tr)->c = 0;
}

static void	func3(t_trans **tr, char ***fill, t_piece **tmp)
{
	while (*tmp)
	{
		(*tr)->i = 0;
		(*tr)->arr = (*tmp)->data;
		while ((*tr)->i < 4)
		{
			(*tr)->k = 0;
			if (!((*tr)->arr[(*tr)->i] = malloc(sizeof(char) * 5)))
				exit(0);
			while ((*tr)->k < 4)
			{
				if ((*fill)[(*tr)->c][(*tr)->i * 4 + (*tr)->k] == '#')
					(*fill)[(*tr)->c][(*tr)->i * 4 + (*tr)->k] = 'A' + (*tr)->c;
				(*tr)->arr[(*tr)->i][(*tr)->k] =
				(*fill)[(*tr)->c][(*tr)->i * 4 + (*tr)->k];
				(*tr)->k++;
			}
			(*tr)->arr[(*tr)->i][(*tr)->k] = '\0';
			(*tr)->i++;
		}
		(*tr)->c++;
		*tmp = (*tmp)->next;
		(*tr)->i = 0;
	}
}

t_piece		*ft_transfer(char **fill)
{
	t_trans	*tr;
	t_piece	*tmp;
	t_piece	*tetr;
	int		j;

	j = 0;
	func(&tr, fill, &tetr, &tmp);
	func2(&tr, &tetr, &tmp);
	func3(&tr, &fill, &tmp);
	free(tr);
	return (tetr);
}

int			ft_put(char **field, int i, int k, char **fg)
{
	int		i1;
	int		k1;

	i1 = -1;
	while (fg[++i1])
	{
		if (!(field[i1 + i]))
			return (0);
		k1 = -1;
		while (fg[i1][++k1])
			if (!(field[i1 + i][k1 + k]) ||
					(field[i1 + i][k1 + k] != '0' && fg[i1][k1] != '.'))
				return (0);
	}
	i1 = -1;
	while (fg[++i1])
	{
		k1 = -1;
		while (fg[i1][++k1])
			if (fg[i1][k1] != '.')
				field[i1 + i][k1 + k] = fg[i1][k1];
	}
	return (1);
}

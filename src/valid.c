/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:28:57 by sbrynn            #+#    #+#             */
/*   Updated: 2019/11/21 16:14:25 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		*cntit(char *s, int **hesh)
{
	int *cnt;
	int j;
	int i;

	i = 0;
	j = 0;
	cnt = ft_memalloc(sizeof(int) * 4);
	cnt[0] = 0;
	cnt[1] = 0;
	cnt[2] = 0;
	cnt[3] = 1;
	while (s[j])
	{
		if (s[j] == '\n')
			cnt[0]++;
		if (s[j] == '\n' && j % 10 != 4 && j % 10 != 9 && j != 20)
			cnt[3] = 0;
		if (s[j] == '.' || s[j] == '#')
			s[j] == '.' ? cnt[1]++ : cnt[2]++;
		if (s[j] == '#' && cnt[2] <= 4)
			(*hesh)[i++] = j;
		j++;
	}
	return (cnt);
}

int		corrfigit(int *hesh)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((hesh[i] == hesh[j] + 1 && hesh[j] % 5 != 3) ||
			(hesh[i] == hesh[j] - 1 && hesh[j] % 5 != 0) ||
			hesh[i] == (hesh[j] + SQR_SIDE + 1) ||
			(hesh[i] == hesh[j] - SQR_SIDE - 1))
				cnt++;
			j++;
		}
		i++;
	}
	return ((cnt >= 6 && cnt <= 8) ? 1 : 0);
}

int		validit(int r, char *buff, int *hesh)
{
	int *val;

	val = cntit(buff, &hesh);
	if (((r == 21 && val[0] == 5) || (r == 20 && val[0] == 4)) && val[2] == 4
	&& (val[2] + val[1]) == 16 && val[3] && corrfigit(hesh))
	{
		free(val);
		return (1);
	}
	else
	{
		free(val);
		return (0);
	}
}

void	findmin(int *mintop, int *minleft, int *hesh)
{
	int i;

	i = 1;
	*mintop = hesh[0];
	*minleft = hesh[0];
	while (i <= 3)
	{
		if (hesh[i] < *mintop)
			*mintop = hesh[i];
		if (hesh[i] % 5 < *minleft % 5)
			*minleft = hesh[i];
		i++;
	}
	*mintop = (*mintop / 5) * 5;
	*minleft = *minleft % 5;
}

char	*normit(int *hesh)
{
	char	*s;
	int		mintop;
	int		minleft;
	int		i;

	i = 4;
	s = ft_memalloc(sizeof(char) * 17);
	ft_memset(s, '.', 16);
	s[16] = '\0';
	findmin(&mintop, &minleft, hesh);
	while (--i >= 0)
	{
		hesh[i] = hesh[i] - minleft - mintop;
		hesh[i] -= hesh[i] / 5;
		s[hesh[i]] = '#';
	}
	return (s);
}

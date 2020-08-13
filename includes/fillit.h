/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:29:54 by iuolo             #+#    #+#             */
/*   Updated: 2019/11/21 16:48:49 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SQR_SIDE 4
# define SQR_SIZE 16
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_piece
{
	char			**data;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_slice
{
	int				i;
	int				k;
	int				max_h;
	int				max_l;
	char			**arr;
	t_piece			*tmp;
}					t_slice;

typedef struct		s_bctrk
{
	int				i;
	int				j;
	char			**tmp_map;
	int				k;
	int				err;
}					t_bctrk;

typedef struct		s_trans
{
	char			**arr;
	int				i;
	int				k;
	int				c;
	int				j;
}					t_trans;

typedef struct		s_map
{
	int				size;
	char			**arr;
}					t_map;

int					g_size;
char				*normit(int *hesh);
void				findmin(int *mintop, int *minleft, int *hesh);
int					validit(int r, char *buff, int *hesh);
int					corrfigit(int *hesh);
int					*cntit(char *s, int **hesh);
int					ft_main(char **fill);
char				**ft_create_map(void);
int					ft_clean(char **map);
void				ft_printmap(char **map);
t_piece				*ft_transfer(char **fill);
int					ft_backtracking(t_piece *tetro, char **map);
int					ft_put(char **field, int i, int k, char **fg);
char				**ft_copy(char **map, int i, int k);

#endif

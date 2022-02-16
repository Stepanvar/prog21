/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:49:14 by ccurie            #+#    #+#             */
/*   Updated: 2022/02/16 22:02:24 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../gnl/get_next_line.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*pick;
	void	*player;
	void	*wall;
	void	*door;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("done\n");
	if (53 == keycode)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	ft_handlemapline(char *mapl, t_vars v)
{
	int	i;

	i = 0;
	while (mapl[i])
	{
		if (1 == mapl[i])
		{
			mlx_put_image_to_window(v.mlx, v.win, v. )
		}
		
	}
	
}

void	ft_maprender(char *file, t_vars v)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		
	}
	
	str = get_next_line(fd);
	
}

int	main(int argc, char *argv[])
{	
	t_vars	vars;
	//int		exit;
	int		w;
	int		h;
	if (argc <= 0)
		return (1);
	ft_maprender(argv, vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1200, 1200, "Check init");
	vars.pick = mlx_xpm_file_to_image(vars.mlx, "sprites/pick.xpm", &w, &h);
	printf("%d, %d\n", w, h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 80, 80);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}

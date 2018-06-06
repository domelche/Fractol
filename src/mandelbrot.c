
#include "../fractol.h"

int		ft_man_iter(t_env *env, int x, int y)
{
	t_ftl	ftl;
	int		i;

	ftl.c_r = (long double)x / env->zoom;
	ftl.c_i = (long double)y / env->zoom;
	ftl.z_r = 0;
	ftl.z_i = 0;
	i = -1;
	while (++i < env->i_max)
	{
		if (ftl.z_r * ftl.z_r +
			ftl.z_i * ftl.z_i >= 4)
			break ;
		ftl.z_tmp = ftl.z_r;
		ftl.z_r = ftl.z_r * ftl.z_r - ftl.z_i * ftl.z_i + ftl.c_r;
		ftl.z_i = 2 * ftl.z_i * ftl.z_tmp + ftl.c_i;
	}
	return (ft_getcolour(i, env->i_max));
}
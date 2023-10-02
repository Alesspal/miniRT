#include "ft_raytracing.h"
#include "ft_mlx.h"
#include <math.h>

// Set up the camera's basis vectors and the virtual screen
void	compute_camera(t_camera *cam, float aspect_ratio)
{
	t_vec	temp_up;

	if ((cam->dir.x == 0 && cam->dir.y == 1 && cam->dir.z == 0)
		|| (cam->dir.x == 0 && cam->dir.y == -1 && cam->dir.z == 0))
	{
		temp_up.x = 0;
		temp_up.y = 0;
		temp_up.z = 1;
	}
	else
	{
		temp_up.x = 0;
		temp_up.y = 1;
		temp_up.z = 0;
	}
	cam->v_screen.d = 1;
	cam->dir = ft_normalize(cam->dir);
	cam->right = ft_normalize(cross_product(cam->dir, temp_up));
	cam->up = ft_normalize(cross_product(cam->right, cam->dir));
	cam->v_screen.width = 2 * cam->v_screen.d * tan(cam->fov * M_PI / 360);
	cam->v_screen.height = cam->v_screen.width / aspect_ratio;
	cam->v_screen.center = vec_add(cam->pos,
			vec_mult(cam->dir, cam->v_screen.d));
	cam->v_screen.top_left = vec_add(vec_sub(cam->v_screen.center,
				vec_mult(cam->right, cam->v_screen.width / 2)),
			vec_mult(cam->up, cam->v_screen.height / 2));
}

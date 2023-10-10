#include "ft_raytracing.h"

// Fill prime ray considering the position and 
// direction of the camera and the pixel position.
void	set_prime_ray(t_ray *pr, t_mlx_win win, t_camera cam, t_point2D p)
{
	double	u;
	double	v;
	t_vec	pixel_pos;

	u = (double)p.x / win.win_w;
	v = (double)p.y / win.win_h;
	pixel_pos = vec_add(cam.v_scr.top_left,
			vec_sub(vec_mult(cam.right, u * cam.v_scr.width),
				vec_mult(cam.up, v * cam.v_scr.height)));
	pr->dir = ft_normalize(vec_sub(pixel_pos, cam.pos));
}

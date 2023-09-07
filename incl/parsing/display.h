#ifndef DISPLAY_H
# define DISPLAY_H

# include "ft_raytracing.h"

void	display_ambient_light(t_ambiant_light ambient_light);
void	display_spot_light(t_spot_light spot_light);
void	display_camera(t_camera camera);
void	display_sphere(t_sphere sphere);
void	display_cylinder(t_cylinder cylinder);
void	display_plan(t_plan plan);
void	display_shapes(t_shapes *shapes);
void	display_scene(t_scene scene);

#endif
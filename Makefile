NAME	=		miniRT

CC		=		gcc
CFLAGS	=		-Wall -Werror -Wextra ${INCL_LIST} -g

LIBFT		=	libft.a
LIBMLX		=	libmlx.a

SRCS_DIR	=	srcs/
INCL_DIR	=	incl/
OBJS_DIR	=	objs/
LIBFT_DIR	=	libft/
LIBMLX_DIR	=	mlx/
PARSING_DIR	=	parsing/

INCL_LIST	=	-I${LIBFT_DIR} \
				-I${LIBMLX_DIR} \
				-I${INCL_DIR} \
				-I${INCL_DIR}${PARSING_DIR}

SRCS_LIST	=	main.c \
				ft_control.c \
				ft_img_pix_put.c \
				ft_vector.c \
				ft_vector2.c \
				ft_shapes.c \
				ft_phong.c \
				get_n.c \
				ft_color.c \
				${PARSING_DIR}display.c \
				${PARSING_DIR}element_parsing.c \
				${PARSING_DIR}element_parsing2.c \
				${PARSING_DIR}element_parsing3.c \
				${PARSING_DIR}element_parsing4.c \
				${PARSING_DIR}file_parsing.c \
				${PARSING_DIR}get_value.c \
				${PARSING_DIR}get_value2.c \
				${PARSING_DIR}parsing_utils.c \
				${PARSING_DIR}parsing_utils2.c \
				draw_scene.c \
				intersection.c \
				intersection2.c \
				init.c \
				prime_ray.c \
				compute_equation.c

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

all:			${LIBFT} ${LIBMLX} ${NAME}

${OBJS_DIR}:
				mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
				mkdir -p $(dir $@)
				${CC} ${CFLAGS} ${INCL_LIST} -c $< -o $@

${LIBFT}:
				${MAKE} -C ${LIBFT_DIR}

${LIBMLX}:
				${MAKE} -C ${LIBMLX_DIR}

${NAME}:		${OBJS_DIR} ${OBJS}
				${CC} ${OBJS} -L${LIBFT_DIR} -lft -L${LIBMLX_DIR} -lmlx -framework OpenGL -framework AppKit ${CFLAGS} -o ${NAME}

clean:
				rm -rf ${OBJS_DIR}
				${MAKE} -C ${LIBFT_DIR} clean
				${MAKE} -C ${LIBMLX_DIR} clean

fclean:			clean
				rm -f ${NAME}
				${MAKE} -C ${LIBFT_DIR} fclean
				${MAKE} -C ${LIBMLX_DIR} clean

re:				fclean all

.PHONY:			all clean fclean re
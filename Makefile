NAME	=		Minirt

CC		=		gcc
CFLAGS	=		-Wall -Werror -Wextra ${INCL_LIST} -g

LIBFT		=	libft.a
LIBMLX		=	libmlx.a

SRCS_DIR	=	srcs/
INCL_DIR	=	incl/
OBJS_DIR	=	objs/
LIBFT_DIR	=	libft/
LIBMLX_DIR	=	mlx/

INCL_LIST	=	-I${LIBFT_DIR} \
				-I${LIBMLX_DIR} \
				-I${INCL_DIR}

SRCS_LIST	=	main.c \
				ft_control.c \
				ft_img_pix_put.c \
				ft_vector.c \
				ft_shapes.c \
				rayshooter.c

OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

all:			${LIBFT} ${LIBMLX} ${NAME}

${OBJS_DIR}:
				mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o:	${SRCS_DIR}%.c
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
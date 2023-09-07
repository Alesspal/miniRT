/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:15:27 by jdecorte          #+#    #+#             */
/*   Updated: 2023/08/30 12:47:54 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFFER_SIZE 256

char	*get_next_line(int fd);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *string, int searchedChar);

void	ft_bzero2(void *s, size_t n);
void	*ft_calloc2(size_t elementCount, size_t elementSize);

size_t	ft_strlen2(const char *theString);

#endif

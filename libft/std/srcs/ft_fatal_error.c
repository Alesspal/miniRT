/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesspal <alesspal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:44:31 by alesspal          #+#    #+#             */
/*   Updated: 2023/08/30 09:57:31 by alesspal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/incl/ft_printf.h"

void	ft_fatal_error(char *err_msg, int ret_err)
{
	perror(err_msg);
	exit(ret_err);
}

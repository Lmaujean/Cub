/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:17:07 by jbuan             #+#    #+#             */
/*   Updated: 2021/11/30 18:17:09 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"
#include "../inc/macro.h"
#include <unistd.h>
#include <stdlib.h>

void	end(char **str, int error, char *error_msg)
{
	free_split(str);
	error_san(error, error_msg);
}

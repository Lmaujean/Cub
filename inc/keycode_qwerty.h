/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_qwerty.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:49:48 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 18:49:49 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_QWERTY_H
# define KEYCODE_QWERTY_H

# ifdef __linux__
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ECHAP 65307
# elif __APPLE__
#  define UP 13
#  define DOWN 1 
#  define LEFT 0
#  define RIGHT 2
#  define UP_ARROW 126
#  define DOWN_ARROW 125 
#  define LEFT_ARROW 123
#  define RIGHT_ARROW 124
#  define ESC 53
# endif


#endif

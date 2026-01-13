/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:12:41 by aoberon           #+#    #+#             */
/*   Updated: 2026/01/13 17:30:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "srcs.h"
# include "textures.h"
# include "minilibx-linux/mlx.h"

# define WINDOW_WIDTH 1900
# define WINDOW_HEIGHT 1000

# define CHUNK_SIZE 128
// IF CHANGE CHUNK_SIZE, CHANGE QTE_CHUNK_SIZE (= CHUNK_SIZE * 4)

# define RATIO_PLAYER_SIZE_X 0.75
# define RATIO_PLAYER_SIZE_Y 0.90
// Size player = chunk size - X % chunk size

# define SPEED 700

# define SPEED_GUARD 450

# define FPS_CAP 125
// -> 0.008


// |---- ANIMATION ----|

# define DELAY_ANIMATION 0.08

// |---- GUARD ----|

# define DELAY_TURN_GUARD 2.5
# define DELAY_GUARD_CHASE_PLAYER 6

// |---- INVINCIBILITY FRAME ----|

# define DELAY_IFRAMES 1.5

// |---- QTE ----|

# define QTE_EASY	1
# define DELAY_QTE	0.001
# define QTE_CHUNK_SIZE 512
// QTE_CHUNK_SIZE = CHUNK_SIZE * 4

// |---- DYNAMITE ----|

# define BOMB_TIMING 1.3
# define BOMB_NUMBER 5
# define DELAY_BOMB_EXPLOSION 0.7
# define DEBUG_DYNAMITE 0

// ----------------------------------------------------------------

# define IS_DEBUG 0

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define COLLECTABLE 20
# define COLLECTED 21
# define COLLECTED_ON_GUARD 22

# define EXIT_FAILED_LEVEL 2

#endif

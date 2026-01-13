/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:25:57 by aoberon           #+#    #+#             */
/*   Updated: 2026/01/13 17:30:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRCS_H
# define SRCS_H

#include "structs.h"

int					ft_printf(const char *string, ...);

// |================================================|
// |					SRC_CAMERA					|
// |================================================|

// |----------- CAMERA_CHUNKS ----------|

int					is_in_chunks_to_display(int *chunks_to_display,
						int size, int chunk);
void				get_chunks_to_display(t_game *game, t_camera *camera);

// |---------- CAMERA ----------|

void				camera(t_game *game, t_camera *camera, t_player *player);

// |================================================|
// |					SRC_DEBUG					|
// |================================================|

// |----------- DEBUG_DISPLAY ----------|

void				debug_fps(t_game *game);

// |================================================|
// |					SRC_DISPLAY					|
// |================================================|

// |----------- DISPLAY_FEATURES_ANIMATION_MOVE --------|

int					get_guard_idle_frame(t_guard *guard);

t_sprite			*get_guard_move_animation(t_game *game, t_guard *guard,
						t_avatar_animation *animation);
t_sprite			*get_player_move_animation(t_game *game, t_player *player,
						t_avatar_animation *animation);

// |----------- DISPLAY_FEATURES_ANIMATION --------|

void				get_animation(t_game *game, t_gameplay *gameplay,
						t_sprite *sprite, int chunk_pos);

// |----------- DISPLAY_FEATURES_AT_START --------|

int					display_tutorial(t_game *game, t_gameplay *gameplay,
						t_window *window, int tutorial_status);

int					display_title_screen(t_game *game, t_window *window,
						int is_title_screen);

// |----------- DISPLAY_FEATURES_BOMB -----------|

void				display_bomb(t_player *player, t_bomb *bomb,
						t_game *game, t_window *window);

// |----------- DISPLAY_FEATURES_CHARACTER_ON_MAP -----------|

void				get_characters_on_map(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_FEATURES_DIALOGUE_MAIN -----------|

void				display_dialogue(t_game *game,
						t_texts_box_list *texts_box_list);

// |----------- DISPLAY_FEATURES_DIALOGUE_TEXT_BOX -----------|

void				display_one_node_texts_box(t_game *game, t_window *window,
						t_text_box text_box);

void				display_character(t_game *game, t_window *window,
						t_vector_2 pos_display, char character);

// |----------- DISPLAY_FEATURES_ENDING_SCREEN -----------|

int					display_end_screen(t_game *game, int is_end);

// |----------- DISPLAY_GUARDS_MAIN ---------|

void				display_guards(t_game *game, t_gameplay *gameplay,
						t_window *window, t_guard *guards);

// |----------- DISPLAY_FEATURES_GUARDS_TURN_FOV ---------|

void				turn_guards(t_guard *guard);

// |----------- DISPLAY_FEATURES_MAIN ----------|

void				display_gameplay_features(t_game *game,
						t_gameplay *gameplay, t_window *window);
void				display_hp(t_window *window, t_player *player, int color);

// |----------- DISPLAY_FEATURES_MENU ----------|

int					display_menu(t_game *game, t_window *window, int is_pause);

// |----------- DISPLAY_FEATURES_QTE_LAUNCH ---------|

void				launch_qte(t_game *game, t_qte *qte, t_guard *guard);

// |----------- DISPLAY_FEATURES_QTE_MAIN --------|

int					display_qte(t_game *game, t_qte *qte, t_player *player,
						t_guard *guards);

// |----------- DISPLAY_FEATURES_UI_BOXS ---------|

void				display_ui_boxs(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_FEATURES_UI_MAIN ---------|

void				display_one_str(t_game *game, t_vector_2 pos_display,
						char *text, int size_letter);
void				display_ui(t_game *game, t_window *window,
						t_gameplay *gameplay);

// |----------- DISPLAY_PLAYER ---------|

void				display_player(t_game *game, t_window *window,
						t_player *player, t_sprite *sprite);

// |----------- DISPLAY_SPRITES --------|

void				update_frame(t_sprite *sprite);
void				display_sprites(t_game *game, t_camera *camera,
						t_window *window);

// |----------- DISPLAY_TOOLS_1 ----------|

void				img_pix_put(t_img *img, int x, int y, int color);
void				put_image_to_image(t_img *window_img,
						t_vector_2 pos, t_img *img);
void				memcpy_img(t_img *img_dst, t_vector_2 pos_dst,
						t_img *img_src, t_vector_2 *pos_src);

__uint32_t			get_color_pixel(t_img *img, int i, int j);

// |----------- DISPLAY_TOOLS_2 ----------|

void				display_one_sprite_with_transparency(t_window *window,
						t_sprite *sprite, t_vector_2 pos);
void				put_image_to_image_with_limit(t_img *window_img,
						t_vector_2 pos, t_img *img, t_vector_2 *limit);

// |================================================|
// |					SRC_EVENT					|
// |================================================|

// |----------- EVENTS_DIALOGUE_MAIN -----------|

int					display_victory_text(t_game *game,
						int *victory_text_status);

void				set_tutorial_dialogue(t_game *game);
void				set_text_box_events_start(t_game *game);
void				get_text_box_events(t_game *game, t_gameplay *gameplay);

// |----------- EVENTS_DIALOGUE_UTILS ----------|

void				get_text_box_events_remain_zero_collectible(t_game *game,
						t_gameplay *gameplay);
void				get_text_box_events_remain_one_collectible(t_game *game,
						t_gameplay *gameplay);

// |----------- EVENTS_DIALOGUE_TOOLS ----------|

void				add_one_text_to_dialogue(t_game *game,
						t_texts_box_list **texts_box_list, t_text *text,
						int talking_character);

// |----------- TEXTS_BOX_LIST_UTILS_FREE ----------|

void				ft_lstclear_texts_box(t_texts_box_list **lst);
void				ft_lstdelone_texts_box(t_texts_box_list *lst);

// |----------- TEXTS_BOX_LIST_UTILS_MAIN ----------|

int					ft_lstsize_texts_box(t_texts_box_list *lst);
void				ft_lstadd_back_texts_box(t_texts_box_list **lst,
						t_texts_box_list *new);

t_texts_box_list	*ft_lstnew_texts_box(t_text_box *text_box);
t_texts_box_list	*ft_lstlast_texts_box(t_texts_box_list *lst);
t_texts_box_list	*ft_lstfirst_texts_box(t_texts_box_list *lst);

// |====================================================|
// |					SRC_GAMEPLAY					|
// |====================================================|

// |--------- GAMEPLAY_COLLECTIBLE_HELPER ----------|

bool				check_all_collectibles_have_been_collected(
						t_collectible *collectible, int size);

// |--------- GAMEPLAY_COLLECTIBLE ----------|

void				collected_one_collectible(t_game *game,
						t_gameplay *gameplay, int pos, int new_state);

// |--------- GAMEPLAY_COLLIDER_CHECK_TILE ----------|

void				check_tile(t_game *game, char tile, int pos);

// |----------- GAMEPLAY_COLLIDER_TOOLS -----------|

int					check_wall_collider(char *map, t_collider chunks);

void				check_collider(t_game *game, t_player *player,
						t_guard *guards);

t_collider			get_collider_on_move(t_f_vector_2 *move, t_player *player,
						int x_max);

// |---------- GAMEPLAY_COLLIDER_POSITIONS ----------|

int					is_inside_area(t_f_vector_2 pos, t_f_vector_2 pos_size,
						t_f_vector_2 area, t_f_vector_2 size_area);

void				check_collider_positions(t_game *game,
						t_player *player, t_guard *guards);

// |---------- GAMEPLAY_FEATURES_BOMB ----------|

void				make_bomb_explode(t_game *game, t_bomb bomb);
void				set_bomb_position(t_bomb *bomb, t_player *player,
						t_game *game);

// |---------- GAMEPLAY_FEATURES_QTE ----------|

int					get_pressed(t_game *game, t_qte *qte, t_guard *guard);

void				end_qte(t_qte *qte, t_guard *guard, int not_pressed_flag);

// |----------- GAMEPLAY_FEATURES ----------|

void				gameplay_features(t_game *game, t_gameplay *gameplay);

// |---------- GAMEPLAY_MOVE_ANIMATION ---------|

void				move_animation(t_vector_2 look_dir, t_sprite *sprite);

// |----------- GAMEPLAY_RESTART_GAME ----------|

void				restart_the_game(t_game *game);

// |---------- GAMEPLAY_MOVE_GUARD ---------|

void				move_guard(t_game *game, t_guard *guard, t_player *player);

// |----------- GAMEPLAY_MOVE_GUARD_TOOLS ----------|

void				set_guard_pos(t_game *game, t_guard *guard,
						t_f_vector_2 move);
void				set_guard_look_dir(t_guard *guard, t_player *player,
						t_f_vector_2 move);
void				set_move_guard(t_guard *guard, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move_guard(t_f_vector_2 *move, t_guard *guard,
						t_vector_2 collider, t_vector_2 axe);

t_collider			get_collider_guard_on_move(t_f_vector_2 *move,
						t_guard *guard, int x_max);

// |---------- GAMEPLAY_MOVE_PLAYER_ANIMATION ----------|

void				move_player_animation(t_player *player, t_sprite *sprite);

// |----------- GAMEPLAY_MOVE_PLAYER -----------|

void				move_player(t_game *game, t_player *player);

// |---------- GAMEPLAY_MOVE_PLAYER_TOOLS ----------|

void				set_player_look_dir(t_player *player);
void				set_player_pos(t_player *player, t_f_vector_2 move);
void				set_move_player(t_player *player, t_f_vector_2 *move,
						double delta_time, t_vector_2 axe);
void				restrict_move(t_f_vector_2 *move, t_player *player,
						t_vector_2 collider, t_vector_2 axe);

// |---------- GAMEPLAY_PLAYER_TO_CHARACTER_FUNCTIONS ----------|

void				set_player_to_main(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_eater(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_thief(t_game *game, t_gameplay *gameplay,
						t_player *player);
void				set_player_to_bomber(t_game *game, t_gameplay *gameplay,
						t_player *player);

// |----------- GAMEPLAY_PLAYER_TO_CHARACTER_MAIN ----------|

void				set_player_to_character(t_game *game, t_gameplay *gameplay,
						t_player *player, int character);

// |---------- GAMEPLAY_TOOLS ----------|

void				calculate_fps(int *fps, double *delta_time);

// |============================================|
// |					SRC_GNL					|
// |============================================|

char				*get_next_line(int fd);

// |================================================|
// |					SRC_HANDLER					|
// |================================================|

// |----------- HANDLER_BOMB -----------|

void				handle_bomb(int keysym, t_game *game);

// |----------- HANDLER_DIALOGUE -----------|

int					handle_dialogue_next_text_box(t_game *game);
int					handle_dialogue(int keysym, t_game *game);

// |---------- HANDLER_GAME_FEATURES ---------|

int					close_game(t_game *game);
int					secure_lost_focus(t_game *game);
int					handle_end_screen(int keysym, t_game *game);
int					handle_title_screen(int keysym, t_game *game);

void				handle_out_game_features(int keysym, t_game *game);

// |----------- HANDLER_PAUSE_MENU -----------|

void				handle_pause_menu(int keysym, t_game *game);

// |---------- HANDLER_PLAYER_FEATURES ---------|

void				handle_qte(int keysym, t_game *game);
void				handle_change_character_player(int keysym, t_game *game,
						t_gameplay *gameplay, t_player *player);

// |---------- HANDLER_PLAYER_MOVEMENT ---------|

void				handle_player_move_press(int keysym, t_game *game);
void				handle_player_move_release(int keysym, t_game *game);

// |---------- HANDLER ---------|

int					handle_keypress(int keysym, t_game	*game);
int					handle_keyrelease(int keysym, t_game *game);

// |---------- HANDLER_TUTORIAL ---------|

int					handle_tutorial(int keysym, t_game *game);

// |================================================|
// |					SRC_INIT					|
// |================================================|

// |---------- INIT_ASSETS_SPRITES_ANIMATIONS ----------|

void				init_sprites_animations(t_game *game, t_sprite *sprite,
						char character);

// |----------- INIT_SPRITES_ASSETS_HELPER_COLLECTIBLES -----------|

void				init_sprites_assets_collectibles(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_OTHERS -----------|

void				init_sprites_assets_others(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_PLAYER -----------|

void				init_sprites_assets_player(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_UI_TEXT_BOX -----------|

void				init_sprites_assets_ui_text_box(t_game *game,
						t_sprites_assets *assets);

// |----------- INIT_SPRITES_ASSETS_HELPER_WALLS -----------|

void				init_sprites_assets_walls(t_game *game,
						t_sprites_assets *assets);

// |---------- INIT_ASSETS_SPRITES_IMAGES ----------|

void				init_xpm_file(t_game *game, void *ptr, char *path,
						t_img *img);

char				*find_sprite_path(t_game *game, char *start_path,
						int frame);

t_img				new_resize_img(t_game *game, void *ptr, t_img *src,
						t_vector_2 dst_size);

// |----------- INIT_SPRITES_ASSETS_MAIN -----------|

void				init_sprites_assets(t_game *game);

// |----------- INIT_SPRITES_ASSETS_TOOLS ----------|

void				init_one_sprite_asset(t_game *game, t_sprite **sprite,
						t_init_sprite_asset_args init_sprite_asset_args);

// |---------- INIT_AVAIBABLE_CHARACTER ---------|

int					*init_available_character(char **argv, int *argc_index,
						int *chosen_character);

// |----------- INIT_GAME_CAMERA -----------|

void				init_camera(t_game *game);

// |---------- INIT_GAME_MAIN ----------|

void				init_game(t_game *game, int *available_character,
						int chosen_character);
void				bzero_game(t_game *game);

// |----------- INIT_GAME_WINDOW -----------|

void				init_window(t_game *game);

// |---------- INIT_GAMEPLAY_ALL_TEXTS ---------|

void				init_all_texts_of_the_game(t_game *game,
						t_gameplay *gameplay);

// |---------- INIT_GAMEPLAY_AVATAR_ANIMATION ----------|

t_avatar_animation	*init_avatar_animation(t_game *game,
						t_sprites_assets *assets);

// |---------- INIT_GAMEPLAY_COLLECTIBLE ---------|

void				init_collectible(t_game *game, t_gameplay *gameplay,
						t_collectible *collectible);

// |---------- INIT_GAMEPLAY_GUARD ---------|

void				set_guard_fov_direction(t_guard *guard);
void				init_guards(t_game *game, t_guard *guards);

// |---------- INIT_GAMEPLAY_HELPER ---------|

void				init_gameplay_helper(t_game *game, t_gameplay *gameplay,
						int *available_character, int chosen_character);

// |---------- INIT_GAMEPLAY_MAIN ----------|

void				init_gameplay(t_game *game, int *available_character,
						int chosen_character);

// |----------- INIT_GAMPEPLAY_PLAYER ----------|

void				init_player(t_game *game, t_player *player,
						int chosen_character);
void				init_explosion_pos(t_game *game, t_bomb *bomb, bool alloc);

// |----------- INIT_GAMEPLAY_RANDOM_ELEMENTS ----------|

void				random_look_direction(t_guard *guard);
void				put_unavailable_character_on_map(t_game *game,
						t_gameplay *gameplay);

// |----------- INIT_GAMEPLAY_TEXT_BOX ----------|

void				init_one_text_box(t_game *game, t_gameplay *gameplay,
						t_text_box *text_box, int talking_character);

// |----------- INIT_SPRITES_MAIN ----------|

void				init_sprites(t_game *game);
void				sprite_cpy(t_sprite *new, t_sprite *src);
void				get_random_frame_animation(t_sprite *sprite,
						char character);

// |----------- INIT_SPRITES_ORGANIZATION -----------|

void				get_wall_image(t_game *game, t_sprite **sprite, int pos);

// |================================================|
// |					SRC_PARSING					|
// |================================================|

// |----------- LST_MAP_UTILS ----------|

int					ft_lstsize(t_lst_map *lst);

void				ft_lstclear(t_lst_map **lst);
void				ft_lstadd_back(t_lst_map **lst, t_lst_map *new);

t_lst_map			*ft_lstnew(void *content);
t_lst_map			*ft_lstlast(t_lst_map *lst);

// |----------- PARSE_MAP_UTILS_CHAR_MANIPULATIONS ---------|

char				*line_to_tab(char *line);
char				*char_2d_to_1d(char **map_2d, int x, int y);

// |----------- PARSE_MAP_UTILS_CHECK_MAP ----------|

int					is_ber(char *file_name);
int					is_closed(char **map, int x, int y);
int					is_rectangle(t_lst_map *lst, int size);
int					has_all_characters(char **map, int x, int y);

// |----------- PARSE_MAPS ---------|

int					parse_map(char *file_name, char **map,
						t_vector_2 *map_vector);

// |====================================================|
// |					SRC_PATHFINDING					|
// |====================================================|

// |----------- A_STAR_ALGORITHM -----------|

int					a_star(t_level *level, int pos, int end_pos);

// |----------- A_STAR_UTILS -----------|

int					dst_to_end(int pos, int end, int x);
int					calculate_dir_pos(int dir, int pos, int x);
int					find_character(t_level *level, char searched_char);

t_path_map			*init_path_map(t_level *level);

// |---------- PATHFINDING ---------|

int					pathfinding(t_game *game);

// |================================================|
// |					SRC_TOOLS					|
// |================================================|

// |---------- EXIT_ERROR_MESSAGE ----------|

int					exit_map_error(char **map_2d, int y);
int					exit_pathfinding_error(t_level *level, char flag,
						int pos_error);

void				exit_arg_error(void);
void				exit_option_error(int *available_character);

// |---------- FREE_ASSETS ---------|

void				free_one_sprite(void *ptr, t_sprite *sprite);
void				free_assets(void *ptr, t_sprites_assets *assets);

// |---------- FREE_UTILS ----------|

void				free_2d_char_tab(char **tab, int y);
void				free_dialogue(t_texts_box_list *dialogue);
void				free_text_box_text_pages(t_text_box *text_box);
void				free_map_sprites(t_sprite **map_sprites, int size);
void				free_collectibles(t_collectible *collectible,
						char *collectible_code, int size);

// |----------- FREE -----------|

void				exit_game(t_game game, int exit_code, const char *error);

// |----------- MEM_FUNCTIONS ----------|

char				*ft_strdup(const char *s);

void				ft_bzero(void *s, size_t n);
void				ft_memset(void *addr, int value, size_t n);

void				ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_calloc(size_t nmemb, size_t size);

// |---------- POSITIONS_TOOLS----------|

int					pos_to_chunk(int x, int y, int x_max);

t_vector_2			chunk_to_pixel_pos(int chunk, int x_max);
t_f_vector_2		chunk_to_pixel_f_pos(int chunk, int x_max);

// |----------- UTILS ----------|

int					ft_nbrlen(int nb);
int					is_equals(char *s1, char *s2);

void				ft_itoa(int n, char result[10]);

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlen(const char *s);

// |----------- VECTOR_FUNCTIONS -----------|

t_f_vector_2		normalize(t_vector_2 vector);
t_f_vector_2		direction_normalized(t_vector_2 src, t_vector_2 dest);

//========================================

// |----------- GAME -----------|

void				start_game(t_game *game);

// |---------- SO_LONG ---------|

//------------------------------------------

// |================================================|
// |					TEMPORARY					|
// |================================================|

void				debug_fps(t_game *game);
void				ft_print_1d_to_2d(t_level *level);
void				ft_print_lst_map(t_lst_map *lst_map);
void				ft_print_map(char **map, int x, int y);
void				ft_print_path_map_status(t_level *level);
void				debug_player_box_collider(t_player *player);
void				ft_print_path_map(t_level *level, int end_pos);
void				ft_print_chunk_pos(t_vector_2 *chunk_pos, int c_count);
void				ft_print_collectibles_pos(t_vector_2 *c_pos, int c_count);

#endif
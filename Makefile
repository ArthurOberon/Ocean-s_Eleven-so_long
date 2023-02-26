SO_LONG 		=	so_long

CC 				=	gcc
CFLAGS 			=	-Wall -Wextra #-Werror
INCLUDES_DIR 	=	include/
SRC_DIR 		=	src/
OBJ_DIR 		=	obj/
INCLUDES_H		=	-I./$(INCLUDES_DIR)
MLX_FLAGS 		=	-L$(INCLUDES_DIR) -lmlx -lX11 -lXext
DEPS 			=	$(INCLUDES_DIR)so_long.h

# ALL SOURCES FOR SO_LONG
SL_SRCS 		=	$(addprefix $(SRC_DIR), \
					so_long.c \
					\
					)

PS_OBJ 			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SL_SRCS))

all: $(SO_LONG)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_H) -c -o $@ $<

$(SO_LONG): $(PS_OBJ)
	@echo "\e[36mMaking $(SO_LONG)...\e[0m"
	@$(CC) $(CFLAGS) $(INCLUDES_H) $(PS_OBJ) -o $(SO_LONG)
	@echo "\e[32mDone !\e[0m"

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\e[31mObject files removed.\e[0m"

fclean:	clean
	@rm -f $(SO_LONG)
	@echo "\e[31m$(SO_LONG) removed.\e[0m"

re:		fclean all

.PHONY = all bonus clean fclean re

##
## EPITECH PROJECT, 2024
## my_rpg
## File description:
## Makefile
##

TARGET			=	my_rpg
CC				=	gcc -g3
CXXFLAGS		=	-g3 -Wall -Werror -Wextra

HSRC			=	-lcsfml-graphics -lcsfml-audio -lcsfml-system		\
					-lcsfml-window -lm
HRCS			=	include

LDFLAGS			=	-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib/ ${HSRC}	\
					-Llib/commons/ -lcommons -I $(HRCS)
CPPFLAGS		=	-I/opt/homebrew/Cellar/csfml/2.5.2_1/include/

BUILD_DIR 		=	build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS_FILE:.c=.o))

SRCS_FILE	=	src/main.c							\
				src/algorithm/path_finding.c		\
				src/dialogues/dialogues_parser.c	\
				src/dialogues/dialogues_registry.c	\
				src/dialogues/dialogue_player.c		\
				src/dialogues/dialogues_service.c	\
				src/enemy/enemy.c					\
				src/enemy/enemy_utils.c				\
				src/enemy/enemy_utils2.c			\
				src/event/close_event.c				\
				src/event/event_handler.c			\
				src/event/input_event.c				\
				src/event/input_event2.c			\
				src/game/game_phase.c				\
				src/game/game_save.c				\
				src/gui/button/button_registry.c	\
				src/gui/button/game_menu_buttons.c	\
				src/gui/interface/back_button.c		\
				src/gui/interface/main_menu.c		\
				src/gui/interface/game_menu.c		\
				src/gui/interface/save_menu.c		\
				src/gui/interface/settings_menu.c	\
				src/map/collision.c					\
				src/map/map_layers.c				\
				src/map/rect_from_id.c				\
				src/map/tiles_manager.c				\
				src/object/tile_object.c			\
				src/player/player_combat.c			\
				src/player/player_sprite.c			\
				src/render/render_window.c			\
				src/render/resolutions.c			\
				src/scheduler/task_daemon.c			\
				src/scheduler/task_provider.c		\
				src/settings/settings_import.c		\
				src/sound/sound_registry.c			\
				src/utils/calculate_pos.c			\
				src/utils/utf8_to_32.c				\
				src/utils/square_tile_from_pos.c	\
				src/utils/csfml_str.c				\
				src/utils/texture_util.c			\
				src/dialogues/dialogue_npc.c		\
				src/item/inventory_item.c			\
				src/dialogues/telep.c				\
				src/music/music_player.c			\

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	${CC} -c $< -o $@ ${LDFLAGS} ${CPPFLAGS}

$(TARGET):	$(OBJS)
	@make -C lib/commons
	${CC} ${CXXFLAGS} -o $(TARGET) ${OBJS} ${LDFLAGS} ${CPPFLAGS}

re:	fclean all

clean:
	@make -C lib/commons clean
	rm -rf $(BUILD_DIR)

fclean:	clean
	@make -C lib/commons fclean
	rm -f $(TARGET)

.PHONY: all re clean fclean

##
## EPITECH PROJECT, 2024
## my_rpg
## File description:
## Makefile
##

TARGET			=	my_rpg
CC				=	gcc
CXXFLAGS		=	-g3 -Wall -Werror -Wextra

HSRC			=	-lcsfml-graphics -lcsfml-audio -lcsfml-system		\
					-lcsfml-window -lm
HRCS			=	include

LDFLAGS			=	-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib/ ${HSRC}	\
					-Llib/commons/ -lcommons -I $(HRCS)
CPPFLAGS		=	-I/opt/homebrew/Cellar/csfml/2.5.2_1/include/

BUILD_DIR 		=	build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS_FILE:.c=.o))

SRCS_FILE	=	src/main.c					\
				src/assets.c				\
				src/event/close_event.c		\
				src/event/event_handler.c	\
				src/map/map_layers.c		\
				src/map/rect_from_id.c		\
				src/render/camera.c			\
				src/render/render_window.c	\
				src/render/resolutions.c	\

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

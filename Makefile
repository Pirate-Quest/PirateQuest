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

LDFLAGS			=	-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib/ ${HSRC}	\
					-Llib/commons/ -lcommons -I $(HRCS)

CPPFLAGS		=	-I/opt/homebrew/Cellar/csfml/2.5.2_1/include/
APPLE_OBJS		=	${SRCS_FILE:.c=.o}
HRCS			=	include
BUILD_DIR 		=	build
OBJS			=	$(addprefix $(BUILD_DIR)/, $(SRCS_FILE:.c=.o))

SRCS_FILE	=	src/main.c				\
				src/assets.c			\
				src/map/rect_from_id.c	\

apple: ${APPLE_OBJS}
	@make -C lib/commons
	${CC} ${CXXFLAGS} -o my_rpg ${APPLE_OBJS} ${LDFLAGS} ${CPPFLAGS}

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TARGET):	$(OBJS)
	@make -C lib/commons
	$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIB)						\
	-Llib/commons/ -lcommons -I $(HRCS)									\
	-lm -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window	\

re:	fclean all

clean:
	@make -C lib/commons clean
	rm -rf $(BUILD_DIR)
	rm -fr $(APPLE_OBJS)

fclean:	clean
	@make -C lib/commons fclean
	rm -f $(TARGET)

.PHONY: all apple re clean fclean

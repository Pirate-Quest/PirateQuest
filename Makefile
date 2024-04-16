##
## EPITECH PROJECT, 2024
## my_rpg
## File description:
## Makefile
##

CC	=	gcc -g3

SRCS_FILE	=	src/main.c				\
				src/assets.c			\
				src/map/rect_from_id.c	\

HRCS	=	include

TARGET	=	my_rpg

BUILD_DIR = build

OBJS	=	$(addprefix $(BUILD_DIR)/, $(SRCS_FILE:.c=.o))

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TARGET):	$(OBJS)
	@make -C lib/commons
	$(CC) -o $(TARGET) $(OBJS) $(LIB)									\
	-Llib/commons/ -lcommons -I $(HRCS)									\
	-lm -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window	\

re:	fclean all

clean:
	@make -C lib/commons clean
	rm -rf $(BUILD_DIR)

fclean:	clean
	@make -C lib/commons fclean
	rm -f $(TARGET)

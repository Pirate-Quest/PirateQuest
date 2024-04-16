##
## EPITECH PROJECT, 2024
## my_paint
## File description:
## Makefile
##

CC	=	gcc -c -g3

ARRC	=	ar rc

SRCS	=	my_str_dup.c								\
			my_rev_str.c								\
			my_getnbr.c								\
			my_str_utils.c								\
			my_str_to_word_array.c						\
			my_put_int.c								\
			my_strcat.c									\
			my_strcpy.c									\
			my_strcmp.c									\
			count_args.c								\
			my_str_isalpha.c							\
			my_str_isnum.c								\
			my_memset.c									\
			my_hashtable/algorithm/key_hash.c			\
			my_hashtable/dump/hashtable_dump.c			\
			my_hashtable/manager/hashtable_delete.c		\
			my_hashtable/manager/hashtable_insert.c		\
			my_hashtable/provider/hashtable_provider.c	\
			my_hashtable/search/hashtable_search.c		\
			my_list/my_list_manager.c					\
			my_list/my_list_provider.c					\

HRCS	=	../../include

TARGET	=	libcommons.a

BUILD_DIR = build

OBJS	=	$(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

CFLAGS	=	-I $(HRCS)

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o:	%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TARGET):	$(OBJS)
	$(ARRC) $(TARGET) $(OBJS)

clean:
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(TARGET)

re:	fclean all

.PHONY:	all clean fclean re

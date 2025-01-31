.SILENT:
.PHONY: all clean fclean fsanitize re

NAME=libft.a

#------------------------------------------------------------------------------#
# 							VARIABLES										   #
#------------------------------------------------------------------------------#

SRCS_DIR= cfiles/

SRCS = \
	isdigit                     \
	isalpha                     \
	isalnum                     \
	isascii                     \
	isprint                     \
	strlen                      \
	memset                      \
	bzero                       \
	memcpy                      \
	memmove                     \
	strlcpy                     \
	strlcat                     \
	toupper                     \
	tolower                     \
	strchr                      \
	strrchr                     \
	strncmp                     \
	memchr                      \
	memcmp                      \
	strnstr                     \
	atoi                        \
	strdup                      \
	calloc                      \
	split                       \
	substr                      \
	strjoin                     \
	strcmp				        \
	strtrim                     \
	itoa                        \
	putchar_fd                  \
	putstr_fd                   \
	putendl_fd                  \
	putnbr_fd                   \
	strmapi                     \
	striteri                    \
	printf		                \
	putchar			            \
	putstr			            \
	putnbrbase		            \
	handle                      \
	lstnew_bonus                \
	lstadd_front_bonus          \
	lstsize_bonus               \
	lstlast_bonus               \
	lstadd_back_bonus           \
	lstdelone_bonus             \
	lstclear_bonus              \
	lstiter_bonus               \
	lstmap_bonus

OBJS_DIR      = .objs/

SRC			  = $(patsubst %, $(SRCS_DIR)ft_%.c, $(CFILES))

OBJS		  = $(patsubst $(SRCS_DIR)%.c, .objs/%.o, $(SRC))

INCS          = includes/libft.h

DEPS          = $(OBJS:.o=.d)


#------------------------------------------------------------------------------#
# 							COMMANDS									       #
#------------------------------------------------------------------------------#

CC= cc

CFLAGS       = -Werror -Wextra -Wall -MMD -MP

RM           = rm -rf

CFSIGSEV     = -fsanitize=address

AR           = ar rcs

#------------------------------------------------------------------------------#
# 							RULES											   #
#------------------------------------------------------------------------------#


all:$(NAME)


$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@


fsanitize:
	$(MAKE) CFLAGS="$(CFLAGS) $(CFSIGSEV)"


clean:
	$(RM) $(OBJS_DIR)


fclean:clean
	$(RM) $(NAME)


re:fclean all
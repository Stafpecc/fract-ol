.SILENT:
.PHONY: all clean fclean re main help fsanitize valgrind

#------------------------------------------------------------------------------#
# 							VARIABLES										   #
#------------------------------------------------------------------------------#


NAME            = fractol
EXEC			= exec/fractol.out

CFILES_DIR		= cfiles/
OBJS_DIR		= .objs/
EXEC_DIR		= exec/
LIBFT_DIR		= libft/
LIBFT_TARGET	= ../libft/libft.a
LIBMLX_DIR		= .minilibx-linux/
INC			    = -I includes/\
				  -I $(LIBMLX_DIR)\
				  -I $(LIBFT_DIR)includes/
INCLUDEF		= includes/fractol.h
LIBFT_NAME		= libft.a
LIBMLX_NAME		= libmlx.a
LIBFT_PATH      = $(LIBFT_DIR)$(LIBFT_NAME)
LIBMLX_PATH     = $(LIBMLX_DIR)$(LIBMLX_NAME)

MAIN			= main.c

CFILES          = \
		fractol             \
		graphics            \
		init                \
		render              \
		mandelbrot          \
		window              \
		hook				\
		julia				\
		burning_ship		\
		animation


SRC				= $(patsubst %, $(CFILES_DIR)ft_%.c, $(CFILES))
OBJS			= $(patsubst $(CFILES_DIR)%.c, .objs/%.o, $(SRC))


#------------------------------------------------------------------------------#
# 							COMMANDS									       #
#------------------------------------------------------------------------------#


RM 				= rm -f
RM_DIR			= rm -rf
CC				= cc
AR				= ar -rcs
AR_EXTRACT      = ar -x
MAKE			= make

CFLAGS 			= -Wall -Wextra -Werror -g -pg
CFSIGSEV        = -fsanitize=address

PURPLE          = \033[1;35m
GREEN           = \033[1;32m
RED             = \033[1;31m
YELLOW          = \033[33m
BOLD_UNDERLINE  = \033[1;4m
RESET           = \033[0m


#------------------------------------------------------------------------------#
# 							COMPILATION RULES								   #
#------------------------------------------------------------------------------#


all: $(NAME)

fsanitize:
	$(MAKE) CFLAGS="$(CFLAGS) $(CFSIGSEV)"


valgrind: $(EXEC_G3)
		$(MAKE) $(EXEC_G3)
		if [ -z "$(FLAGS)" ]; then \
			echo "$(PURPLE)Please define FLAGS (e.g., make valgrind FLAGS=1).$(RESET)"; \
		elif [ "$(FLAGS)" -eq 1 ]; then \
			valgrind --leak-check=full ./$(EXEC); \
		elif [ "$(FLAGS)" -eq 2 ]; then \
			valgrind --track-origins=yes ./$(EXEC); \
		elif [ "$(FLAGS)" -eq 3 ]; then \
			valgrind --tool=massif ./$(EXEC); \
		else \
			echo "$(RED)Invalid FLAGS value. Use 1, 2, or 3.$(RESET)"; \
		fi; \
		echo "$(RED)Deleting $(EXEC)...$(RESET)"; \
		if [ -f $(EXEC) ]; then $(RM) $(EXEC); fi; \
		echo "$(GREEN)Deleting $(EXEC) completed successfully!$(RESET)"

	
main: all
	echo "$(PURPLE)Execute $(EXEC)...$(RESET)"
	echo "$(PURPLE)─────────────────────────────────────────────────$(RESET)"

	if [ -z $(FLAG) ]; then \
		echo "$(PURPLE)Please define FLAG with make main FLAG=X\n\
	where X = 1 for mandelbrot\n \
		= 2 for julia\n \
		= 3 for burning_ship."; \
	elif [ $(FLAG) -eq 1 ]; then \
		./$(EXEC) mandelbrot; \
	elif [ $(FLAG) -eq 2 ]; then \
		./$(EXEC) julia; \
	elif [ $(FLAG) -eq 3 ]; then \
		./$(EXEC) burning_ship; \
	else \
		echo "$(RED)Invalid FLAG value. Use 1, 2, or 3.$(RESET)"; \
	fi

	echo "$(PURPLE)─────────────────────────────────────────────────$(RESET)"
	echo "$(GREEN)Exec of $(EXEC) completed successfully!$(RESET)"
	echo "$(RED)Deleting $(EXEC)...$(RESET)"

		$(RM) $(EXEC)

	echo "$(GREEN)Deleting $(EXEC) completed successfully!$(RESET)"



clean:
	echo "$(RED)Deleting object files...$(RESET)"

		$(RM_DIR) $(OBJS_DIR)
		$(MAKE) -sC $(LIBFT_DIR) clean
		$(MAKE) -sC $(LIBMLX_DIR) clean
		$(RM) massif.out*

	echo "$(GREEN)Deleting object files completed successfully!$(RESET)"


fclean: clean
	echo "$(RED)Deleting $(NAME)...$(RESET)"

		$(RM_DIR) $(EXEC_DIR)
		$(MAKE) -sC $(LIBFT_DIR) fclean

	echo "$(GREEN)Deleting $(NAME) completed successfully!$(RESET)"
	
	echo "$(RED)"
	echo "┌──────────────────────────────────────────────────────────┐"
	echo "│      Deletion finished successfully! ( ◔ ω◔) ノシ        │"
	echo "└──────────────────────────────────────────────────────────┘"
	
	echo "                          ╱|、"
	echo "                        (˚ˎ 。7"
	echo "                         |、˜|"
	echo "                        じしˍ,)ノ"
	
	echo "$(RESET)"


re : fclean all


help:
	echo "$(YELLOW)\n                  =============================="
	echo "                        $(BOLD_UNDERLINE)AVAILABLE TARGETS:$(RESET)"
	echo "$(YELLOW)                  ==============================$(RESET)"
	echo " "
	echo "$(GREEN)───────────────────────────────────────────────────────────────────"
	echo " "
	echo "$(GREEN)  all$(RESET)           $(PURPLE)-$(RESET) Compile the library and generate $(NAME)"
	echo "$(GREEN)  clean$(RESET)         $(PURPLE)-$(RESET) Remove all object files and temporary build files"
	echo "$(GREEN)  fclean$(RESET)        $(PURPLE)-$(RESET) Perform 'clean' and remove the $(NAME) archive"
	echo "$(GREEN)  re$(RESET)            $(PURPLE)-$(RESET) Rebuild everything from scratch"
	echo "$(GREEN)  main$(RESET)          $(PURPLE)-$(RESET) Compile and run the main program with $(NAME)"
	echo "$(GREEN)  valgrind$(RESET)      $(PURPLE)-$(RESET) Run Valgrind with optional FLAGS for memory analysis"
	echo " "
	echo "           .  $(GREEN)FLAGS=1$(RESET) $(PURPLE)->$(RESET) Leak check"
	echo "           .  $(GREEN)FLAGS=2$(RESET) $(PURPLE)->$(RESET) Track origins of errors"
	echo "           .  $(GREEN)FLAGS=3$(RESET) $(PURPLE)->$(RESET) Memcheck, a memory error detector"
	echo " "  
	echo "$(GREEN)  fsanitize$(RESET)     $(PURPLE)-$(RESET) Compile with sanitizers to detect memory errors"
	echo " "
	echo "$(GREEN)───────────────────────────────────────────────────────────────────"


#------------------------------------------------------------------------------#
# 							DIRECTORY CREATION RULES						   #
#------------------------------------------------------------------------------#


$(OBJS_DIR):
	echo "$(YELLOW)Creating directory $(OBJS_DIR)...$(RESET)"
		
		mkdir -p $(OBJS_DIR)

$(EXEC_DIR):
	echo "$(YELLOW)Creating $(EXEC_DIR) directory...$(RESET)"

		mkdir -p $(EXEC_DIR)


#------------------------------------------------------------------------------#
# 							BUILD RULES										   #
#------------------------------------------------------------------------------#


$(NAME): $(OBJS) $(LIBFT_NAME) $(LIBMLX_NAME) $(INCLUDEF) | $(EXEC_DIR)
	echo "$(PURPLE)Compiling $(NAME) in progress...$(RESET)"

		$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBFT_PATH) $(LIBMLX_PATH) -lXext -lX11 -lm

	echo "$(GREEN)$(EXEC) completed successfully!$(RESET)"

	echo "$(GREEN)"
	echo "┌───────────────────────────────────────────────────────────┐"
	echo "│      Compilation finished successfully! ᕕ(⌐■_■)ᕗ ♪♬       │"
	echo "└───────────────────────────────────────────────────────────┘"

	echo "                      ☆  *    .      ☆"
	echo "                        ∧＿∧   ∩    * ☆"
	echo "                 *  ☆ ( ・∀・)/ ."
	echo "                  .  ⊂      ノ* ☆"
	echo "                ☆ * (つ   ノ  .☆"
	echo "                      (ノ"

	echo "$(RESET)"


$(LIBFT_NAME): FORCE
		$(MAKE) -sC $(LIBFT_DIR)


$(LIBMLX_NAME):
		$(MAKE) -sC $(LIBMLX_DIR)


$(OBJS_DIR)%.o: $(CFILES_DIR)%.c | $(OBJS_DIR)
	echo "$(PURPLE)Compiling $<...$(RESET)"

		$(CC) $(CFLAGS) $(INC) -c $< -o $@

	echo "$(GREEN)$< completed successfully!$(RESET)"


$(EXEC_G3): $(LIBFT_NAME) $(LIBMLX_NAME) $(OBJS)
	echo "$(PURPLE)Compiling $< with g3...$(RESET)"
		
		$(CC) $(CFLAGS) -o $(EXEC) -g3 $(OBJS) $(LIBMLX_PATH) $(LIBFT_PATH) -lXext -lX11 -lm

	echo "$(GREEN)$< completed successfully!$(RESET)"

FORCE:
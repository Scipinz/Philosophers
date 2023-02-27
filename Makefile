# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2023/02/14 15:13:51 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	philo

#==============================================================================: Source to object conversion 
OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
RM			=	rm -rf
AR			=	ar rcs
MKDIR		=	mkdir -p objs
HEADERS		= 	-I include

#==============================================================================: Source files 
SRCS		=	$(addprefix src/, \
					main.c \
				$(addprefix utils/, \
					get_time.c \
					initiate_data.c \
					validate_args.c) \
				$(addprefix functions/, \
					ft_calloc.c \
					ft_atoi.c) \
				$(addprefix simulation/, \
					threads.c \
					sim_exec.c \
				)

#==============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#==============================================================================: Make commands
all: message $(NAME)

#==============================================================================: Main compile
$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME) -lpthread
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

#==============================================================================: File compile
objs/%.o: srcs/%.c
	@$(MKDIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#==============================================================================: Build messages
message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

#==============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@echo "$(RED)🧹Removed object folders!$(RESET)"

#==============================================================================: Remove object files and executables
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🧹Removed $(NAME)!$(RESET)"

#==============================================================================: Remove object files and executables then remake executables
re: fclean all

.PHONY: all clean fclean re message run objs
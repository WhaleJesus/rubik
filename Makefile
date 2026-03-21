# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklaps <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 18:03:47 by sklaps            #+#    #+#              #
#    Updated: 2025/05/27 18:03:59 by sklaps           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = rubik
CC       = c++
CFLAGS   = -Wall -Wextra -Werror -std=c++98
DFLAGS   = -MMD -MF $(@:.o=.d)
DATE     = 27/5/2025
HASH     =

################################################################################
#                              SOURCE FILES                                    #
################################################################################

FILE_EXTENSION = .cpp

SRCS_PATH      = ./src
INCLUDE_PATH   = ./src

SRCS_LIST      = CubeClass.cpp

MAIN           = main.cpp

################################################################################
#                              OBJECT FILES                                    #
################################################################################

OBJS_DIR   = objs

OBJS       = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:$(FILE_EXTENSION)=.o))
OBJ_MAIN   = $(OBJS_DIR)/$(MAIN:.cpp=.o)

DEPS       = $(OBJS:.o=.d)
DEPS_MAIN  = $(OBJ_MAIN:.o=.d)

################################################################################
#                                  RULES                                       #
################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(OBJ_MAIN)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJ_MAIN)
	@echo "\033[32m✔️ Build successful: $(NAME)\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_PATH)/%.cpp | $(OBJS_DIR)
	@echo "\033[38;2;255;255;0mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) $(DFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

$(OBJ_MAIN): $(SRCS_PATH)/$(MAIN) | $(OBJS_DIR)
	@echo "\033[38;2;255;255;0mCompiling $<...\033[0m"
	$(CC) $(CFLAGS) $(DFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mfclean done\033[0m"
re: fclean all

-include $(DEPS) $(DEPS_MAIN)

.PHONY: all clean fclean re

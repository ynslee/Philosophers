# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 18:00:34 by yoonslee          #+#    #+#              #
#    Updated: 2023/07/19 18:06:41 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread -g

PHILO_SRC = philo \
		utils \
		error_check

PHILO_PRE = $(addprefix ./src/, $(PHILO_SRC))
PHILO_SUFF = $(addsuffix .c, $(PHILO_PRE))

.PHONY = all, clean, fclean, re
all: $(NAME)

$(NAME):
	cc $(FLAGS) $(PHILO_SUFF) -o $(NAME)

clean:
	rm -rf $(SRCSO)

fclean: clean
	rm -rf $(NAME)

re: fclean all

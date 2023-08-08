# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 18:00:34 by yoonslee          #+#    #+#              #
#    Updated: 2023/08/08 15:19:00 by yoonseonlee      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread -g

PHILO_SRC = args_check \
		init \
		main \
		philo_fest \
		philo \
		print \
		utils 

PHILO_PRE = $(PHILO_SRC)
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

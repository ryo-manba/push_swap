# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 23:18:37 by rmatsuka          #+#    #+#              #
#    Updated: 2021/06/11 09:51:18 by rmatsuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS			=	push_swap
CHECKER		=	checker
PS_DIR		=	push_swap_src/
CHECKER_DIR	=	checker_src/

all:		$(PS) $(CHECKER) ## Create push_swap & checker

$(PS):
			make -C $(PS_DIR)

$(CHECKER):
			make -C $(CHECKER_DIR)

clean:
			make clean -C $(PS_DIR)
			make clean -C $(CHECKER_DIR)

fclean:	clean
			make fclean -C $(CHECKER_DIR)
			make fclean -C $(PS_DIR)

re:		fclean all

.PHONY:	re all clean fclean

test:	all ## Run all test
		test/test.sh

test3:	all ## Run three test
		test/3test.sh

test5all: all ## Run five all test
		test/5test_all.sh

test5:	all ## Run five test
		test/5test.sh

test100:	all ## Run one hundred test
		test/100test.sh

test500:	all ## Run five hundred test
		test/500test.sh

.PHONY: test test3 test5 test5all test100 test500 help ghost

help:
	@grep -E '^[a-zA-Z_-]+\d*:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'


ghost:	## busters
		@echo "                      __---__"
		@echo "                    _-       /--______"
		@echo "               __--( /     \ )XXXXXXXXXXXv."
		@echo "             .-XXX(   O   O  )XXXXXXXXXXXXXXX-"
		@echo "            /XXX(       U     )        XXXXXXX"
		@echo "          /XXXXX(              )--_  XXXXXXXXXXX"
		@echo "         /XXXXX/ (      O     )   XXXXXX   \XXXXX"
		@echo "         XXXXX/   /            XXXXXX   \__ \XXXXX"
		@echo "         XXXXXX__/          XXXXXX         \__---->"
		@echo " ---___  XXX__/          XXXXXX      \__         /"
		@echo "   \-  --__/   ___/\  XXXXXX            /  ___--/="
		@echo "    \-\    ___/    XXXXXX              '--- XXXXXX"
		@echo "       \-\/XXX\ XXXXXX                      /XXXXX"
		@echo "         \XXXXXXXXX   \                    /XXXXX"
		@echo "          \XXXXXX      >                 _/XXXXX/"
		@echo "            \XXXXX--__/              __-- XXXX/"
		@echo "             -XXXXXXXX---------------  XXXXXX-"
		@echo "                \XXXXXXXXXXXXXXXXXXXXXXXXXX/"
		@echo "                  ""VXXXXXXXXXXXXXXXXXXV"""

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 09:55:26 by eralonso          #+#    #+#              #
#    Updated: 2022/12/09 10:05:30 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;30m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
CIAN		=	\033[1;36m

NAME		=	push_swap
CHECKER		=	checker

LIBRARY		=	lib/
LIB			=	lib/lib.a

HEADER		=	./inc/

SRC_DIR		=	src/
EXEC_DIR	=	src/exec/
MOVE_DIR	=	src/moves/
UTIL_DIR	=	src/utils/
OBJ_DIR		=	obj/

F_EXECS		=	push_swap ft_check_input ft_stacks ft_sort
F_UTILS		=	ft_err_cntl
F_MOVES		=	ft_moves ft_combs
FILES		=	${F_EXECS} ${F_UTILS} ${F_MOVES}

EXECS		=	$(addprefix ${SRC_DIR}, $(addsuffix .c, ${F_EXECS}))
UTILS		=	$(addprefix ${UTIL_DIR}, $(addsuffix .c, ${F_UTILS}))
MOVES		=	$(addprefix ${MOVE_DIR}, $(addsuffix .c, ${F_MOVES}))

OBJS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .o, ${FILES}))
DEPS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .d, ${FILES}))

INCLUDE		=	-I ${HEADER}
RM			=	rm -rf
MKD			=	mkdir -p
MK			=	Makefile
CFLAGS		=	-Wall -Wextra -Werror

${OBJ_DIR}%.o	:	${SRC_DIR}*/%.c ${MK} ${LIB}
	@${MKD} $(dir $@)
	@printf "${PINK}Compiling: ${YELLOW}$<...							\r${DEF_COLOR}"
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all		:
	@$(MAKE) make_lib
	@$(MAKE) ${NAME}

${NAME}		::	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o $@
	@echo "\n${GREEN}Push_swap has been compiled${DEF_COLOR}"

${NAME}		::
	@echo "${YELLOW}Nothing to be done for 'push_swap'${DEF_COLOR}"

make_lib	:
	@$(MAKE) -C ${LIBRARY}

clean		:
	@$(MAKE) clean -C ${LIBRARY}
	@${RM} ${OBJ_DIR}
	@echo "${RED}All OBJS && DEPS has been removed${DEF_COLOR}"

fclean		:
	@$(MAKE) clean
	@$(MAKE) fclean -C ${LIBRARY}
	@${RM} ${NAME} ${CHECKER}
	@echo "${RED}Program has been removed${DEF_COLOR}"

re		:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "${CIAN}Push_swap has been recompiled${DEF_COLOR}"

.PHONY		: all clean fclean re make_lib

-include	${DEPS}

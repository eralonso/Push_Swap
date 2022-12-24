# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eralonso <eralonso@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 09:55:26 by eralonso          #+#    #+#              #
#    Updated: 2022/12/23 19:30:46 by eralonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
BLACK		=	\033[1;30m
RED		=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
PINK		=	\033[1;35m
CIAN		=	\033[1;36m

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/NAME-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
NAME		=	push_swap
CHECKER		=	checker

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/LIBRARY/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
NAME		=	push_swap
LIBRARY		=	lib/
LIB		=	lib/lib.a

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/HEADERS/-/-/-/-/-/-//-/-/-/-/-/-/-/-/-/-/#
HEADER		=	./inc/
C_HEADER	=	./bonus/inc/

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/DIRS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
SRC_DIR		=	src/
EXEC_DIR	=	src/exec/
MOVE_DIR	=	src/moves/
UTIL_DIR	=	src/utils/
OBJ_DIR		=	objs/

C_SRC_DIR	=	bonus/src/
C_EXEC_DIR	=	bonus/src/exec/
C_MOVE_DIR	=	bonus/src/moves/
C_UTIL_DIR	=	bonus/src/utils/
C_OBJ_DIR	=	bonus/objs/

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/FILES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
F_EXECS		=	push_swap ft_check_input ft_stacks \
			ft_sort ft_sort_massive
F_UTILS		=	ft_utils ft_management_nodes
F_MOVES		=	ft_moves ft_combs

C_F_EXECS	=	ft_checker_bonus ft_check_input_bonus \
			ft_stacks_bonus
C_F_UTILS	=	ft_utils_bonus
C_F_MOVES	=	ft_moves_bonus ft_combs_bonus \
			ft_choose_move_bonus

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/SRCS-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
EXECS		=	$(addprefix ${EXEC_DIR}, $(addsuffix .c, ${F_EXECS}))
UTILS		=	$(addprefix ${UTIL_DIR}, $(addsuffix .c, ${F_UTILS}))
MOVES		=	$(addprefix ${MOVE_DIR}, $(addsuffix .c, ${F_MOVES}))
SRCS		=	${EXECS} ${UTILS} ${MOVES}

C_EXECS		=	$(addprefix ${C_EXEC_DIR}, $(addsuffix .c, ${C_F_EXECS}))
C_UTILS		=	$(addprefix ${C_UTIL_DIR}, $(addsuffix .c, ${C_F_UTILS}))
C_MOVES		=	$(addprefix ${C_MOVE_DIR}, $(addsuffix .c, ${C_F_MOVES}))
C_SRCS		=	${C_EXECS} ${C_UTILS} ${C_MOVES}

#/-/-/-/-/-/-/-/-/-/-/-/-/-/OBJS && DEPS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
OBJS		=	$(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})
DEPS		=	${OBJS:.o=.d}

C_OBJS		=	$(addprefix ${C_OBJ_DIR}, ${C_SRCS:.c=.o})
C_DEPS		=	${C_OBJS:.o=.d}

DEPS_SRCS	=	lib/*/objs/src/*/*.o
#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/COMANDS/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
INCLUDE		=	-I ${HEADER}
C_INCLUDE	=	-I ${C_HEADER}
RM		=	rm -rf
MKD		=	mkdir -p
MK		=	Makefile
CFLAGS		=	-Wall -Wextra -Werror

#/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/RULES/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/#
${OBJ_DIR}%.o	:	%.c ${DEPS_SRCS} ${MK}
	@${MKD} $(dir $@)
	@printf "${PINK}\rCompiling: ${YELLOW}$<...						${DEF_COLOR}\r"
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

${C_OBJ_DIR}%.o	:	%.c ${DEPS_SRCS} ${MK}
	@${MKD} $(dir $@)
	@printf "${PINK}\rCompiling: ${YELLOW}$<...						${DEF_COLOR}\r"
	${CC} -MT $@ ${CFLAGS} -MMD -MP ${C_INCLUDE} -c $< -o $@

all				:
	@$(MAKE) make_lib
	@$(MAKE) ${NAME}

${NAME}			::	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o $@
	@echo "\n${GREEN}Push_swap has been compiled${DEF_COLOR}"

${NAME}			::
	@echo "${YELLOW}Nothing to be done for 'push_swap'${DEF_COLOR}"

bonus			:
	@$(MAKE) make_lib
	@$(MAKE) ${CHECKER}

${CHECKER}		::	${C_OBJS}
	@${CC} ${CFLAGS} ${C_OBJS} ${LIB} -o $@
	@echo "\n${GREEN}Checker has been compiled${DEF_COLOR}"

${CHECKER}		::
	@echo "${YELLOW}Nothing to be done for 'checker'${DEF_COLOR}"
make_lib		:
	@$(MAKE) -C ${LIBRARY}

clean			:
	@$(MAKE) clean -C ${LIBRARY}
	@${RM} ${OBJ_DIR}
	@echo "${RED}All OBJS && DEPS has been removed${DEF_COLOR}"

fclean			:
	@$(MAKE) clean
	@$(MAKE) fclean -C ${LIBRARY}
	@${RM} ${NAME} ${CHECKER}
	@echo "${RED}Program has been removed${DEF_COLOR}"

re				:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "${CIAN}Push_swap has been recompiled${DEF_COLOR}"

.PHONY			: all clean fclean re make_lib bonus

-include		${DEPS}
-include		${C_DEPS}

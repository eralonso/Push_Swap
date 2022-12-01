NAME		=	push_swap
CHECKER		=	checker

LIBRARY		=	ft_printf/
LIB		=	ft_printf/libftprintf.a

HEADER		=	./inc/

SRC_DIR		=	src/
EXEC_DIR	=	src/exec/
UTIL_DIR	=	src/utils/
OBJ_DIR		=	obj/

F_EXECS		=	push_swap ft_check_input ft_stacks
F_UTILS		=	ft_exit ft_nodes
FILES		=	${F_EXECS} ${F_UTILS}

EXECS		=	$(addprefix ${SRC_DIR}, $(addsuffix .c, ${F_EXECS}))
UTILS		=	$(addprefix ${UTIL_DIR}, $(addsuffix .c, ${F_UTILS}))

OBJS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .o, ${FILES}))
DEPS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .d, ${FILES}))

INCLUDE		=	-I ${HEADER}
RM		=	rm -rf
MKD		=	mkdir -p
MK		=	Makefile
CFLAGS		=	-Wall -Wextra -Werror

${OBJ_DIR}%.o	:	${SRC_DIR}/*/%.c ${MK} ${LIB}
	@${MKD} $(dir $@)
	@printf "Compiling $<...				\r"
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all		:
	@$(MAKE) make_lib
	@$(MAKE) ${NAME}

${NAME}		::	${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o $@

${NAME}		::
	@echo ""
	@echo "Nothing to be done for 'push_swap'."

make_lib	:
	@$(MAKE) -C ${LIBRARY}

clean		:
	@$(MAKE) clean -C ${LIBRARY}
	@${RM} ${OBJ_DIR}
	@echo "All OBJS && DEPS has been removed"

fclean		:
	@$(MAKE) clean
	@$(MAKE) fclean -C ${LIBRARY}
	@${RM} ${NAME} ${CHECKER}
	@echo "Program has been removed"

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY		: all clean fclean re make_lib

-include	${DEPS}

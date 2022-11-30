NAME		=	push_swap

HEADER		=	./inc/

LIB		=	ft_printf/libftprintf.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/

FILES		=	push_swap ft_moves 

SRCS		=	$(addprefix ${SRC_DIR}, $(addsuffix .c, ${FILES}))
OBJS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .o, ${FILES}))
DEPS		=	$(addprefix ${OBJ_DIR}, $(addsuffix .d, ${FILES}))

INCLUDE		=	-I ${HEADER}
RM		=	rm -rf
MKD		=	mkdir -p
MK		=	Makefile
CFLAGS		=	-Wall -Wextra -Werror

${OBJ_DIR}%.o	:	${SRC_DIR}%.c ${MK} ${LIB}
	@${MKD} $(dir $@)
	@printf "Compiling $<...				\r"
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all		:
	@$(MAKE) make_lib
	@$(MAKE) ${NAME}

${NAME}		::	${OBJS}
	${CC} ${CFLAGS} ${LIB} ${OBJS} -o $@

${NAME}		::
	@echo "Nothing to be done for 'push_swap'."

make_lib	:
	@$(MAKE) -C ft_printf

.PHONY		: all clean fclean re make_lib

-include	${DEPS}

TARG	= a.out
NAME	= libftprintf.a
ODIR	= ./bin
SDIR	= ./src
SRCS	= $(shell find $(SDIR) -name '*.c')
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
LDFLAGS	= -L/Users/ccurie/practiceinprog/clanguage/prog21/base_print/ -lftprintf
CFLAGS	= -Wall -Wextra -g $(AFL)
RM		= rm -rf
CC		= cc 
.PHONY: all
all: $(NAME)
#$(TARG): $(NAME) main.c
#	$(CC) main.c -L/Users/ccurie/practiceinprog/clanguage/prog21/base_print/ -lftprintf
$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< -MMD

-include $(DEPS)
.PHONY: clean
clean:
	$(RM) $(NAME) $(TARG)
.PHONY: fclean
fclean: clean
	$(RM) $(OBJS) $(DEPS)
.PHONY: re
re: fclean all

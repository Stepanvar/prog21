NAME	= libft
ODIR	= ./bin
SDIR	= ./src
SRCS	= $(shell find $(SDIR) -name '*.c')
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
CFLAGS	= -Wall -Wextra -Werror -g $(BSIZE)
BSIZE	= -D BUFFER_SIZE=42
RM		= rm -rf
CC		= gcc 
.PHONY: all
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< -MMD

-include $(DEPS)
.PHONY: clean
clean:
	$(RM) $(NAME)
.PHONY: fclean
fclean: clean
	$(RM) $(OBJS) $(DEPS)
.PHONY: re
re: fclean all
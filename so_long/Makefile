NAME	= so_long.out
ODIR	= ./bin
SDIR	= ./src
SRCS	= $(shell find $(SDIR) -name '*.c')
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
CFLAGS	= -Wall -Wextra -g $(AFL)
LDFLAGS	= -Ldisplayer/ -lproject
CC	= gcc
RM	= rm -rf

.PHONY: all
all: MK $(NAME)
MK:
	make -C gnl/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -Lminilibx -lmlx -framework OpenGL -framework AppKit -Lgnl -lgnl

$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iminilibx -Ignl -c -o $@ $< -MMD

-include $(DEPS)
.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) $(ODIR)

.PHONY: re
re: fclean all

NAME	= getnl.exe
ODIR	= ./bin
SDIR	= ./src
SRCS	= $(SDIR)/get_next_line.c #$(SDIR)/get_next_line_utils.c
OBJS	= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))
CFLAGS	= -Wall -Wextra -Werror -g $(AFL)
RM		= rm -rf
CC		= /C/Users/user/gcc/bin/x86_64-w64-mingw32-gcc.exe 
.PHONY: all
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

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

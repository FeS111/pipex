MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

VPATH = src

# Compiler Variables
CC		 = cc
# CFLAGSS	 = -Wall -Wextra -Werror -g
INCFLAG	 = -I src -I libft

AR		 = ar
ARFLAGS  = -rcs
# File Variables
NAME	    = pipex
SRC		    = $(addprefix src/, main.c util.c)
OBJ		    = $(addprefix _bin/,$(notdir $(SRC:.c=.o)))
SRCBONUS	= $(addprefix src/, main_bonus.c util.c)
OBJBONUS	= $(addprefix _bin/,$(notdir $(SRCBONUS:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	$(CC) -o $(NAME) $(CFLAGSS) $(INCFLAG) $(OBJ) libft/libft.a 

bonus: $(OBJBONUS) | libft/libft.a
	$(CC) -o $(NAME) $(CFLAGSS) $(INCFLAG) $(OBJBONUS) libft/libft.a 

libft:
	@if [ ! -d "libft" ]; then git clone https://github.com/fes111/libft.git; fi
	
libft/libft.a: libft
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

san: CFLAGSS += -fsanitize=address

san: re

run: $(NAME)
	- ./$(NAME)

clean:
	@rm -f $(OBJ) $(OBJBONUS)

fclean:	clean
	@rm -f $(NAME)
	(cd libft && make fclean)

re:		fclean all

all:	$(NAME)

.PHONY: clean fclean re all run bonus
NAME = push_swap
B_NAME = checker

CC = gcc
GFLAGS = -Wall -Werror -Wextra

SRCDIR = src/
OBJDIR = obj/

B_SRCDIR = bonus/
B_OBJDIR = bonus_obj/

SRCFILES = bucket_utils.c free_it.c get_index.c handle_exit.c ll.c main.c push.c ranking.c read_args.c reverse_rotate.c rotate.c sort_alogs.c sort_utils.c swap.c utils.c valid_number.c
SRCOBJ = $(SRCFILES:%.c=$(OBJDIR)%.o)

B_SRCFILES = free_it_bonus.c handle_exit_bonus.c ll_bonus.c ll_cmd_bonus.c main_bonus.c push_bonus.c ranking_bonus.c read_args_bonus.c reverse_rotate_bonus.c rotate_bonus.c run_cmds_bonus.c swap_bonus.c utils_bonus.c valid_number_bonus.c
B_SRCOBJ = $(B_SRCFILES:%.c=$(B_OBJDIR)%.o)

LIBFT = ./libft
HEADERS = -I include/push_swap.h -I $(LIBFT)/headers
B_HEADERS = -I include/push_swap_bonus.h -I $(LIBFT)/headers

.PHONY: all libft bonus clean fclean re

all: libft $(NAME)

$(NAME): $(SRCOBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(GFLAGS) $(SRCOBJ) $(LIBFT)/libft.a -o $(NAME)

bonus: $(B_SRCOBJ)
	$(MAKE) -C $(LIBFT)
	@if [ ! -f $(B_NAME) ]; then \
		$(CC) $(GFLAGS) $(B_SRCOBJ) $(LIBFT)/libft.a -o $(B_NAME); \
	fi

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p ${OBJDIR}
	$(CC) -c $(GFLAGS) -o $@ $<

$(B_OBJDIR)%.o: $(B_SRCDIR)%.c
	@mkdir -p $(B_OBJDIR)
	$(CC) -c $(GFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJDIR)
	rm -rf $(B_OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all


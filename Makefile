# 実行ファイル名
NAME	= libftprintf.a


# コンパイル対象ファイル
SRCS = \
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_strlen.c\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memmove.c\
ft_tolower.c\
ft_toupper.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strchr.c\
ft_strrchr.c\
ft_strncmp.c\
ft_memchr.c\
ft_memcmp.c\
ft_strnstr.c\
ft_atoi.c\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_striteri.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c

# 生成したいオブジェクト
OBJS	= $(SRCS:.c=.o)

# コンパイラの指定
CC		= cc

# コンパイルオプション
CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: ${NAME}

.PHONY: clean
clean: 
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f ${NAME}

.PHONY: re
re: fclean all
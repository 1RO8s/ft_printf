# 実行ファイル名
NAME	= libftprintf.a


# コンパイル対象ファイル
SRCS = \
ft_isalpha.c\


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
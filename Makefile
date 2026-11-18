CC = gcc
CFLAGS = -Wall -Wextra -g -Iheaders

TARGET = tpAeds

SRCS = main.c \
	sources/pokemon.c \
    sources/pokelist.c \
	sources/pokecenter.c \

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	fel /f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run

# Intruções de como rodar o tp:
# No Windows (PowerShell ou CMD, usando MinGW):
#   Compilar:  mingw32-make
#   Rodar:     .\tpAeds.exe   (ou: mingw32-make run)
#   Limpar:    mingw32-make clean
#
# No Linux (Terminal, usando GCC e Make):
#   Compilar:  make
#   Rodar:     ./tpAeds      (ou: make run)
#   Limpar:    make clean
CC = gcc
CFLAGS = -Wall -Wextra -g -Iheaders

# detecta Windows vs Linux para definir extensao .exe, comando de limpeza (del/rm) e execucao
ifeq ($(OS),Windows_NT)
	TARGET = tpAeds.exe
	RM_CMD = -del /f /q $(subst /,\,$(OBJS)) $(TARGET) 2>nul
	RUN_CMD = $(TARGET)
else
	TARGET = tpAeds
	RM_CMD = rm -f $(OBJS) $(TARGET)
	RUN_CMD = ./$(TARGET)
endif

SRCS = main.c \
	sources/pokemon.c \
    sources/pokelist.c \
	sources/pokecenter.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM_CMD)

run: $(TARGET)
	$(RUN_CMD)

.PHONY: clean run
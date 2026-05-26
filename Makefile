CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = src/main.c \
      src/engine.c \
      src/render.c \
      src/sort_bubble.c \
      src/sort_quick.c \
      src/sort_bogo.c

OUT = sortingVisualizer

all:
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)

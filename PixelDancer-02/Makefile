CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lgl2d -lglfw -lXrandr -lX11 -lGL -lGLU -lpthread -lm
INCDIR=-I.
LIBDIR=-L.
OBJS=game.o palette.o grid.o canvas.o

game: $(OBJS)
	$(CC) -o game $(OBJS) $(LIBDIR) $(LFLAGS)

game.o: game.c
	$(CC) -c game.c $(INCDIR) $(CFLAGS)

palette.o: palette.c
	$(CC) -c palette.c $(INCDIR) $(CFLAGS)

grid.o: grid.c
	$(CC) -c grid.c $(INCDIR) $(CFLAGS)

canvas.o: canvas.c
	$(CC) -c canvas.c $(INCDIR) $(CFLAGS)



.PHONY: clean

clean:
	rm $(OBJS) game

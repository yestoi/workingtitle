foo : game.o main.o
		gcc `pkg-config --cflags --libs glib-2.0` -o foo game.o main.o

game.o : game.c
		gcc `pkg-config --cflags --libs glib-2.0` -c game.c

main.o : main.o
		gcc `pkg-config --cflags --libs glib-2.0` -c main.c

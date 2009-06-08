foo : game.o main.o
		gcc -g `pkg-config --cflags --libs glib-2.0` -o foo game.o main.o

game.o : game.c
		gcc -g `pkg-config --cflags --libs glib-2.0` -c game.c

main.o : main.o
		gcc -g `pkg-config --cflags --libs glib-2.0` -c main.c

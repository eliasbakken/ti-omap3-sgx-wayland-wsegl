


LDFLAGS = -shared -lwayland-egl -lpvr2d
LDFLAGS += `pkg-config wayland-client --libs`
CFLAGS=-fPIC -I../libwayland-egl/ -I./ -I../common -I../../doc/reference/
BIN=wayland-egl
LIB=lib$(BIN).so
SRC=wayland-egl.c 

all:
	gcc -o $(LIB) $(SRC) $(CFLAGS) $(LDFLAGS) 

install:
	cp $(LIB) /usr/lib

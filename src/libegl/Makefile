
CFLAGS=-shared -fPIC -Wl,-soname,libEGL.so -I../common/
LDFALGS=-lEGL-sgx -ldl -L/usr/lib/sgx/
SRC=egl.c 

all: 
	gcc $(CFLAGS) -o libEGL.so $(SRC) $(LDFLAGS)

install: 
	cp libEGL.so /usr/lib/




#CC=/home/iagent/workspace/setup-scripts/build/tmp-angstrom_v2013_06-eglibc/sysroots/i686-linux/usr/bin/armv7ahf-vfp-neon-angstrom-linux-gnueabi/arm-angstrom-linux-gnueabi-cpp
CC=gcc
LDFLAGS = -shared -lwayland-egl -lpvr2d
LDFLAGS += `pkg-config wayland-client --libs`
LDFLAGS += `pkg-config wayland-server --libs`
CFLAGS=-fPIC -I../libwayland-egl/ -I./ -I../common
SRC=wayland-sgx-protocol.c waylandwsegl.c ../common/log.c
BIN=waylandwsegl


all:
	$(CC) -o $(BIN).so  $(SRC) $(CFLAGS) $(LDFLAGS)

install:
	cp $(BIN).so /usr/lib/



# This is meant to be run on the host. The other targets, not so much
wayland-scanner=/home/iagent/workspace/setup-scripts/build/tmp-angstrom_v2013_06-eglibc/sysroots/i686-linux/usr/bin/wayland-scanner

headers:
	$(wayland-scanner) code < wayland-sgx.xml > wayland-sgx-protocol.c	
	$(wayland-scanner) server-header < wayland-sgx.xml > wayland-sgx-server-protocol.h
	$(wayland-scanner) client-header < wayland-sgx.xml > wayland-sgx-client-protocol.h


install: 
	scp wayland-sgx-* root@10.24.2.90:/usr/src/wayland-sgx/src/common/

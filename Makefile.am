
include wayland-scanner.mk

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

bin_PROGRAMS = wsegl
wsegl_SOURCES = src/wsegl/waylandwsegl.c

dist_noinst_SCRIPTS = autogen.sh

SUBDIRS = src
dist_doc_DATA = README

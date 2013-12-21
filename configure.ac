AC_INIT([sgx-wayland], 0.1)

AM_CONFIG_HEADER([config.h])
AC_GNU_SOURCE

#AC_CONFIG_HEADERS ([config.h])
AM_INIT_AUTOMAKE([1.11 foreign])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_SRCDIR ([src/libwayland-egl/egl.c])
AC_PROG_CC

AC_CONFIG_FILES([
        Makefile
        src/Makefile
])
AC_OUTPUT

AC_INIT([game], [0.0.1], [metiscus@gmail.com])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])
AM_MAINTAINER_MODE
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AR
LT_INIT
AX_CXX_COMPILE_STDCXX([11],[noext],[mandatory])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile])
PKG_CHECK_MODULES([SDL2], [sdl2])
PKG_CHECK_MODULES([OPENGL], [gl])
AC_CONFIG_MACRO_DIR([m4])
AC_OUTPUT

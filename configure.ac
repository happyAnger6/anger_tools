#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([anger-tools], [0.1], [happyAnger6@163.com])
AC_CONFIG_SRCDIR([src/include/list.h])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE(anger-tools,1.0)

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL
# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS(bzero)
AC_CHECK_FUNCS(vsnprintf)

AC_OUTPUT([Makefile
	   src/lib/Makefile
	   src/algorithms/sorts/Makefile
	   src/algorithms/lists/slist/Makefile
	   src/test/Makefile
	   src/examples/Makefile
	   src/al_c_impl/list/Makefile
	   ])

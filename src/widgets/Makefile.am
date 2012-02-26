#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libwidgets.la

#######################################
# Build information for each library

# Sources for widgets
libwidgets_la_SOURCES = menu.c archivos.c calendario.c dialogos.c listados.c templates.c formularios.c

# Linker options widgetsProgram
#libwidgets_la_LDFLAGS = -lncurses -lcdk

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libwidgets_la_CPPFLAGS = -I$(top_srcdir)/src/include


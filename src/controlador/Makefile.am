#######################################
# The list of libraries we are building seperated by spaces.
# The 'lib_' indicates that these build products will be installed
# in the $(libdir) directory. For example /usr/lib
lib_LTLIBRARIES = libcontrolador.la

#######################################
# Build information for each library

# Sources for funciones
libcontrolador_la_SOURCES = callbacks.c drivers_post.c drivers_pre.c clientes.c insumos.c orden_pedido_producto.c orden_pedido_proveedor.c orden_produccion.c persistencia.c principal.c producto_terminado.c proveedores.c RMPS.c tecnicos.c utils.c 
# Linker options funcionesProgram
#libcontrolador_la_LDFLAGS = 

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
libcontrolador_la_CPPFLAGS = -I$(top_srcdir)/src/include


#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/controlador/insumos.o \
	${OBJECTDIR}/widgets/archivos.o \
	${OBJECTDIR}/controlador/drivers_pre.o \
	${OBJECTDIR}/controlador/utils.o \
	${OBJECTDIR}/controlador/producto_terminado.o \
	${OBJECTDIR}/controlador/tecnicos.o \
	${OBJECTDIR}/widgets/dialogos.o \
	${OBJECTDIR}/controlador/callbacks.o \
	${OBJECTDIR}/widgets/formularios.o \
	${OBJECTDIR}/pruebas.o \
	${OBJECTDIR}/controlador/orden_produccion.o \
	${OBJECTDIR}/controlador/RMPS.o \
	${OBJECTDIR}/controlador/proveedores.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/controlador/drivers_post.o \
	${OBJECTDIR}/widgets/templates.o \
	${OBJECTDIR}/controlador/persistencia.o \
	${OBJECTDIR}/controlador/orden_pedido_proveedor.o \
	${OBJECTDIR}/widgets/menu.o \
	${OBJECTDIR}/controlador/orden_pedido_producto.o \
	${OBJECTDIR}/widgets/calendario.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/controlador/clientes.o \
	${OBJECTDIR}/widgets/listados.o \
	${OBJECTDIR}/controlador/principal.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lcdk -lncurses -ltinfo -lsqlite3

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/Refactor

dist/Debug/GNU-Linux-x86/Refactor: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/Refactor ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/controlador/insumos.o: nbproject/Makefile-${CND_CONF}.mk controlador/insumos.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/insumos.o controlador/insumos.c

${OBJECTDIR}/widgets/archivos.o: nbproject/Makefile-${CND_CONF}.mk widgets/archivos.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/archivos.o widgets/archivos.c

${OBJECTDIR}/controlador/drivers_pre.o: nbproject/Makefile-${CND_CONF}.mk controlador/drivers_pre.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/drivers_pre.o controlador/drivers_pre.c

${OBJECTDIR}/controlador/utils.o: nbproject/Makefile-${CND_CONF}.mk controlador/utils.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/utils.o controlador/utils.c

${OBJECTDIR}/controlador/producto_terminado.o: nbproject/Makefile-${CND_CONF}.mk controlador/producto_terminado.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/producto_terminado.o controlador/producto_terminado.c

${OBJECTDIR}/controlador/tecnicos.o: nbproject/Makefile-${CND_CONF}.mk controlador/tecnicos.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/tecnicos.o controlador/tecnicos.c

${OBJECTDIR}/widgets/dialogos.o: nbproject/Makefile-${CND_CONF}.mk widgets/dialogos.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/dialogos.o widgets/dialogos.c

${OBJECTDIR}/controlador/callbacks.o: nbproject/Makefile-${CND_CONF}.mk controlador/callbacks.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/callbacks.o controlador/callbacks.c

${OBJECTDIR}/widgets/formularios.o: nbproject/Makefile-${CND_CONF}.mk widgets/formularios.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/formularios.o widgets/formularios.c

${OBJECTDIR}/pruebas.o: nbproject/Makefile-${CND_CONF}.mk pruebas.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/pruebas.o pruebas.c

${OBJECTDIR}/controlador/orden_produccion.o: nbproject/Makefile-${CND_CONF}.mk controlador/orden_produccion.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/orden_produccion.o controlador/orden_produccion.c

${OBJECTDIR}/controlador/RMPS.o: nbproject/Makefile-${CND_CONF}.mk controlador/RMPS.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/RMPS.o controlador/RMPS.c

${OBJECTDIR}/controlador/proveedores.o: nbproject/Makefile-${CND_CONF}.mk controlador/proveedores.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/proveedores.o controlador/proveedores.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/controlador/drivers_post.o: nbproject/Makefile-${CND_CONF}.mk controlador/drivers_post.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/drivers_post.o controlador/drivers_post.c

${OBJECTDIR}/widgets/templates.o: nbproject/Makefile-${CND_CONF}.mk widgets/templates.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/templates.o widgets/templates.c

${OBJECTDIR}/controlador/persistencia.o: nbproject/Makefile-${CND_CONF}.mk controlador/persistencia.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/persistencia.o controlador/persistencia.c

${OBJECTDIR}/controlador/orden_pedido_proveedor.o: nbproject/Makefile-${CND_CONF}.mk controlador/orden_pedido_proveedor.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/orden_pedido_proveedor.o controlador/orden_pedido_proveedor.c

${OBJECTDIR}/widgets/menu.o: nbproject/Makefile-${CND_CONF}.mk widgets/menu.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/menu.o widgets/menu.c

${OBJECTDIR}/controlador/orden_pedido_producto.o: nbproject/Makefile-${CND_CONF}.mk controlador/orden_pedido_producto.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/orden_pedido_producto.o controlador/orden_pedido_producto.c

${OBJECTDIR}/widgets/calendario.o: nbproject/Makefile-${CND_CONF}.mk widgets/calendario.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/calendario.o widgets/calendario.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/controlador/clientes.o: nbproject/Makefile-${CND_CONF}.mk controlador/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/clientes.o controlador/clientes.c

${OBJECTDIR}/widgets/listados.o: nbproject/Makefile-${CND_CONF}.mk widgets/listados.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/listados.o widgets/listados.c

${OBJECTDIR}/controlador/principal.o: nbproject/Makefile-${CND_CONF}.mk controlador/principal.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -Wall -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/principal.o controlador/principal.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/Refactor

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

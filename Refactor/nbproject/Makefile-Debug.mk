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
	${OBJECTDIR}/controlador/tecnicos.o \
	${OBJECTDIR}/widgets/menu.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/controlador/callbacks.o \
	${OBJECTDIR}/widgets/formularios.o \
	${OBJECTDIR}/controlador/clientes.o \
	${OBJECTDIR}/widgets/listados.o \
	${OBJECTDIR}/pruebas.o \
	${OBJECTDIR}/controlador/drivers.o \
	${OBJECTDIR}/controlador/principal.o \
	${OBJECTDIR}/controlador/proveedores.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/controlador/persistencia.o

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

${OBJECTDIR}/controlador/tecnicos.o: nbproject/Makefile-${CND_CONF}.mk controlador/tecnicos.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/tecnicos.o controlador/tecnicos.c

${OBJECTDIR}/widgets/menu.o: nbproject/Makefile-${CND_CONF}.mk widgets/menu.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/menu.o widgets/menu.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/controlador/callbacks.o: nbproject/Makefile-${CND_CONF}.mk controlador/callbacks.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/callbacks.o controlador/callbacks.c

${OBJECTDIR}/widgets/formularios.o: nbproject/Makefile-${CND_CONF}.mk widgets/formularios.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/formularios.o widgets/formularios.c

${OBJECTDIR}/controlador/clientes.o: nbproject/Makefile-${CND_CONF}.mk controlador/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/clientes.o controlador/clientes.c

${OBJECTDIR}/widgets/listados.o: nbproject/Makefile-${CND_CONF}.mk widgets/listados.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/listados.o widgets/listados.c

${OBJECTDIR}/pruebas.o: nbproject/Makefile-${CND_CONF}.mk pruebas.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/pruebas.o pruebas.c

${OBJECTDIR}/controlador/drivers.o: nbproject/Makefile-${CND_CONF}.mk controlador/drivers.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/drivers.o controlador/drivers.c

${OBJECTDIR}/controlador/principal.o: nbproject/Makefile-${CND_CONF}.mk controlador/principal.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/principal.o controlador/principal.c

${OBJECTDIR}/controlador/proveedores.o: nbproject/Makefile-${CND_CONF}.mk controlador/proveedores.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/proveedores.o controlador/proveedores.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/controlador/persistencia.o: nbproject/Makefile-${CND_CONF}.mk controlador/persistencia.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/include/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/persistencia.o controlador/persistencia.c

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

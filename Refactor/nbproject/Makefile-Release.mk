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
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/controlador/clientes.o \
	${OBJECTDIR}/controlador/principal.o \
	${OBJECTDIR}/widgets/menu.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/controlador/callbacks.o \
	${OBJECTDIR}/widgets/formularios.o

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/refactor

dist/Release/GNU-Linux-x86/refactor: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/refactor ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/controlador/clientes.o: nbproject/Makefile-${CND_CONF}.mk controlador/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/clientes.o controlador/clientes.c

${OBJECTDIR}/controlador/principal.o: nbproject/Makefile-${CND_CONF}.mk controlador/principal.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/principal.o controlador/principal.c

${OBJECTDIR}/widgets/menu.o: nbproject/Makefile-${CND_CONF}.mk widgets/menu.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/menu.o widgets/menu.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/controlador/callbacks.o: nbproject/Makefile-${CND_CONF}.mk controlador/callbacks.c 
	${MKDIR} -p ${OBJECTDIR}/controlador
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/controlador/callbacks.o controlador/callbacks.c

${OBJECTDIR}/widgets/formularios.o: nbproject/Makefile-${CND_CONF}.mk widgets/formularios.c 
	${MKDIR} -p ${OBJECTDIR}/widgets
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/widgets/formularios.o widgets/formularios.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/refactor

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
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
	${OBJECTDIR}/datos/clientes.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/vista/login.o \
	${OBJECTDIR}/main.o

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
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/listo

dist/Release/GNU-Linux-x86/listo: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/listo ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/datos/clientes.o: nbproject/Makefile-${CND_CONF}.mk datos/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/clientes.o datos/clientes.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/vista/login.o: nbproject/Makefile-${CND_CONF}.mk vista/login.c 
	${MKDIR} -p ${OBJECTDIR}/vista
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/login.o vista/login.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/listo

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

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
	${OBJECTDIR}/interfaz/login.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/interfaz/ventana.o \
	${OBJECTDIR}/main.o

# C Compiler Flags
CFLAGS=-lcdk -lncurses -lsqlite3

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lcdk

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/cdk_2

dist/Debug/GNU-Linux-x86/cdk_2: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cdk_2 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/interfaz/login.o: nbproject/Makefile-${CND_CONF}.mk interfaz/login.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/login.o interfaz/login.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/interfaz/ventana.o: nbproject/Makefile-${CND_CONF}.mk interfaz/ventana.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/ventana.o interfaz/ventana.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/cdk_2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

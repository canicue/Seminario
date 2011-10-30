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
	${OBJECTDIR}/interfaz/menu.o \
	${OBJECTDIR}/interfaz/scroll.o \
	${OBJECTDIR}/interfaz/label.o \
	${OBJECTDIR}/popup.o \
	${OBJECTDIR}/interfaz.o \
	${OBJECTDIR}/interfaz/dialogo.o \
	${OBJECTDIR}/interfaz/info.o \
	${OBJECTDIR}/main.o

# C Compiler Flags
CFLAGS=-lcdk -lncurses -lsqlite3 -lpanel -lmenu

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/widgets

dist/Debug/GNU-Linux-x86/widgets: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/widgets ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/interfaz/menu.o: nbproject/Makefile-${CND_CONF}.mk interfaz/menu.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/menu.o interfaz/menu.c

${OBJECTDIR}/interfaz/scroll.o: nbproject/Makefile-${CND_CONF}.mk interfaz/scroll.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/scroll.o interfaz/scroll.c

${OBJECTDIR}/interfaz/label.o: nbproject/Makefile-${CND_CONF}.mk interfaz/label.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/label.o interfaz/label.c

${OBJECTDIR}/popup.o: nbproject/Makefile-${CND_CONF}.mk popup.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/popup.o popup.c

${OBJECTDIR}/interfaz.o: nbproject/Makefile-${CND_CONF}.mk interfaz.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz.o interfaz.c

${OBJECTDIR}/interfaz/dialogo.o: nbproject/Makefile-${CND_CONF}.mk interfaz/dialogo.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/dialogo.o interfaz/dialogo.c

${OBJECTDIR}/interfaz/info.o: nbproject/Makefile-${CND_CONF}.mk interfaz/info.c 
	${MKDIR} -p ${OBJECTDIR}/interfaz
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/interfaz/info.o interfaz/info.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I/usr/lib/cdk -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/widgets

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

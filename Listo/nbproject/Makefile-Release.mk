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
	${OBJECTDIR}/vista/proveedores/form_prov.o \
	${OBJECTDIR}/vista/scroll.o \
	${OBJECTDIR}/vista/tecnicos/form_tec.o \
	${OBJECTDIR}/hacedor.o \
	${OBJECTDIR}/datos/clientes.o \
	${OBJECTDIR}/datos/tecnicos.o \
	${OBJECTDIR}/vista/tecnicos/tecnicos.o \
	${OBJECTDIR}/datos/rmps.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/vista/login.o \
	${OBJECTDIR}/datos/proveedores.o \
	${OBJECTDIR}/pruebas.o \
	${OBJECTDIR}/vista/proveedores/proveedores.o \
	${OBJECTDIR}/vista/clientes/clientes.o \
	${OBJECTDIR}/datos/insumos.o \
	${OBJECTDIR}/vista/info.o \
	${OBJECTDIR}/datos/datos.o \
	${OBJECTDIR}/vista/clientes/form_cli.o \
	${OBJECTDIR}/vista/principal.o

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

${OBJECTDIR}/vista/proveedores/form_prov.o: nbproject/Makefile-${CND_CONF}.mk vista/proveedores/form_prov.c 
	${MKDIR} -p ${OBJECTDIR}/vista/proveedores
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/proveedores/form_prov.o vista/proveedores/form_prov.c

${OBJECTDIR}/vista/scroll.o: nbproject/Makefile-${CND_CONF}.mk vista/scroll.c 
	${MKDIR} -p ${OBJECTDIR}/vista
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/scroll.o vista/scroll.c

${OBJECTDIR}/vista/tecnicos/form_tec.o: nbproject/Makefile-${CND_CONF}.mk vista/tecnicos/form_tec.c 
	${MKDIR} -p ${OBJECTDIR}/vista/tecnicos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/tecnicos/form_tec.o vista/tecnicos/form_tec.c

${OBJECTDIR}/hacedor.o: nbproject/Makefile-${CND_CONF}.mk hacedor.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/hacedor.o hacedor.c

${OBJECTDIR}/datos/clientes.o: nbproject/Makefile-${CND_CONF}.mk datos/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/clientes.o datos/clientes.c

${OBJECTDIR}/datos/tecnicos.o: nbproject/Makefile-${CND_CONF}.mk datos/tecnicos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/tecnicos.o datos/tecnicos.c

${OBJECTDIR}/vista/tecnicos/tecnicos.o: nbproject/Makefile-${CND_CONF}.mk vista/tecnicos/tecnicos.c 
	${MKDIR} -p ${OBJECTDIR}/vista/tecnicos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/tecnicos/tecnicos.o vista/tecnicos/tecnicos.c

${OBJECTDIR}/datos/rmps.o: nbproject/Makefile-${CND_CONF}.mk datos/rmps.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/rmps.o datos/rmps.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/vista/login.o: nbproject/Makefile-${CND_CONF}.mk vista/login.c 
	${MKDIR} -p ${OBJECTDIR}/vista
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/login.o vista/login.c

${OBJECTDIR}/datos/proveedores.o: nbproject/Makefile-${CND_CONF}.mk datos/proveedores.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/proveedores.o datos/proveedores.c

${OBJECTDIR}/pruebas.o: nbproject/Makefile-${CND_CONF}.mk pruebas.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/pruebas.o pruebas.c

${OBJECTDIR}/vista/proveedores/proveedores.o: nbproject/Makefile-${CND_CONF}.mk vista/proveedores/proveedores.c 
	${MKDIR} -p ${OBJECTDIR}/vista/proveedores
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/proveedores/proveedores.o vista/proveedores/proveedores.c

${OBJECTDIR}/vista/clientes/clientes.o: nbproject/Makefile-${CND_CONF}.mk vista/clientes/clientes.c 
	${MKDIR} -p ${OBJECTDIR}/vista/clientes
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/clientes/clientes.o vista/clientes/clientes.c

${OBJECTDIR}/datos/insumos.o: nbproject/Makefile-${CND_CONF}.mk datos/insumos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/insumos.o datos/insumos.c

${OBJECTDIR}/vista/info.o: nbproject/Makefile-${CND_CONF}.mk vista/info.c 
	${MKDIR} -p ${OBJECTDIR}/vista
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/info.o vista/info.c

${OBJECTDIR}/datos/datos.o: nbproject/Makefile-${CND_CONF}.mk datos/datos.c 
	${MKDIR} -p ${OBJECTDIR}/datos
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/datos/datos.o datos/datos.c

${OBJECTDIR}/vista/clientes/form_cli.o: nbproject/Makefile-${CND_CONF}.mk vista/clientes/form_cli.c 
	${MKDIR} -p ${OBJECTDIR}/vista/clientes
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/clientes/form_cli.o vista/clientes/form_cli.c

${OBJECTDIR}/vista/principal.o: nbproject/Makefile-${CND_CONF}.mk vista/principal.c 
	${MKDIR} -p ${OBJECTDIR}/vista
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/vista/principal.o vista/principal.c

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

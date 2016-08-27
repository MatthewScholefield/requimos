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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=w64
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/source/ComputerPlayer.o \
	${OBJECTDIR}/source/Enemy.o \
	${OBJECTDIR}/source/Entity.o \
	${OBJECTDIR}/source/EntityType.o \
	${OBJECTDIR}/source/Grid.o \
	${OBJECTDIR}/source/GridRunner.o \
	${OBJECTDIR}/source/Hud.o \
	${OBJECTDIR}/source/HumanPlayer.o \
	${OBJECTDIR}/source/Position.o \
	${OBJECTDIR}/source/Renderer.o \
	${OBJECTDIR}/source/World.o \
	${OBJECTDIR}/source/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64
CXXFLAGS=-m64

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/lib/SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/requimos.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/requimos.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/requimos ${OBJECTFILES} ${LDLIBSOPTIONS} -lopengl32 -lfreetype -ljpeg -lwinmm -lgdi32

${OBJECTDIR}/source/ComputerPlayer.o: source/ComputerPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ComputerPlayer.o source/ComputerPlayer.cpp

${OBJECTDIR}/source/Enemy.o: source/Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Enemy.o source/Enemy.cpp

${OBJECTDIR}/source/Entity.o: source/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Entity.o source/Entity.cpp

${OBJECTDIR}/source/EntityType.o: source/EntityType.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/EntityType.o source/EntityType.cpp

${OBJECTDIR}/source/Grid.o: source/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Grid.o source/Grid.cpp

${OBJECTDIR}/source/GridRunner.o: source/GridRunner.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/GridRunner.o source/GridRunner.cpp

${OBJECTDIR}/source/Hud.o: source/Hud.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Hud.o source/Hud.cpp

${OBJECTDIR}/source/HumanPlayer.o: source/HumanPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/HumanPlayer.o source/HumanPlayer.cpp

${OBJECTDIR}/source/Position.o: source/Position.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Position.o source/Position.cpp

${OBJECTDIR}/source/Renderer.o: source/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Renderer.o source/Renderer.cpp

${OBJECTDIR}/source/World.o: source/World.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/World.o source/World.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -g -DSFML_STATIC -I/C/lib/SFML/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/requimos.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

EXECUTABLE=sfmlsandbox

CC=C:/cppdev/mingw-w64-7.3.0/mingw64/bin/g++.exe
CFLAGS=-O3 -Wall -c -fmessage-length=0 -std=c++17 -Wl,--subsystem,windows
LIBRARYDIR="-LC:/cppdev/SFML-2.5.1/lib"
LIBRARIES=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
INCLUDEDIR="-IC:/cppdev/SFML-2.5.1/include"

dir_guard=mkdir -p $(@D)

SRC_DIR=src/
RELEASE_OBJ_DIR=Obj_Release/
RELEASE_OUT_DIR=Release/
DLLS=\
"C:/cppdev/SFML-2.5.1/bin/sfml-audio-2.dll" \
"C:/cppdev/SFML-2.5.1/bin/sfml-graphics-2.dll" \
"C:/cppdev/SFML-2.5.1/bin/sfml-system-2.dll" \
"C:/cppdev/SFML-2.5.1/bin/sfml-window-2.dll" \
"C:/cppdev/SFML-2.5.1/bin/openal32.dll" \
"C:/cppdev/mingw-w64-7.3.0/mingw64/bin/libstdc++-6.dll" \
"C:/cppdev/mingw-w64-7.3.0/mingw64/bin/libwinpthread-1.dll" \
"C:/cppdev/mingw-w64-7.3.0/mingw64/bin/libgcc_s_seh-1.dll" 


CPPSOURCES=$(call rwildcard,src/,*.cpp)
CCSOURCES=$(call rwildcard,src/,*.cc)
SOURCES= $(CPPSOURCES) $(CCSOURCES)

TEMP=$(SOURCES:.cpp=.o)
OBJECTS=$(TEMP:.cc=.o)
OBJECTSOUT=$(OBJECTS:$(SRC_DIR)%=$(RELEASE_OBJ_DIR)%)

clean_build_run: clean all run

build_run: all run

all: $(RELEASE_OUT_DIR)$(EXECUTABLE)

run:
	$(RELEASE_OUT_DIR)$(EXECUTABLE).exe

$(RELEASE_OUT_DIR)$(EXECUTABLE): $(OBJECTSOUT)
	$(dir_guard)
	@echo 'Building executable: $@'
	$(CC) $(LIBRARYDIR) -o $@ $(OBJECTSOUT) $(LIBRARIES)
	cp -R res/resource $(RELEASE_OUT_DIR)
	cp $(DLLS) $(RELEASE_OUT_DIR)

$(RELEASE_OBJ_DIR)%.o: $(SRC_DIR)%.cc
	$(dir_guard)
	@echo 'Building file: $@'
	$(CC) $(LIBRARIES) $(CFLAGS) $(INCLUDEDIR) -c $< -o $(@:src/%=release/%)

$(RELEASE_OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(dir_guard)
	@echo 'Building file: $@'
	$(CC) $(LIBRARIES) $(CFLAGS) $(INCLUDEDIR) -c $< -o $(@:src/%=release/%)

clean:
	rm -rf $(RELEASE_OUT_DIR)
	rm -rf $(RELEASE_OBJ_DIR)

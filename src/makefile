CXXFLAGS+=-std=c++11
DFLAGS=-DDEBUG
LIB=-lmingw32 -lSDL_gfx -lSDLmain -lSDL
OBJ=base_scene.o scene_manager.o main.o keyboard_state.o waypoint_manager.o
SRC=test_systems.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	-$(RM) *.o *.a *.exe

unit:
	$(CXX) $(CXXFLAGS) unit.cpp

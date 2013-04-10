CXXFLAGS+=-std=c++0x
DFLAGS=-DDEBUG
LIB=-lmingw32 -lSDLmain -lSDL
OBJ=error.o base_scene.o main.o
SRC=scene.cpp scene_manager.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	-$(RM) *.o *.a *.exe

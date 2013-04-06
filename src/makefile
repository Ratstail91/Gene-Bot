CXXFLAGS+=-std=c++0x
DFLAGS=-DDEBUG
LIB=-lmingw32 -lSDL_gfx -lSDLmain -lSDL
OBJ=error.o base_scene.o
SRC=test_scene.cpp main.cpp

all: debug

release: $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC) $(OBJ) $(LIB)

debug: $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(SRC) $(OBJ) $(LIB)

clean:
	-$(RM) *.o *.exe

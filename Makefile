OBJS = src/*.cpp
OBJ_NAME = Memory
LIBS = -lSDL2_image -lSDL2_ttf -lSDL2

all:
	g++ $(OBJS) $(LIBS) -o $(OBJ_NAME)
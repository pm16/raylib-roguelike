CC=clang
CFLAGS=-Wall -Werror -std=c++17
INCLUDE=-I./include
LIB=-L./lib -lstdc++ -lSDL2 -l:pdcurses.a
game: main.cpp
	$(CC) $(CFLAGS) *.cpp $(INCLUDE) $(LIB) -o ./build/game
	
clean:
	rm -rf ./build/*
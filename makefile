CC=clang
CFLAGS=-Wall -Werror -std=c++17
INCLUDE=-I./include
LIB=-L./lib -lstdc++ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -lsqlite3
game: main.cpp
	$(CC) $(CFLAGS) *.cpp $(INCLUDE) $(LIB) -o ./build/game
	
clean:
	rm -rf ./build/*
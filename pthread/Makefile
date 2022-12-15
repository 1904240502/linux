src = $(wildcard ./src/*.cpp)
target = $(patsubst ./src/%.cpp,./bin/%,$(src))

myArgs= -Wall -g
ALL:$(target)
CC=g++

dir:
	mkdir src bin

./bin/%:./src/%.cpp
	$(CC) $< -o $@ $(myArgs) -lpthread
%:./src/%.cpp
	$(CC) $< -o ./bin/$@ $(myArgs) -lpthread
clean:
	-rm -rf $(target)
.PHONY:clean ALL dir
	

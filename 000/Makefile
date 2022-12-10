src = $(wildcard *.cpp)
target = $(patsubst %.cpp,%,$(src))

ALL:$(target)
CC=g++
%:%.cpp
	$(CC) $< -o $@ 
clean:
	-rm -rf $(target)
.PHONY:clean ALL
	

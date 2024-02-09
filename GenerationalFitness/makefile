
CC = g++
CPPFLAGS = -Wall -Wextra -std=c++17

main.exe: main.o simulator.o organism.o
	$(CC) $^ $(CPPFLAGS) -o $@

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) -c $<

simulator.o: simulator.cpp simulator.h
	$(CC) $(CPPFLAGS) -c $<

organism.o: organism.cpp organism.h
	$(CC) $(CPPFLAGS) -c $<

.PHONY: clean
clean:
	rm *.o main.exe

-include $(wildcard *.d)

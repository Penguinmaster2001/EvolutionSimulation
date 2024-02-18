# Anthony Cieri 2024


CC = g++
CPPFLAGS = -Wall -Wextra -std=c++17
LIFE = lifeSquare.o lifeSquareObject.o lifeFood.o lifeGrid.o lifeOrganism.o

main.exe: main.o simulator.o organism.o LIFE
	$(CC) $^ $(CPPFLAGS) -o $@

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) -c $<

simulator.o: simulator.cpp simulator.h
	$(CC) $(CPPFLAGS) -c $<

organism.o: organism.cpp organism.h
	$(CC) $(CPPFLAGS) -c $<


lifeSquare.o: lifeSquare.h lifeSquare.cpp
	$(CC) $(CPPFLAGS) -c $<

lifeSquare.o: lifeSquareObject.h lifeSquareObject.cpp
	$(CC) $(CPPFLAGS) -c $<

lifeFood.o: lifeFood.h lifeFood.cpp
	$(CC) $(CPPFLAGS) -c $<

lifeGrid.o: lifeGrid.h lifeGrid.cpp
	$(CC) $(CPPFLAGS) -c $<

lifeOrganism.o: lifeOrganism.h lifeOrganism.cpp
	$(CC) $(CPPFLAGS) -c $<


.PHONY: clean
clean:
	rm *.o main.exe

-include $(wildcard *.d)

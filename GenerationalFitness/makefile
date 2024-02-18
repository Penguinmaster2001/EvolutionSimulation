# Anthony Cieri 2024


CC = g++
CPPFLAGS = -Wall -Wextra -std=c++17

main.exe: main.o simulator.o organism.o life/lifeSquareObject.o life/lifeFood.o # lifeGrid.o lifeOrganism.o
	$(CC) $^ $(CPPFLAGS) -o $@

main.o: main.cpp main.h
	$(CC) $(CPPFLAGS) -c $< -o $@

simulator.o: simulator.cpp simulator.h
	$(CC) $(CPPFLAGS) -c $< -o $@

organism.o: organism.cpp organism.h
	$(CC) $(CPPFLAGS) -c $< -o $@


life/lifeSquareObject.o: life/lifeSquareObject.cpp life/lifeSquareObject.h
	$(CC) $(CPPFLAGS) -c $< -o $@

life/lifeFood.o: life/lifeFood.cpp life/lifeFood.h
	$(CC) $(CPPFLAGS) -c $< -o $@

# lifeGrid.o: life/lifeGrid.h life/lifeGrid.cpp
# 	$(CC) $(CPPFLAGS) -c $< -o $@

# lifeOrganism.o: life/lifeOrganism.h life/lifeOrganism.cpp
# 	$(CC) $(CPPFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm *.o *.gch life/*.o life/*.gch main.exe

-include $(wildcard *.d)

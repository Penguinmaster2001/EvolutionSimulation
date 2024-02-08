Anthony Cieri
Started Feb. 8, 2024

A collection of tests and projects centered around simulating evolution.

Projects:
	GenerationalFitness
		A simple script written in Python that generates many organisms with
		a random "fitness" score 0 <= f <= 1. The score represents the
		probability that the organism survives long enough to reproduce.
		After eliminating half of the population based on the fitness, each of
		the remaining population chooses a mate (eventually they will choose
		based on fitness, and their mate can refuse) and reproduces. Their
		offspring will take the average of their parents' fitness + a random
		value. This repeats every generation.

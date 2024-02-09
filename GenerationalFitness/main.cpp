# include "main.h"

int main(int argc, char** argv)
{
    int num_organisms = 10;
    int num_generations = 10;

    if (argc > 1)
    {
        num_organisms = std::stoi(argv[1]);
    }

    if (argc > 2)
    {
        num_generations = std::stoi(argv[2]);
    }


    Simulator sim(num_organisms, num_generations);
    sim.run();

    return 0;
}

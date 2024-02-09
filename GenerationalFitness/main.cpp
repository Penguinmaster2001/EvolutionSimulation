# include "main.h"

int main(int argc, char** argv)
{
    int num_organisms = 10;

    if (argc > 1)
    {
        num_organisms = std::stoi(argv[1]);
    }


    Simulator sim(num_organisms);
    sim.run();

    return 0;
}

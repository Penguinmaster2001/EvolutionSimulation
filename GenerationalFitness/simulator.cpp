# include "simulator.h"

Simulator::Simulator(int num_organisms, int num_generations)
{
    this->num_organisms = num_organisms;
    this->num_generations = num_generations;
}

void Simulator::run()
{
    std::cout << "Running the simulation" << std::endl;
}

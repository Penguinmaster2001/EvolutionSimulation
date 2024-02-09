# include "simulator.h"

Simulator::Simulator(int num_organisms, int num_generations)
{
    this->num_organisms = num_organisms;
    this->num_generations = num_generations;
}



void Simulator::run()
{
    this->current_generation = Generation(this->num_organisms);
    std::cout << "Generation 0: " << this->current_generation << std::endl;
}

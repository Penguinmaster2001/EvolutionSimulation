# include "simulator.h"

Simulator::Simulator(int num_organisms, int num_generations)
{
    this->num_organisms = num_organisms;
    this->num_generations = num_generations;
}



void Simulator::run()
{
    this->current_generation = Generation(this->num_organisms);

    for (int i = 0; i < this->num_generations; i++)
    {
        this->current_generation = this->current_generation.create_next_generation();
        // std::cout << "Generation " << i << ": " << this->current_generation << "\n";
    }

    std::cout << this->current_generation.generate_stats() << "\n";
}

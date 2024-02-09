# include "simulator.h"

Simulator::Simulator(int num_organisms)
{
    this->num_organisms = num_organisms;
    
    this->organisms = OrganismVector();
    for (int i = 0; i < num_organisms; i++)
    {
        this->organisms.push_back(std::make_shared<Organism>());
    }
}

void Simulator::run()
{
    return;
}

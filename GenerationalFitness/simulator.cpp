# include "simulator.h"

Simulator::Simulator(int num_organisms)
{
    num_organisms = num_organisms;
    
    organisms = OrganismVector();
    for (int i = 0; i < num_organisms; i++)
    {
        organisms.push_back(std::make_shared<Organism>());
    }
}

void Simulator::run()
{
    return;
}

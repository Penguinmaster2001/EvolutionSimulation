#include "generation.h"

// private
std::vector<Organism> Generation::generate_random_organisms(int num_organisms)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0.5, 0.1);

    std::vector<Organism> new_organisms = std::vector<Organism>();

    new_organisms.resize(num_organisms);

    for (int i = 0; i < num_organisms; i++)
    {
        new_organisms[i] = Organism(d(gen));
    }

    return new_organisms;
}


// public
Generation::Generation(std::vector<Organism> organisms)
{
    this->organisms = organisms;
}

Generation::Generation(int num_organisms)
{
    this->organisms = this->generate_random_organisms(num_organisms);
}

std::vector<Organism> Generation::get_organisms()
{
    return this->organisms;
}

void Generation::set_organisms(std::vector<Organism> organisms)
{
    this->organisms = organisms;
}

Generation Generation::create_next_generation()
{
    // TODO: Implement reproduction
    return generate_random_organisms(this->organisms.size());
}

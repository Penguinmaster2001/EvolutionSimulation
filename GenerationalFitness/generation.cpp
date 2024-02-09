#include "generation.h"

// private
std::vector<Organism> Generation::generate_random_organisms(int num_organisms)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> normal_dist(0.5, 0.1);

    std::vector<Organism> new_organisms = std::vector<Organism>();

    new_organisms.resize(num_organisms);

    for (int i = 0; i < num_organisms; i++)
    {
        new_organisms[i] = Organism(normal_dist(gen));
    }

    return new_organisms;
}



// public
Generation::Generation(std::vector<Organism> organisms)
{
    this->organisms = organisms;
    this->num_organisms = organisms.size();
}

Generation::Generation(int num_organisms)
{
    this->organisms = this->generate_random_organisms(num_organisms);
    this->num_organisms = num_organisms;
}



void Generation::set_organisms(std::vector<Organism> organisms)
{
    this->organisms = organisms;
    this->num_organisms = organisms.size();
}



float Generation::get_average_fitness() const
{
    if (this->num_organisms == 0)
    {
        return -1.0f;
    }

    float total_fitness = 0.0f;
    for (const Organism &organism : this->organisms)
    {
        total_fitness += organism.get_fitness();
    }
    
    return total_fitness / this->num_organisms;
}


Generation Generation::create_next_generation()
{
    // TODO: Implement reproduction
    return generate_random_organisms(this->num_organisms);
}



std::ostream &operator<<(std::ostream &os, const Generation &generation)
{
    os << "\nGeneration: " << generation.get_num_organisms() << " organisms\n"
        << "Average Fitness: " << generation.get_average_fitness() << std::endl;
    
    
    return os;
}

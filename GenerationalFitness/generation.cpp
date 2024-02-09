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



std::string Generation::generate_stats()
{
    std::sort(this->organisms.begin(), this->organisms.end(), 
        [](const Organism &a, const Organism &b) -> bool
        {
            return a.get_fitness() > b.get_fitness();
        });

    float highest = this->organisms[0].get_fitness();
    float lowest = this->organisms[this->num_organisms - 1].get_fitness();

    
    std::string stats = "Generation Stats:\nNumber of Organisms: " + std::to_string(this->num_organisms) + "\n"
        + "Mean: " + std::to_string(this->get_average_fitness()) + "\n"
        + "Highest: " + std::to_string(highest) + "\n"
        + "Lowest: " + std::to_string(lowest) + "\n"
        + "Median: " + std::to_string(this->organisms[this->num_organisms / 2].get_fitness()) + "\n";

    int histogram_size = 50;
    std::vector<int> histogram_data = std::vector<int>();
    histogram_data.resize(histogram_size);
    for (int i = 0; i < histogram_size; i++)
    {
        histogram_data[i] = 0;
    }

    std::string histogram = "Fitness Histogram:\n";

    int largest_bucket_size = 0;

    std::vector<Organism>::iterator it;

    int bucket = 0;
    float step = (highest - lowest) / float(histogram_size);
    for (it = this->organisms.end(); it != this->organisms.begin() && bucket < histogram_size; --it)
    {
        if (it->get_fitness() > ((bucket + 1) * step) + lowest)
        {
            if (histogram_data[bucket] > largest_bucket_size)
            {
                largest_bucket_size = histogram_data[bucket];
            }

            bucket = (it->get_fitness() - lowest) / step;
        }

        histogram_data[bucket]++;
    }

    for (int i = 20; i > -1; i--)
    {
        for (int j = 0; j < histogram_size; j++)
        {
            if (histogram_data[j] > i)
            {
                histogram += "*";
            }
            else
            {
                histogram += " ";
            }
        }

        histogram += "\n";
    }

    stats += histogram;


    return stats;
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
    // Remove all organisms that don't get to reproduce

    // Sort the organisms by fitness
    std::sort(this->organisms.begin(), this->organisms.end(), 
        [](const Organism &a, const Organism &b) -> bool
        {
            return a.get_fitness() > b.get_fitness();
        });

    // normal_dist is used to decide whether an organism gets to reproduce
    // The parameters depend on the current generation's average fitness
    float average_fitness = this->get_average_fitness();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> normal_dist(0.5, 0.2);
    std::uniform_real_distribution<> uniform_dist(average_fitness - 0.1, average_fitness + 0.1);

    std::vector<Organism> reproducing_organisms = std::vector<Organism>();
    reproducing_organisms.resize(this->num_organisms / 2);

    // std::cout << "Reproducing organisms:\n";
    for (int i = 0; i < this->num_organisms / 2; i++)
    {
        Organism current_organism = this->organisms[i];

        // Add the organism to the next generation if the random number is greater than the fitness
        // Otherwise, add the organism at the opposite position in the list
        if (current_organism.get_fitness() > uniform_dist(gen))
        {
            // std::cout << "1";
            reproducing_organisms[i] = this->organisms[i];
        }
        else
        {
            // std::cout << "0";
            reproducing_organisms[i] = this->organisms[this->num_organisms - i - 1];
        }
    }
    // std::cout << "\n";


    // Make the organisms reproduce
    std::vector<Organism> new_organisms = std::vector<Organism>();
    new_organisms.resize(this->num_organisms);

    for (int i = 0; i < this->num_organisms / 2; i += 2)
    {
        new_organisms[i * 2] = reproducing_organisms[i].reproduce(reproducing_organisms[i + 1]);
        new_organisms[i * 2 + 1] = reproducing_organisms[i + 1].reproduce(reproducing_organisms[i]);
    }

    return Generation(new_organisms);
}



std::ostream &operator<<(std::ostream &os, const Generation &generation)
{
    os << "\nGeneration: " << generation.get_num_organisms() << " organisms\n"
        << "Average Fitness: " << generation.get_average_fitness() << "\n";
    
    
    return os;
}

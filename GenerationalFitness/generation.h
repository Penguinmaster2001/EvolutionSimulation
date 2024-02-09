/*
    Anthony Cieri

    
    This file holds the Generation class and functions
 */

# ifndef GENERATION_H
# define GENERATION_H

# include "organism.h"

# include <algorithm>
# include <vector>
# include <random>
# include <iostream>
# include <string>

class Generation {
private:
    int num_organisms;
    std::vector<Organism> organisms;


    std::vector<Organism> generate_random_organisms(int num_organisms);


    friend std::ostream& operator<<(std::ostream& os, const Generation& generation);



public:
    Generation() : num_organisms(0) {};
    Generation(std::vector<Organism> organisms);
    Generation(int num_organisms);


    float get_average_fitness() const;


    int get_num_organisms() const {return this->num_organisms;};

    std::vector<Organism> get_organisms() const {return this->organisms;};
    void set_organisms(std::vector<Organism> organisms);

    std::string generate_stats();


    Generation create_next_generation();
};

# endif

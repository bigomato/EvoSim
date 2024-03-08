#include <vector>
#include <string>
#include <algorithm>
#include "utils/rng.h"
#include "rng.h"
using std::string;
using std::vector;

typedef struct Dna
{
    vector<Gene> p1_genes;
    vector<Gene> p2_genes;

    Dna(vector<Gene> p1_genes, vector<Gene> p2_genes)
    {
        this->p1_genes = p1_genes;
        this->p2_genes = p2_genes;
    }

    Dna *get_offspring_dna(Dna *p2_dna)
    {
        vector<Gene> p1_gametes;
        vector<Gene> p2_gametes;
        crossover(this, &p1_gametes);
        crossover(p2_dna, &p2_gametes);
        return new Dna(p1_gametes, p2_gametes);
    }
};

typedef struct Gene
{
    char data[25];
    char type = data[0];
    int id = hexStringToInt(std::string(data).substr(22, 3));
};

int hexStringToInt(string hexString)
{
    try
    {
        size_t pos;
        return std::stoi(hexString, &pos, 16);
    }
    catch (const std::exception &)
    {
        return 0;
    }
}

void crossover(Dna *dna, vector<Gene> *gametes)
{
    for (int i = 0; i < std::max(dna->p1_genes.size(), dna->p2_genes.size()); i++)
    {
        vector<Gene> possible_gene;
        if (dna->p1_genes.size() - 1 >= i)
            possible_gene.push_back(dna->p1_genes[i]);
        if (dna->p2_genes.size() - 1 >= i)
            possible_gene.push_back(dna->p2_genes[i]);

        int random_index = randomint(0, possible_gene.size() - 1);
        gametes->push_back(possible_gene[random_index]);

        if (randomnumber() < 0.005)
        {
            int random_gene = randomint(0, possible_gene.size() - 1);
            gametes->push_back(possible_gene[random_gene]);
        }
    }
}

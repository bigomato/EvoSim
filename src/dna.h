#include <vector>

typedef struct Dna {
    vector<Gene> p1_genes;
    vector<Gene> p2_genes;

    Dna (vector<Gene> p1_genes, vector<Gene> p2_genes) {
        this->p1_genes = p1_genes;
        this->p2_genes = p2_genes;
    }

    Dna get_offspring_dna(Dna *p2_dna){
        vector<Gene> *p1_gametes;
        vector<Gene> *p2_gametes;
        Dna *offspring_dna;
        crossover(this, p1_gametes);
        crossover(p2_dna, p2_gametes);
        combine(p1_gametes, p2_gametes, offspring_dna);
        return offspring_dna;
    }
}


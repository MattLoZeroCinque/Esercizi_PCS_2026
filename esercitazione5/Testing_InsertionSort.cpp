#include <iostream>
#include <vector>
#include <string>
#include "Sorting_Algorithm.hpp"
#include "randfiller.h"


int main() {
    randfiller filler;

    // Si testa su 100 vettori
    for (int i = 0; i < 100; ++i) {
        int size = 1 + (std::rand() % 100);
        std::vector<int> vec(size);
        filler.fill(vec, -1000, 1000);

        insertion_sort(vec);

        if (is_sorted(vec).has_value()) {
            return EXIT_FAILURE;
        }
    }

    // Si testa su 10 stringhe
    std::vector<std::string> str_vec = {
        "Bisseck", "De Bruyne", "Estupiñán", "Douvikas", "Di Gregorio", 
        "calcio", "rigore", "cartellino", "campo", "arbitro"
    };

    insertion_sort(str_vec);

    if (is_sorted(str_vec).has_value()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
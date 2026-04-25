#include <iostream>
#include <vector>
#include <string>
#include "Sorting_Algorithm.hpp"
#include "randfiller.h"

using namespace std;

int main() {
    randfiller filler;

    // Si testa su 100 vettori di interi con dimensione casuale tra 1 e 100
    for (int i = 0; i < 100; ++i) {
        int size = 1 + (rand() % 100);
        vector<int> vec(size);
        filler.fill(vec, -1000, 1000);

        new_quick_sort(vec, 0, size - 1);

        if (is_sorted(vec).has_value()) {
            return EXIT_FAILURE;
        }
    }

    // Si testa su 10 stringhe
    vector<string> str_vec = {
        "Bisseck", "De Bruyne", "Estupiñán", "Douvikas", "Di Gregorio", 
        "calcio", "rigore", "cartellino", "campo", "arbitro"
    };

    new_quick_sort(str_vec, 0, str_vec.size() - 1);

    if (is_sorted(str_vec).has_value()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
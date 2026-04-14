#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Sorting_Algorithm.hpp"
#include "timecounter.h"
#include "randfiller.h"

using namespace std;

int main() {
    randfiller filler;
    timecounter timer;

    // Si stampa a schermo l'intestazione della tabella
    cout << left << setw(10) << "Size" 
         << setw(15) << "Bubble" 
         << setw(15) << "Insertion" 
         << setw(15) << "Selection" 
         << setw(15) << "std::sort" << endl;

    // Si cicla come richiesto partendo da N=4 (2^2) fino a N=8192 (2^13)
    for (int N = 4; N <= 8192; N *= 2) {
        vector<int> original_vec(N);
        filler.fill(original_vec, -1000, 1000);

        cout << left << setw(10) << N;

        // Si testa il Bubble Sort
        vector<int> v1 = original_vec;
        timer.tic();
        bubble_sort(v1);
        cout << setw(15) << timer.toc();

        // Si testa l'Insertion Sort
        vector<int> v2 = original_vec;
        timer.tic();
        insertion_sort(v2);
        cout << setw(15) << timer.toc();

        // Si testa il Selection Sort
        vector<int> v3 = original_vec;
        timer.tic();
        selection_sort(v3);
        cout << setw(15) << timer.toc();

        // Si testa il comando nativo di C++ 'std::sort'
        vector<int> v4 = original_vec;
        timer.tic();
        sort(v4.begin(), v4.end());
        cout << setw(15) << timer.toc() << endl;
    }

    return EXIT_SUCCESS;
}
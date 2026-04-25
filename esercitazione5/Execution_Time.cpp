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
         << setw(15) << "std::sort"
         << setw(15) << "Merge"
		 << setw(15) << "Quick"
         << setw(15) << "New_Quick" << endl;

    // Si cicla come richiesto partendo da N=4 (2^2) fino a N=8192 (2^13)
    for (int N = 4; N <= 8192; N *= 2) {
        
        const int num_samples = 100;
        
        // Si preallocano 100 vettori della dimensione che si vuole testare
        vector<vector<int>> samples(num_samples, vector<int>(N));
        for (int i = 0; i < num_samples; ++i) {
            filler.fill(samples[i], -1000, 1000);
        }

        cout << left << setw(10) << N;

        // Si testa il Bubble Sort
        auto v_bubble = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            bubble_sort(v_bubble[i]);
        }
        cout << setw(15) << timer.toc() / num_samples;

        // Si testa l'Insertion Sort
        auto v_insertion = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            insertion_sort(v_insertion[i]);
        }
        cout << setw(15) << timer.toc() / num_samples;

        // Si testa il Selection Sort
        auto v_selection = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            selection_sort(v_selection[i]);
        }
        cout << setw(15) << timer.toc() / num_samples;

        // Si testa il comando nativo di C++ 'std::sort'
        auto v_std = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            std::sort(v_std[i].begin(), v_std[i].end());
        }
        cout << setw(15) << timer.toc() / num_samples;

        // Si testa il Merge Sort
        auto v_merge = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            merge_sort(v_merge[i], 0, N - 1);
        }
        cout << setw(15) << timer.toc() / num_samples;

        // Si testa il Quick Sort
        auto v_quick = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            quick_sort(v_quick[i], 0, N - 1);
        }
        cout << setw(15) << timer.toc() / num_samples;
		
		// Si testa il Quick Sort ottimizzato
        auto v_new_quick = samples;
        timer.tic();
        for (int i = 0; i < num_samples; ++i) {
            new_quick_sort(v_new_quick[i], 0, N - 1);
        }
        cout << setw(15) << timer.toc() / num_samples << endl;
    }

    return 0;
}
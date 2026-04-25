#pragma once
#include <vector>
#include <algorithm>
#include <optional>


// Si crea l'algoritmo di Bubble-Sort
template<typename T>
void bubble_sort(std::vector<T>& A) {
    if (A.empty()) return;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        for (size_t j = A.size() - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}




// Si crea l'algoritmo di Selection-Sort
template<typename T>
void selection_sort(std::vector<T>& A) {
    if (A.empty()) return;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        size_t min = i; 
        for (size_t j = i + 1; j < A.size(); ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }
}




// Si crea l'algoritmo di Insertion-Sort
template<typename T>
void insertion_sort(std::vector<T>& A) {
    for (size_t j = 1; j < A.size(); ++j) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}




// Si crea l'algoritmo di Merge-Sort

// Si crea innanzitutto l'algoritmo di Merge
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    // Si creano gli array L (Left) ed R (Right)
    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    int i = 0;
    int j = 0;   
    // Si implementa la Fusion
    for (int k = p; k <= r; k++) {
        if (i < n1 && (j >= n2 || L[i] <= R[j])) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


// Si implementa successivamente il Merge nell'algoritmo di Merge-Sort
template<typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}




// Si crea l'algoritmo di Quick-Sort

// Si crea innanzitutto l'algoritmo di Partition
template<typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}


// Si implementa successivamente il Partition nell'algoritmo di Quick-Sort
template<typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}




// Si definisce l'algoritmo ottimizzato di Quick-Sort (New_Quick-Sort)

// Si crea innanzitutto l'algoritmo di Insertion Sort che lavori su un intervallo specifico [p, r]
template <typename T>
void insertion_sort_range(std::vector<T>& A, int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        T key = A[j];
        int i = j - 1;
        while (i >= p && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}


// Si implementa successivamente il Partition nell'algoritmo di Quick Sort ottimizzato con la soglia n barrato: n̄ = 42
template <typename T>
void new_quick_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        // Calcola la dimensione del pezzetto attuale
        int n_elementi = r - p + 1;

        if (n_elementi <= 42) {
            // Se piccolo, usa l'operaio specializzato (Insertion)
            insertion_sort_range(A, p, r);
        } else {
            // Se grande, continua a dividere (Quick)
            int q = partition(A, p, r);
            new_quick_sort(A, p, q - 1);
            new_quick_sort(A, q + 1, r);
        }
    }
}

// Si procede in questo modo all'interno del quick sort perché anche partendo da un vettore di N >> 42 elementi, ...
// ... si arriverà sempre ad un punto di doverne ordinare uno di N < 42, dopo un tot numero di ricorsioni dell'algoritmo.






// Si definisce la funzione "is_sorted()" che verifichi se il dato vettore è ordinato
template<typename T>
std::optional<T> is_sorted(const std::vector<T>& vec) {
    if (vec.size() < 2) {
        return std::nullopt;
    }
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i] > vec[i + 1]) {
            return vec[i+1];
        }
    }
    return std::nullopt;
}
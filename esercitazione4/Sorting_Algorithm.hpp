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
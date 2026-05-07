#include <iostream>
#include <vector>
#include "Implementazione_Grafo.hpp"


// Si testa l'implementazione dei grafi
// AI!! TRY AND CATCH
int main() {
    try {
        // Si crea un grafo arbitrario
        unidirected_graph<int> g1;
        
        std::cout << "--- Test Aggiunta Archi ---" << std::endl;
        g1.add_edge(1, 2);
        g1.add_edge(2, 3);
        g1.add_edge(3, 1);
        g1.add_edge(4, 2);
        
        // Si testano i nodi unici
        std::cout << "Nodi nel grafo: ";
        for (int node : g1.all_nodes()) {
            std::cout << node << " ";
        }
        std::cout << "\n" << std::endl;

        // Si testa sui vicini (neighours)
        int target = 2;
        std::cout << "Vicini del nodo " << target << ": ";
        for (int n : g1.neighours(target)) {
            std::cout << n << " ";
        }
        std::cout << "\n" << std::endl;

        // Si testa l'operatore differenza (-)
        unidirected_graph<int> g2;
        g2.add_edge(2, 1);  // Questo arco è presente in entrambi i grafi
        g2.add_edge(1, 6);  // Questo arco è presente soltanto nel grafo g2
        
        std::cout << "--- Test Differenza (G1 - G2) ---" << std::endl;
        unidirected_graph<int> diff = g1 - g2;
        
        std::cout << "Archi rimasti nella differenza:" << std::endl;
        for (const auto& edge : diff.all_edges()) {
            std::cout << edge << " ";
        }
        std::cout << "\n" << std::endl;

        // AI!! Test edge_at e gestione eccezioni
        std::cout << "--- Test Indici ed Eccezioni ---" << std::endl;
        std::cout << "L'arco in posizione 0 è: " << g1.edge_at(0) << std::endl;
        
        std::cout << "Proviamo un indice sbagliato (99)..." << std::endl;
        std::cout << g1.edge_at(99) << std::endl;

    } catch (const std::out_of_range& e) {
        std::cerr << "ECCEZIONE CATTURATA: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Errore generico: " << e.what() << std::endl;
    }

    return 0;
}
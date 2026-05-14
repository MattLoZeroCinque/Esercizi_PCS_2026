#include "Implementazione_Grafo.hpp"
#include <map>
#include <set>
#include <limits>


// AI!! Struttura per restituire sia distanze che predecessori
template<typename I>
struct Dijkstra_Res {
    std::map<I, int> dist;
    std::map<I, I> pred;
};

// Si implementa l'algoritmo di Dijkstra

template<typename I>
Dijkstra_Res<I> Dijkstra(const unidirected_graph<I>& G, const I& s, const std::map<unidirected_edge<I>, int>& W) {
    
    Dijkstra_Res<I> res;
    // AI!! Usiamo un set di coppie {distanza, nodo} per simulare la PQ (Priority Queue) con DecreaseKey
    std::set<std::pair<int, I>> pq;

    // STEP 1: Inizializzazione (ossia "for i=0; i<n; i++")
    for (const auto& i : G.all_nodes()) {
        res.pred[i] = -1;  // Array dei predecessori (AI!! Usiamo -1 come valore nullo)
        res.dist[i] = std::numeric_limits<int>::max();  // Array delle distanze (AI!! Usiamo +infinito come valore massimo)
    }

    res.pred[s] = s;  // Con "s" si identifica la sorgente
    res.dist[s] = 0;

    // STEP 2: PQ.Enqueue per tutti i nodi
    for (const auto& i : G.all_nodes()) {
        pq.insert({res.dist[i], i});
    }

    // STEP 3: Loop principale (while !PQ.empty - finché la coda con priorità non è vuota)
    while (!pq.empty()) {
        I u = pq.begin()->second;
        pq.erase(pq.begin());

        
        for (const auto& w : G.neighours(u)) {
            unidirected_edge<I> edge(u, w);
            int weight_uw = W.at(edge);

            // STEP 3.1: Condizione di rilassamento
            if (res.dist[w] > res.dist[u] + weight_uw) {
                
				// STEP 3.2: Aggiornamento (rimozione ed inserimento) dei valori nella coda 
                pq.erase({res.dist[w], w});
                res.dist[w] = res.dist[u] + weight_uw;
                res.pred[w] = u;
                pq.insert({res.dist[w], w});
            }
        }
    }

    return res;
}
#include "Implementazione_Grafo.hpp"
#include "Visita_Grafo.hpp"
#include "Algoritmo_Dijkstra.cpp"
#include <fstream>

// AI!! Funzione helper per salvare il grafo in formato .dot per GraphViz
template<typename I>
void save_to_dot(const unidirected_graph<I>& G, const std::string& filename) {
    std::ofstream out(filename);
    out << "graph G {" << std::endl;
    for (const auto& edge : G.all_edges()) {
        out << "  " << edge.from() << " -- " << edge.to() << ";" << std::endl;
    }
    out << "}" << std::endl;
}

int main() {
    // Si crea il grafo di esempio
    // AI!! Esempio complesso per evidenziare la differenza BFS vs DFS
    unidirected_graph<int> G;
    G.add_edge(1, 2);
    G.add_edge(1, 3);
    G.add_edge(2, 4);
    G.add_edge(2, 5);
    G.add_edge(3, 6);
    G.add_edge(3, 7);
    G.add_edge(4, 8);
    G.add_edge(5, 8);
    G.add_edge(6, 8);
    G.add_edge(7, 8);


    // Si esegue l'algoritmo di BFS (ossia utilizzando la politica "FIFO")
    fifo<int> q;
    auto bfsTree = graph_visit(G, 1, q);
    save_to_dot(bfsTree, "bfs_result.dot");
    std::cout << "BFS completata: file 'bfs_result.dot' generato." << std::endl;

    // Si esegue l'algoritmo di DFS (ossia utilizzando la politica "LIFO")
    lifo<int> s;
    auto dfsTree = graph_visit(G, 1, s);
    save_to_dot(dfsTree, "dfs_result.dot");
    std::cout << "DFS completata: file 'dfs_result.dot' generato." << std::endl;

    // Si esegue l'algoritmo di Dijkstra, definendo per ogni arco i relativi pesi 
    std::map<unidirected_edge<int>, int> weights;
    weights[unidirected_edge<int>(1, 2)] = 10;
    weights[unidirected_edge<int>(1, 3)] = 3;
    weights[unidirected_edge<int>(2, 4)] = 1;
    weights[unidirected_edge<int>(2, 5)] = 2;
    weights[unidirected_edge<int>(3, 6)] = 7;
	weights[unidirected_edge<int>(3, 7)] = 8;
	weights[unidirected_edge<int>(4, 8)] = 3;
	weights[unidirected_edge<int>(5, 8)] = 1;
	weights[unidirected_edge<int>(6, 8)] = 11;
	weights[unidirected_edge<int>(7, 8)] = 5;

    auto Dijkstra_Res = Dijkstra(G, 1, weights);
    
    std::cout << "\nRisultati Dijkstra (Sorgente: 1):" << std::endl;
    for (const auto& node : G.all_nodes()) {
        std::cout << "Nodo " << node << " -> Distanza: " << Dijkstra_Res.dist[node] 
                  << ", Predecessore: " << Dijkstra_Res.pred[node] << std::endl;
    }

    return 0;
}
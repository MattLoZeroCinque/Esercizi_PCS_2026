#include <deque>
#include <concepts>
#pragma once


// Si implementa la classe "fifo"

template<typename I> requires std::integral<I>
class fifo {
    std::deque<I> q_;  // Si definisce in input il contenitore "q" incapsulato

public:
    // Si implementa il Costruttore di default
    fifo() = default;

    // Si implementa il metodo "put()"
    void put(const I& val) { 
        q_.push_back(val); 
    }

   // Si implementa il metodo "get()"
    I get() { 
        I val = q_.front();
        q_.pop_front();
        return val;
    }

    // Si implementa il metodo "empty()"
    bool empty() const { 
        return q_.empty(); 
    }
};


// Si implementa la classe "lifo"

template<typename I> requires std::integral<I>
class lifo {
    std::deque<I> s_;  // Si definisce in input il contenitore "s" incapsulato

public:
    // Si implementa il Costruttore di default
    lifo() = default;

    // Si implementa il metodo "put()"
    void put(const I& val) { 
        s_.push_back(val); 
    }

    // Si implementa il metodo "get()"
    I get() { 
        I val = s_.back();
        s_.pop_back();
        return val;
    }

    // Si implementa il metodo "empty()"
    bool empty() const { 
        return s_.empty(); 
    }
};



// Si implementa la funzione template "graph_visit()"

template<typename I, typename C>
unidirected_graph<I> graph_visit(const unidirected_graph<I>& G, const I& source, C container) {
    
    unidirected_graph<I> visit_tree;  // Si definisce in input il grafo che conterrà l'albero risultante 
    std::set<I> visited;              // Si definisce in input un set per tenere traccia dei nodi già visitati

    // AI!! Si inserisce il nodo sorgente nel contenitore e lo si segna come visitato
    container.put(source);
    visited.insert(source);

    // Si itera finché il contenitore non è vuoto
    while (!container.empty()) {
        I u = container.get();  // Si estrae un nodo dal contenitore

        // Si esplorano i vicini del nodo corrente "u"
        for (const auto& v : G.neighours(u)) {
            // Si entra nell'"if" se il vicino "v" del nodo corrente "u" non è ancora stato visitato
            if (visited.find(v) == visited.end()) {
                visited.insert(v);           // Si segna il nodo "v" come visitato
                visit_tree.add_edge(u, v);   // Si aggiunge l'arco "u-v" all'albero della visita
                container.put(v);            // Si inserisce il nodo nel contenitore per poterlo visitare in seguito
            }
        }
    }

    return visit_tree;  // Si restituisce l'albero della visita 
}


// AI!! Funzione di supporto (privata/interna) per la ricorsione

template<typename I>
void dfs_helper(const unidirected_graph<I>& G, const I& u, std::set<I>& visited, unidirected_graph<I>& tree) {
    visited.insert(u);  // Segna il nodo attuale come visitato

    // Esplora i vicini
    for (const auto& v : G.neighours(u)) {
        if (visited.find(v) == visited.end()) {
            tree.add_edge(u, v);  // Aggiunge l'arco all'albero
            dfs_helper(G, v, visited, tree);  // Chiamata ricorsiva
        }
    }
}

// Si implementa la funzione "recursive_dfs()"

template<typename I>
unidirected_graph<I> recursive_dfs(const unidirected_graph<I>& G, const I& source) {
    unidirected_graph<I> tree;
    std::set<I> visited;
    
    dfs_helper(G, source, visited, tree);
    
    return tree;
}
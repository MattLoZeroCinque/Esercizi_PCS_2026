#include <iostream>
#include <concepts>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <stdexcept>
#pragma once


// Si implementa la classe "unidirected_edge" per definire gli archi

template<typename I> requires std::integral<I>
class unidirected_edge
{
    I node1_;  // Ossia "from()"
    I node2_;  // Ossia "to()"

public:
    // Si implementa il Costruttore di default: un arco vuoto (o meglio, nullo)
    unidirected_edge()
        : node1_(I{0}), node2_(I{0})
    {}

    // Si implementa il Costruttore user-defined
    unidirected_edge(const I& pnode1, const I& pnode2)
        : node1_(std::min(pnode1, pnode2)), 
          node2_(std::max(pnode1, pnode2))
    {
        // Corpo (vuoto) del costruttore: ho già inizializzato i dati sopra
    }

    // Si implementano i metodi "from()" e "to()"
    I from() const { return node1_; }
    I to() const { return node2_; }
	
	
	// Si implementa l'operatore di uguaglianza
    bool operator==(const unidirected_edge& other) const {
        return (node1_ == other.node1_ && node2_ == other.node2_);  // Due archi sono uguali se e solo se congiungono gli stessi nodi
    }

    // Si implementa l'operatore di confronto (ossia "minore di") per l'ordinamento
    bool operator<(const unidirected_edge& other) const {
        
        if (node1_ < other.node1_) return true;  // Si ordina inizialmente in base al primo nodo (ossia "node1_")
        if (node1_ > other.node1_) return false;
        
        return node2_ < other.node2_;  // Se il primo nodo è uguale, si decide in base al secondo (ossia "node2_")
    }
	
};


// Si stampa l'arco nel formato: ["from()", "to()"]
template<typename I>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<I>& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}




// Si implementa la classe "unidirected_graph" per definire i grafi

template<typename I> requires std::integral<I>
class unidirected_graph {
    
    std::set<unidirected_edge<I>> edges_;  // Si memorizzano gli archi in un set perché esso elimina (o meglio, ignora) i duplicati e li tiene ordinati
    
    std::map<I, std::list<I>> adjacency_list_;  // La mappa associa ogni nodo (chiave) a una lista dei suoi vicini (valore): permette l'implementazione del metodo "neighours()"

public:

    // Si implementa il Costruttore di default: un grafo vuoto
    unidirected_graph() = default;

    // Si implementa il Costruttore di copia
    unidirected_graph(const unidirected_graph& other) 
        : edges_(other.edges_), adjacency_list_(other.adjacency_list_) {}


    // Si implementa il metodo "add_edge()", che aggiunge un arco e aggiorna automaticamente i vicini
    void add_edge(const I& u, const I& v) {
        unidirected_edge<I> edge(u, v);
        edges_.insert(edge);
        
        // Si noti che, essendo un grafo non diretto, u è vicino di v - e viceversa
        adjacency_list_[edge.from()].push_back(edge.to());
        adjacency_list_[edge.to()].push_back(edge.from());
         
    }

    // Si implementa il metodo "neighours()", che restituisce i vicini di un nodo 
    std::list<I> neighours(const I& node) const {
        if (adjacency_list_.find(node) != adjacency_list_.end()) {
            return adjacency_list_.at(node);
        }
        return std::list<I>{};  // Se il nodo non esiste, si restituisce una lista vuota
    }

    // Si implementa il metodo "all_edges()", che restituisce tutti gli archi presenti
    std::set<unidirected_edge<I>> all_edges() const {
        return edges_;
    }

    // Si implementa il metodo "all_nodes()", che restituisce tutti i nodi unici del grafo (ovvero un'unica volta, evitando i doppioni)
    std::set<I> all_nodes() const {
        std::set<I> nodes;
        for (const auto& pair : adjacency_list_) {
            nodes.insert(pair.first);
        }
        return nodes;
    }

    // Si implementa il metodo "edge_number()", che restituisce l'indice (la numerazione) di un arco nel set:
	// esso cicla nel set finché non trova l'arco corrispondente, contando i passi necessari per arrivarci; se non lo trova, lancia un'eccezione ("out_of_range")
    size_t edge_number(const unidirected_edge<I>& edge) const {
        size_t index = 0;
        for (const auto& e : edges_) {
            if (e == edge) return index;
            index++;
        }
        throw std::out_of_range("Arco non trovato");
    }

    // Si implementa il metodo "edge_at()", che restituisce l'arco corrispondente a un numero d'ordine
	// Poiché "std::set" non permette l'accesso diretto tramite [], scorriamo il set e contiamo gli elementi fino a raggiungere l'indice desiderato.
	//  [[ Sono consapevole del fatto che sia inefficiente (ha complessità O(n) - ossia lineare) ]]
    unidirected_edge<I> edge_at(size_t index) const {
    if (index >= edges_.size()) {
        throw std::out_of_range("Indice arco fuori limite");
    }

    size_t count = 0;
    // Si itera sugli archi del set, uno per uno
    for (const auto& e : edges_) {
        if (count == index) {
            return e;  // Si restituisce l'arco
        }
        count++;
    }
    
    // AI!! Questo punto non dovrebbe mai essere raggiunto grazie al controllo iniziale, ma lo mettiamo per sicurezza del compilatore.
    throw std::out_of_range("Errore imprevisto");
}


    // Si implementa l'operatore differenza tra grafi
    unidirected_graph operator-(const unidirected_graph& other) const {
        unidirected_graph result;
        for (const auto& e : edges_) {
            // Se l'arco di questo grafo non è presente nell'altro (other), lo si aggiunge
            if (other.edges_.find(e) == other.edges_.end()) {
                result.add_edge(e.from(), e.to());
            }
        }
        return result;
    }
};


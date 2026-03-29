#include <iostream>
#include "Implementazione_Razionali.hpp"


int main(void)
{
    // Si creano dei razionali-test
    rational<int> a(1, 2);
    rational<int> b(1, 3);
    
    // Si testa somma tramite l'operatore "+"
    rational<int> c = a + b;
    
    // Si stampano i singoli dati numerici usando i metodi di accesso
    std::cout << c.num() << " " << c.den() << "\n";
    
   // Si stampa il razionale usando l'operatore "cout <<" (e gestendo "/" ed i casi "Inf" o "NaN")
    std::cout << c << "\n";
    
    // Si testa un caso speciale (ossia di semplificazione)
    rational<int> r(40, 100);
    std::cout << r << "\n";

    return 0;
}
#include <iostream>
#include <Eigen/Eigen>
#include "Gradiente_Coniugato.hpp"

int main(int argc, char **argv) 
{
  unsigned int n = 10;
  std::cout << "--- Avvio del Test per il Metodo del Gradiente Coniugato (con n = " << n << ") ---" << std::endl;

  int res_method = Gradiente_Coniugato(n);

  if (res_method == -1)
  {
    std::cerr << "Errore!" << std::endl;
    return -1;
  }

  std::cout << "--- Test completato con successo ---" << std::endl;

  return 0;
}
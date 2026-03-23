// WARNING! USO DELL'IA PER LA RANDOMIZZAZIONE (MI SEMBRAVA MOLTO PIÙ CARINO FARLO COSÌ)


#include <iostream>
#include <algorithm> // per std::min, std::max
#include <cmath>     // per std::sqrt
#include <random>


using namespace std;

int main() {
    static const int N = 16;
    double arr[N];

    // Randomizzazione
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 50.0);

    cout << "L'array generato randomicamente è il seguente: ";
    for (int i = 0; i < N; ++i) {
        arr[i] = dis(gen);
        cout << arr[i] << " ";
    }
	
    cout << "\n\n";


    // Si calcolano il minimo, il massimo e la media
    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0;

    for (int i = 0; i < N; ++i) {
        minimo = min(minimo, arr[i]);
        massimo = max(massimo, arr[i]);
        somma += arr[i];
    }

    double media = somma / N;


    // Si calcola la deviazione standard
    double somma_quadrati_diff = 0;
    for (int i = 0; i < N; ++i) {
        somma_quadrati_diff += pow(arr[i] - media, 2);
    }
    double dev_std = sqrt(somma_quadrati_diff / N);

    
	
    cout << "Risultati:\n";
    cout << "Il minimo valore all'interno dell'array è: " << minimo << "\n";
    cout << "Il massimo valore all'interno dell'array è: " << massimo << "\n";
    cout << "La media tra i valori all'interno dell'array è: " << media << "\n";
    cout << "La deviazione standard tra i valori all'interno dell'array è: " << dev_std << "\n";


    return 0;
}
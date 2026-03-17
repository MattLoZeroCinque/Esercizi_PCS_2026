#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	
    // 1) Si chiede all'utente di inserire il nome del file
    string filename;
    cout << "Inserisci il nome del file: ";
    cin >> filename; 

    ifstream ifs(filename);

    // 2) Si controlla l'apertura del file
    if (!ifs.is_open()) {
        cerr << "Errore! Impossibile aprire il file: " << filename << endl;
        return 1; // Esci con errore
    }

    string location;
    double temp_1, temp_2, temp_3, temp_4;

    // 3) Si legge la tabella e si computano le medie
    while (ifs >> location >> temp_1 >> temp_2 >> temp_3 >> temp_4) {
        double media = (temp_1 + temp_2 + temp_3 + temp_4) / 4.0;
        cout << location << " " << media << endl;
    }

    ifs.close();
    return 0;
}

	

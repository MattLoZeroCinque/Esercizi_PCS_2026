# include <iostream>


using namespace std;

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    (&y)[1] = 0;

    cout << x << "\n";
	
	
	
	for (int i = 0; i <= 3; i++) {
	    cout << "L'indirizzo dell'elemento" << " " << i << " " << "dell'array di double è:" << " " << &ad[i] << "\n";
	}

    cout << "Siccome 'sizeof(double) = 8' (ossia ogni double occupa 8 byte in memoria) e l'array è una sequenza ordinata di elementi, la differenza fra '&ad[0]' ed '&ad[4]' deve essere di: '8*4' = '32'" << "\n";
	
	
	
	for (int i = 0; i <= 7; i++) {
	    cout << "L'indirizzo dell'elemento" << " " << i << " " << "dell'array di float è:" << " " << &af[i] << "\n";
	}
	
	cout << "Siccome 'sizeof(float) = 4' (ossia ogni float occupa 4 byte in memoria) e l'array è una sequenza ordinata di elementi, la differenza fra '&af[0]' ed '&af[7]' deve essere di: '4*8' = '32'" << "\n";
	
	
	
	for (int i = 0; i <= 2; i++) {
	    cout << "L'indirizzo dell'elemento" << " " << i << " " << "dell'array di int è:" << " " << &ai[i] << "\n";
	}
	
	cout << "Siccome 'sizeof(int) = 4' (ossia ogni int occupa 4 byte in memoria) e l'array è una sequenza ordinata di elementi, la differenza fra '&ai[0]' ed '&ai[2]' deve essere di: '4*3' = '12'" << "\n";
	
	
	
	cout << "L'indirizzo dell'int" << " " << "x =" << " " << x << " " << "è" << " " << &x << "\n";
	
	cout << "L'indirizzo del float" << " " << "y =" << " " << y << " " << "è" << " " << &y << "\n";
	
	
    return 0;
}



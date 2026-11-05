// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

bool esPosible(const vector<int> & pesos, int peso, int viajesMaximos){

    int peso_actual = 0;
    int num_viajes = 1;
    int i = 0;
    bool salir = false;

    while(i < pesos.size() && !salir){
        if(peso_actual + pesos[i] > peso){
            peso_actual = pesos[i];
            num_viajes++;
            if(num_viajes > viajesMaximos)
                salir = true;
        }
        else{
            peso_actual += pesos[i];
        }
        i++;
    }

    return salir == false;

}

// función que resuelve el problema
int resolver(const vector<int> & pesos, int viajesMaximos) {
    
    int ini = 0;
    int fin = 0;
    
    for (int p : pesos) {
        if (p > ini) {
            ini = p;
        }
        fin += p;
    }
    
    int mejor_capacidad = fin;

    while(fin >= ini){
        int mitad = ini + (fin - ini) / 2;
        if (esPosible(pesos, mitad, viajesMaximos)) {
            mejor_capacidad = mitad;
            fin = mitad - 1; 
        } else {
            ini = mitad + 1; 
        }
    }
    
    return mejor_capacidad;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num_obras, viajesMaximos;
    
    // leer los datos de la entrada
    std::cin >> num_obras >> viajesMaximos;
    
    // Si no se puede leer más (fin de fichero), terminamos
    if (num_obras == 0 && viajesMaximos == 0)
        return false;
        
    // Cargamos los pesos de las obras respetando el orden
    std::vector<int> pesos(num_obras);
    for (int i = 0; i < num_obras; ++i) {
        std::cin >> pesos[i];
    }
    
    int sol = resolver(pesos, viajesMaximos);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}

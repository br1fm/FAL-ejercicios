// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct{
    int cota_baja = 0;
    int cota_alta = 0;
}tSolucion;

// función que resuelve el problema
tSolucion resolver(const vector<int> & edificios, int altura_nave) {
    tSolucion ret;
    //TODO: hacer el bucle.
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n_edificios, altura_nave;
    cin >> n_edificios;
    cin >> altura_nave;
    vector<int> edificios(n_edificios);
    for(int i = 0; i < n_edificios; i++){
        cin >> edificios[i];
    }
    
    tSolucion sol = resolver(edificios, altura_nave);
    // escribir sol
    cout << sol.cota_baja << " ";
    cout << sol.cota_alta << "\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct{

    int cont_picos = 0;
    int cont_valles = 0;

} tSolucion;

// función que resuelve el problema
tSolucion resolver(const vector<int> & datos) {
    tSolucion ret;
    for(int i = 1; i < datos.size() - 1; i++){
        if(datos[i] > datos[i - 1] && datos[i] > datos[i + 1]) ret.cont_picos++;
        if(datos[i] < datos[i - 1] && datos[i] < datos[i + 1]) ret.cont_valles++;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n_temps;
    cin >> n_temps;
    vector<int> datos(n_temps);
    for(int i = 0; i < n_temps; i++){
        cin >> datos[i];
    }
    
    tSolucion sol = resolver(datos);
    // escribir sol
    cout << sol.cont_picos << " " << sol.cont_valles << "\n";
    
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
// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n_etapas;
    cin >> n_etapas;
    if (n_etapas == -1)
        return false;

    vector<long long int> etapas(n_etapas + 1);
    long long int acum = 0, elem;

    for(int i = 0; i < n_etapas; i++){
        etapas[i] = acum;
        cin >> elem;
        acum += elem;
    }
    etapas[n_etapas] = acum;
    
    int n_dudas;
    cin >> n_dudas;
    for(int i = 0; i < n_dudas; i++){
        cin >> elem;
        cout << acum - etapas[elem - 1] << "\n";
    }

    cout << "---\n";

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

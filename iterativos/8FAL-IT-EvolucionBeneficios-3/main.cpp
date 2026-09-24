// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
vector<int> resolver(const vector<int> & datos, int anyo_ini) {
    vector<int> ret;
    int max = datos[0];
    for(int i = 0; i < datos.size(); i++){
        if(datos[i] > max){
            max = datos[i];
            ret.push_back(anyo_ini + i);
        } 
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int anyo_ini, anyo_fin, n_anyos;

    cin >> anyo_ini;
    cin >> anyo_fin;
    n_anyos = anyo_fin - anyo_ini + 1;

    vector<int> datos(n_anyos);
    for(int i = 0; i < n_anyos; i++){
        cin >> datos[i];
    }

    vector<int> sol = resolver(datos, anyo_ini);
    // escribir sol
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
    cout << "\n";

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
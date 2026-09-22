// Nombre del alumno Bruno Fernández Mínguez
// Usuario del Juez FAL-A73


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;


// función que resuelve el problema

//La complejidad de la función es O(n), ya que se consulta cada dato del vector datos
//solamente una vez en un recorrido for.

//para todo i : 0 <= i < datos.size() : resultado <= datos[i]
//resultado pertenece al dominio de la variable datos
string resolver(const vector<string> & datos) {

    string min = datos[0];

    for(int i = 1; i < datos.size(); i++){
        if(datos[i] < min) min = datos[i];
    }

    return min;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<string> v;
    int n;
    string elem;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> elem;
        v.push_back(elem);
    }
    
    string sol = resolver(v);
    // escribir sol
    cout << sol << '\n';
    
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
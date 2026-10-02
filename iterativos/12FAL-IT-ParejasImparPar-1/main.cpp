// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & datos) {
    int cont_pares = 0, acum = 0;
    for(int i = datos.size() - 1; 0 <= i; i--){
        if(datos[i] % 2 == 0)
            cont_pares++;
        else
            acum += cont_pares;
    }
    return acum;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n_datos;
    cin >> n_datos;
    vector<int> datos(n_datos);
    
    for(int i = 0; i < n_datos; i++){
        cin >> datos[i];
    }

    int sol = resolver(datos);
    // escribir sol
    cout << sol << "\n";
    
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
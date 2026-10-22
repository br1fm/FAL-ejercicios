// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tSolucion {
    long long rendimiento = 0;
    int longitud = 0;
    int inicio = 0;
};

// Función que resuelve el problema
tSolucion resolver(const vector<int>& datos) {

    tSolucion ret;

    long long acum = 0;
    int inicio_actual = 0;

    for (int i = 0; i < datos.size(); i++) {

        acum += datos[i];

        if (acum <= 0) {
            acum = 0;
            inicio_actual = i + 1;
        }
        else {

            int longitud_actual = i - inicio_actual + 1;

            if (acum > ret.rendimiento || (acum == ret.rendimiento && longitud_actual <= ret.longitud)) {

                ret.rendimiento = acum;
                ret.longitud = longitud_actual;
                ret.inicio = inicio_actual;
            }
        }
    }

    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<int> datos(n);

    for(int i = 0; i < n; i++){
        cin >> datos[i];
    }
    
    tSolucion sol = resolver(datos);
    // escribir sol
    cout << sol.rendimiento << " " << sol.longitud <<  " " << sol.inicio << "\n";
    
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
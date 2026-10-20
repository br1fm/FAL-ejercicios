// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    int indice;
    int valor;
}tSolucion;

// función que resuelve el problema
tSolucion resolver(const vector<int>& datos, int tam) {
    int max = 0, acum = 0, j = 0, indice = 0;
    for (int i = 0; i < datos.size(); i++) {
        acum += datos[i];
        if ((i - j + 1) > tam) {
            acum -= datos[j];
            j++;
        }
        if (acum >= max) {
            indice = j;
            max = acum;
        }
    }
    return { indice, max };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nVag, tam;
    cin >> nVag >> tam;

    vector<int> datos(nVag);

    for (int i = 0; i < nVag; i++) {
        cin >> datos[i];
    }

    tSolucion sol = resolver(datos, tam);
    cout << sol.indice << " " << sol.valor << "\n";
    // escribir sol
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
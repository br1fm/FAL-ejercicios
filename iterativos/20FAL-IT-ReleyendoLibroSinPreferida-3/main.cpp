// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& datos, int tam) {
    int max = 0, acum = 0, j = 0, ret = 0;
    for (int i = 0; i < datos.size(); i++) {
        acum += datos[i];
        if ((i - j + 1) > tam) {
            acum -= datos[j];
            j++;
        }
        if (acum >= max) {
            ret = j;
            max = acum;
        }
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nPag, tam;
    cin >> nPag >> tam;

    if (nPag == 0 && tam == 0)
        return false;

    vector<int> datos(nPag);

    for (int i = 0; i < nPag; i++) {
        cin >> datos[i];
    }

    int sol = resolver(datos, tam);
    cout << sol << "\n";
    // escribir sol

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

// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Función que busca la posición más a la izquierda del elemento
int binarySearchIz(vector<int> const& v, int elem, int ini, int fin) {
    if (ini >= fin)
        return ini; // Vector vacío

    else if (ini + 1 == fin)
        return ini; // Vector de un elemento

    else {
        // Vector de dos o más elementos
        int mitad = (ini + fin - 1) / 2;

        if (v[mitad] < elem)
            return binarySearchIz(v, elem, mitad + 1, fin);
        else
            return binarySearchIz(v, elem, ini, mitad + 1); // Incluye la mitad
    }
}

// Función que busca la posición más a la derecha del elemento
int binarySearchDr(vector<int> const& v, int elem, int ini, int fin) {
    if (ini >= fin)
        return ini; // Vector vacío

    else if (ini + 1 == fin)
        return ini; // Vector de un elemento

    else {
        // Vector de dos o más elementos
        int mitad = (ini + fin) / 2;

        if (elem < v[mitad])
            return binarySearchDr(v, elem, ini, mitad);
        else
            return binarySearchDr(v, elem, mitad, fin); // Incluye la mitad
    }
}

// Función que resuelve cada caso de prueba
bool resuelveCaso() {
    int numelem, elem;

    cin >> numelem;

    if (!std::cin)
        return false;

    cin >> elem;

    vector<int> v(numelem);

    for (int& n : v)
        cin >> n;

    // Busca en el lado izquierdo
    int posIz = binarySearchIz(v, elem, 0, (int)v.size());

    if (posIz == v.size() || v[posIz] != elem) {
        cout << "NO EXISTE\n";
    }
    else {
        // Si existe el elemento, busca en el lado derecho
        int posDr = binarySearchDr(v, elem, 0, (int)v.size());

        if (posIz == posDr)
            cout << posIz << '\n';
        else
            cout << posIz << ' ' << posDr << '\n';
    }

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
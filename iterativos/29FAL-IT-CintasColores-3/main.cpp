// Nombre del alumno .....
// Usuario del Juez .....

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tStruct {
    char color;
    int longitud;
};

bool operator<(const tStruct & a, const tStruct & b) {
    return a.longitud < b.longitud;
}

// Coste: O(n), siendo n el número de cintas.
// En cada iteración avanza k o retrocede q,
// por lo que se recorren los elementos una sola vez.

void particion(vector<tStruct> & v, int & p, int & q) {

    p = 0;
    q = v.size() - 1;
    int k = 0;

    while (k <= q) {

        if (v[k].color == 'v') {
            k++;
        }
        else if (v[k].color == 'a') {
            swap(v[p], v[k]);
            p++;
            k++;
        }
        else {
            swap(v[q], v[k]);
            q--;
        }
    }
}

// Resuelve un caso de prueba
bool resuelveCaso() {

    int numCintas;
    cin >> numCintas;

    if (!cin)
        return false;

    vector<tStruct> v(numCintas);

    for (int i = 0; i < numCintas; i++) {
        cin >> v[i].color >> v[i].longitud;
    }

    int p, q;
    particion(v, p, q);

    sort(v.begin(), v.begin() + p);
    sort(v.begin() + p, v.begin() + q + 1);
    sort(v.begin() + q + 1, v.end());

    cout << "Azules:";
    for (int i = 0; i < p; i++) {
        cout << " " << v[i].longitud;
    }
    cout << "\n";

    cout << "Verdes:";
    for (int i = p; i <= q; i++) {
        cout << " " << v[i].longitud;
    }
    cout << "\n";

    cout << "Rojas:";
    for (int i = q + 1; i < v.size(); i++) {
        cout << " " << v[i].longitud;
    }
    cout << "\n";

    return true;
}

int main() {

#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif

    return 0;
}
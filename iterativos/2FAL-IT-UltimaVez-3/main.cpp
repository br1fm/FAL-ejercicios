#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// función que resuelve el problema
int resolver(const vector<string>& datos, const string& nacion) {

    int i = datos.size() - 1;

    while (i >= 0) {

        if (datos[i] == nacion)
            return datos.size() - i;

        i--;
    }

    return -1;
}


// Resuelve un caso de prueba
bool resuelveCaso() {

    vector<string> v;

    int anyos;
    cin >> anyos;

    if (anyos == 0)
        return false;

    string nacion;
    cin >> nacion;

    for (int i = 0; i < anyos; i++) {
        string dato;
        cin >> dato;
        v.push_back(dato);
    }

    int sol = resolver(v, nacion);

    if (sol == -1)
        cout << "NUNCA\n";
    else
        cout << sol << '\n';

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
    system("PAUSE");   // quitar en Linux
#endif

    return 0;
}
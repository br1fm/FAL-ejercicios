// Nombre del alumno Bruno Fernández Mínguez
// Usuario del Juez FAL-A73


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Coste: O(n), siendo n el número de páginas.
// Se recorre el vector una sola vez.
// En cada iteración se realizan operaciones de coste constante.

int resolver(const vector<int> & datos, int L, int max) {

    int ret = 0, acum = 0, acum_max = -1, pos_max = -1;

    for (int i = 0; i < datos.size(); i++) {

        acum += datos[i];

        if (datos[i] == max) pos_max = i;

        if (i >= L) acum -= datos[i - L];

        if (i >= L - 1) {
            if (pos_max >= i - L + 1){
                if (acum >= acum_max){
                    acum_max = acum;
                    ret = i - L + 1;
                }
            }
        }
    }

    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L, max = 0;
    cin >> n;
    cin >> L;

    if (n == 0 && L == 0)
        return false;
    
    vector<int> datos(n);

    for(int i = 0; i < n; i++){
        cin >> datos[i];
        if(datos[i] > max) max = datos[i];
    }

    int sol = resolver(datos, L, max);
    
    // escribir sol

    cout << sol << "\n";
    
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

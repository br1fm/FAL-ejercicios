// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int> & datos, int k) {
    
int dist_min = datos.size() + 1;
    int cont_unos = 0;
    int inicio = 0;

    for(int i = 0; i < datos.size(); i++){

        if(datos[i] == 1)
            cont_unos++;

        while(cont_unos == k){

            int dist = i - inicio + 1;

            if(dist < dist_min)
                dist_min = dist;

            if(datos[inicio] == 1)
                cont_unos--;

            inicio++;
        }
    }

    return dist_min;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n;

    if (n == -1)
        return false;

    vector<int> datos(n);
    
    for(int i = 0; i < n; i++)
        cin >> datos[i];
    
    cin >> k;

    int sol = resolver(datos, k);
    
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

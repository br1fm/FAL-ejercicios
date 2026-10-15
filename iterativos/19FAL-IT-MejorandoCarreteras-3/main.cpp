// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> & datos) {

    int cont = 1, cont_max = 1;
    sort(datos.begin(), datos.end());
    int ret = datos[0];

    for(int i = 0; i < datos.size() - 1; i++){
        if(datos[i] == datos[i + 1]) cont++;
        else cont = 1;
        if(cont > cont_max){
            ret = datos[i];
            cont_max = cont;
        } 
    }

    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n_datos;
    cin >> n_datos;
    if (n_datos == -1)
        return false;

    vector<int> datos(n_datos);

    for(int i = 0; i < n_datos; i++)
        cin >> datos[i];
    
    int sol = resolver(datos);
    
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

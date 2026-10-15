// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int> & datos, int n_nums) {
    
    vector<int> aux(n_nums);
    vector<int> ret;
    int cont_max = 0;

    for(int i = 0; i < datos.size(); i++){
        aux[datos[i] - 1]++;
        if(aux[datos[i] - 1] > cont_max) cont_max = aux[datos[i] - 1];
    }

    for(int i = aux.size() - 1; i >= 0; i--){
        if(aux[i] == cont_max) ret.push_back(i + 1);
    }

    return ret;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n_datos = 0;
    cin >> n_datos;
    if (n_datos == -1)
        return false;
    int n_nums;
    cin >> n_nums;
    vector<int> datos(n_datos);
    for(int i = 0; i < n_datos; i++)
        cin >> datos[i];
    vector<int> sol = resolver(datos, n_nums);
    
    // escribir sol

    for(int i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    cout << "\n";
    
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

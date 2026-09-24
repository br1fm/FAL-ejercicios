// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//para todo i , j : 0 =< i < j < datos.size
// función que resuelve el problema
string resolver(const vector<int> & datos) {

    if(datos.size() == 0) return "EN LA MITAD";

    int i_ini = 0, i_fin = datos.size() - 1;
    int acum_ini = datos[i_ini], acum_fin = datos[i_fin];
    string ret = "NINGUNA";

    while(i_fin - i_ini > 1){
        if(acum_ini < acum_fin){
            i_ini++;
            acum_ini += datos[i_ini];
        }
        else if(acum_ini > acum_fin){
            i_fin--;
            acum_fin += datos[i_fin];
        }
        else{
            i_ini++;
            i_fin--;
            acum_ini += datos[i_ini];
            acum_fin += datos[i_fin];
        }
    }

    if(acum_ini == acum_fin && i_ini != i_fin) ret = to_string(i_ini + 1) + " " + to_string(i_fin + 1);
        
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> datos;
    int elem;
    cin >> elem;
    while(elem != -1){
        datos.push_back(elem);
        cin >> elem;
    }
    string sol = resolver(datos);
    // escribir sol
    cout << sol << "\n";
    
    
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
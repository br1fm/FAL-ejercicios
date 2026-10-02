// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//   max(para todo i : 0 <= i < datos.size() :
//   suma(datos[e] : e <= i < n) == datos[i])
// función que resuelve el problema
bool resolver(const vector<int> & datos, int & indice) {
    int acum = 0, i = datos.size() - 1;
    bool salir = false;
    while(i >= 0 && !salir){
        if(acum == datos[i]){
            salir = true;
            indice = i;
        }
        acum += datos[i];
        i--;
    }
    return (indice != -1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, indice = -1;
    cin >> n;
    vector<int> datos(n);
    
    for(int i = 0; i < n; i++){
        cin >> datos[i];
    }

    bool sol = resolver(datos, indice);
    // escribir sol
    if(!sol)
        cout << "No\n";
    else
        cout << "Si " << indice << "\n";
    
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
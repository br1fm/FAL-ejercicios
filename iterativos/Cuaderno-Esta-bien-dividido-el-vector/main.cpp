// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

// función que resuelve el problema
/*
    Se van a recorrer dos bucles, uno de p + 1 a n - 1, y otro de 0 a p.
    Ambos recorridos son lineales, y en el peor caso el segundo bucle se va a tener que
    recorrer de forma completa, por lo que su complejidad va a ser lineal O(n).
*/
bool resolver(const vector<int> & datos, int p) {
    int min = INT_MAX;
    for(int i = p + 1; i < datos.size(); i++){
        if(datos[i] < min) min = datos[i];
    }
    int e = 0;
    bool ordenado = true;
    while(e <= p && ordenado){
        if(datos[e] >= min) ordenado = false;
        e++;
    }
    return ordenado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    vector<int> v;
    int n, p, elem;
    cin >> n;
    cin >> p;

    for(int i = 0; i < n; i++){
        cin >> elem;
        v.push_back(elem);
    }
    
    bool sol = resolver(v,p);
    // escribir sol
    sol ? cout << "SI\n" : cout << "NO\n";
    
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
     //system("PAUSE");
     #endif
    
    return 0;
}
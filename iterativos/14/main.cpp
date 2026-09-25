// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef struct{
    string id;
    int altura_edif;
    int altura_piso;
} tEdificio;

// función que resuelve el problema
vector<string> resolver(const vector<tEdificio> & datos) {
    vector<string> ret;
    int altura_max = 0;
    for(int i = datos.size() - 1; i >= 0; --i){
        if(datos[i].altura_piso > altura_max)
            ret.push_back(datos[i].id);
        if(datos[i].altura_edif > altura_max)
            altura_max = datos[i].altura_edif; 
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<tEdificio> datos(n);
    for(int i = 0; i < n; i++){
        cin >> datos[i].id;
        cin >> datos[i].altura_edif;
        cin >> datos[i].altura_piso;
    }
    vector<string> sol = resolver(datos);
    // escribir sol
    if(sol.size() == 0) cout << "Ninguno" << "\n";
    else {  
        cout << sol.size() << "\n";
        for(int i = 0; i < sol.size(); i++){
            cout << sol[i] << " ";
        }
        cout << "\n";
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


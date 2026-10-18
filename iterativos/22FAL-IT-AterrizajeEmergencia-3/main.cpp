// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(const vector<int> & datos, vector<int> & ret, int L) {
    bool en_tramo = false;
    int cont = 0;
    for(int i = 0; i < datos.size() - 1; i++){
        if(abs(datos[i] - datos[i + 1]) <= 1){
            cont++;
            if(cont == L - 1){
                if(en_tramo == false){
                    en_tramo = true;
                    ret.push_back(((i + 1) - L) + 1);
                }
            }
        }
        else{
            en_tramo = false;
            cont = 0;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, L;
    cin >> n >> L;
    if (n == 0 && L == 0)
        return false;
    
    vector<int> datos(n), sol;

    for(int i = 0; i < n; i++){
        cin >> datos[i];
    }

    resolver(datos, sol, L);
    
    // escribir sol

    cout << sol.size() << " ";
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
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

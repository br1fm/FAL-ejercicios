// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> v1, vector<int> v2, vector<int> & ret) {
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0, j = 0;

    while(i < v1.size() || j < v2.size()){
        if(j < v2.size() && !(i < v1.size())){
            ret.push_back(v2[j]);
            j++;
        }
        else if(i < v1.size() && !(j < v2.size())){
            ret.push_back(v1[i]);
            i++;
        }
        else{
            if(v1[i] == v2[j]){
                i++;
                j++;
            }
            else{
                if(v1[i] < v2[j]){
                    ret.push_back(v1[i]);
                    i++;
                } 
                else{
                    ret.push_back(v2[j]);
                    j++;
                }
            }
        }

    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int elem;
    vector<int> v1, v2, sol;
    cin >> elem;

    while(elem != 0){
        v1.push_back(elem);
        cin >> elem;
    }

    cin >> elem;

    while(elem != 0){
        v2.push_back(elem);
        cin >> elem;
    }

    resolver(v1, v2, sol);

    // escribir sol
    
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
    cout << "\n";
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
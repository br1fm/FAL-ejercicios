// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
//Tiene una complejidad constante al no acceder a valores en bucles.
long long int resolver(const vector<long long int> & datos, int anyo_min, int cota_baja, int cota_alta) {
    
    int i = cota_baja - anyo_min;
    long long int ret = datos[cota_alta - anyo_min];
    if(i != 0)
        ret -= datos[i - 1];
    return ret;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anyo_min, anyo_max;
    vector<long long int> datos;
    cin >> anyo_min >> anyo_max;

    if (anyo_min == 0 && anyo_max == 0)
        return false;
    
    //La preparación de los datos tiene coste lineal en el número de datos que tiene el parque.
    int n_anyos = anyo_max - anyo_min + 1;
    long long int acum = 0, elem;
    for(int i = 0; i < n_anyos; i++){
        cin >> elem;
        acum += elem;
        datos.push_back(acum);
    }

    int n_preguntas, cota_baja, cota_alta;
    cin >> n_preguntas;

    for(int i = 0; i < n_preguntas; i++){
        cin >> cota_baja;
        cin >> cota_alta;
        cout << resolver(datos, anyo_min, cota_baja, cota_alta) << "\n";
    }

    cout << "---\n";
        
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

// Nombre del alumno Bruno Fernández Mínguez
// Usuario del Juez FAL-A73


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//Invariante:
//  unocero_cont contiene el número de unos menos
//  el número de ceros de los primeros i elementos del vector.
//  mientras que ret representa el mayor índice en el cual el número
//  de unos menos el número de ceros es 0. En caso de no encontrarse ninguno,
//  la función va a devolver -1.
//Cota superior:
//  el máximo de datos a procesar por la función es datos.size()
//Cota inferior:
//  el mínimo de datos a procesar por la función es 0, ya que si el vector está vacío
//  este caso también se trata, devolviendo -1.
//Complejidad: solo se recorren los datos del vector una sola vez
//  por lo que la complejidad es O(n) siendo n el número de datos del
//  vector
int resolver(const vector<int> & datos) {

    int unocero_cont = 0;
    int ret = -1;

    for (int i = 0; i < datos.size(); i++) {

        if (datos[i] == 1)
            unocero_cont++;
        else if(datos[i] == 0)
            unocero_cont--;

        if (unocero_cont == 0)
            ret = i;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    int i = 0;
    vector<int> datos(n);
    while(i < n){
        cin >> datos[i];
        i++;
    }
    int sol = resolver(datos);
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
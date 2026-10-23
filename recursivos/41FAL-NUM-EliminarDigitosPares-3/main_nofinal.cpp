// Nombre del alumno Bruno Fernández Mínguez
// Usuario del Juez FAL-A73


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
long long int resolverNoFinal(long long int e, long long int pot) {
    if(e < 10){
        if(e % 2 == 0) return 0;
        else return e * pot;
    }
    else{
        if((e%10) % 2 == 0) return resolverNoFinal(e/10, pot);
        else return (e%10 * pot) + resolverNoFinal(e/10, pot*10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    cin >> numero;

    if (! std::cin)
        return false;
    
    long long int sol = resolverNoFinal(numero, 1);
    
    // escribir sol
    
    cout << sol << " " << sol << "\n";
    
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
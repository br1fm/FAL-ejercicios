// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int resolverNoFinal(int numero, int repe) {
    
    if(numero < 10){
        if(numero == repe) return 1;
        else return 0;
    }
    if(numero % 10 == repe){
        return 1 + resolverNoFinal(numero/10, repe);
    }
    else{
        return resolverNoFinal(numero/10, repe);
    }
    
}

// función que resuelve el problema
int resolverFinal(int numero, int repe, int cont) {
    
    if(numero < 10){
        if(numero == repe) return cont + 1;
        else return cont;
    }
    if(numero % 10 == repe){
        return (resolverFinal(numero/10, repe, cont + 1));
    }
    else{
        return resolverFinal(numero/10, repe, cont);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero, repe;
    cin >> numero >> repe;
    
    cout << resolverFinal(numero, repe, 0) << " " << resolverNoFinal(numero, repe) << "\n";
    
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
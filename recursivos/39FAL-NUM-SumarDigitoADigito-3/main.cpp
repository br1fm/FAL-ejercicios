// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
long long int resolverNoFinal(int numero1, int numero2) {
    
    if(numero1 == 0 && numero2 == 0){
        return 0;
    }
    else{
        return ((numero1 % 10 + numero2 % 10) % 10) + resolverNoFinal(numero1 / 10, numero2 / 10) * 10;
    }

}

long long int resolverFinal(int numero1, int numero2, long long int resultado, long long int pot) {

    if (numero1 == 0 && numero2 == 0) {
        return resultado;
    }
    else {
        int aux1 = numero1 % 10;
        int aux2 = numero2 % 10;
        int aux_ret = (aux1 + aux2) % 10;

        resultado = resultado + aux_ret * pot;

        return resolverFinal(numero1 / 10, numero2 / 10, resultado, pot * 10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero1, numero2;
    cin >> numero1 >> numero2;
    
    long long int sol = resolverFinal(numero1, numero2, 0, 1);
    long long int sol1 = resolverNoFinal(numero1, numero2);
    // escribir sol
    cout << sol << " " << sol1 << "\n";
    
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
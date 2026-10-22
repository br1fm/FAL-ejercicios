// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int resolverFinal(int e, int resultado, int pot) {
    
    if(e < 10){
        int e_modif;
        if(e % 2 == 0){
            e_modif = e + 1;
        }else{
            e_modif = e - 1;
        }
        resultado += e_modif * pot;
        return resultado;
    }
    else{
        int uno;
        ((e%10) % 2 == 0 ? uno = 1 : uno = -1);
        resultado = resultado + (e%10 + uno) * pot;
        return resolverFinal(e/10, resultado, pot*10);
    }
    
}

// función que resuelve el problema
int resolverNoFinal(int e) {
    
    if(e < 10){
        if(e % 2 == 0) return e + 1;
        else return e - 1;
    }
    else{
        if((e%10) % 2 == 0) return (e%10 + 1) + resolverNoFinal(e/10) * 10;
        else return (e%10 - 1) + resolverNoFinal(e/10) * 10;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    cin >> numero;
    
    int sol = resolverFinal(numero, 0, 1);
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
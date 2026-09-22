// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tNacimientos{
    int anyo;
    long long int nacimientos;
};


// función que resuelve el problema
int resolver(const vector<tNacimientos> & datos, int anyo1, int anyo2) {
    
    int i = 0;
    int acum = 0;
    bool salir = false;
    while(i < datos.size() && !salir){
        if(anyo1 <= datos[i].anyo && datos[i].anyo <= anyo2) acum += datos[i].nacimientos;
        else if(datos[i].anyo > anyo2) salir = true;
        i++;
    }
    return acum;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anyo1, anyo2, n = 0, e = 0;
    cin >> anyo1;
    cin >> anyo2;

    vector<tNacimientos> v;
    vector<int> anyos;

    if (anyo1 == 0 && anyo2 == 0)
        return false;
    
    n = (anyo2 - anyo1) + 1;
    
    for(int i = 0; i < n; i++){
        tNacimientos nacimiento;
        cin >> nacimiento.nacimientos;
        nacimiento.anyo = anyo1 + i;
        v.push_back(nacimiento);
    }

    cin >> e;
    
    for(int i = 0; i < e; i++){

        cin >> anyo1;
        cin >> anyo2;
        cout << resolver(v, anyo1, anyo2) << "\n";

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

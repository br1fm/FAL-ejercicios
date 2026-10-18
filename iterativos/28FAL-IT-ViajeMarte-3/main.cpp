// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct tStruct {
    string nombre;
    int altura;
};

bool operator<(tStruct d1, tStruct d2) {
    return (d1.nombre < d2.nombre) ||
           (d1.nombre == d2.nombre && d1.altura < d2.altura);
}

// función que resuelve el problema
int resolver(vector<tStruct> & datos, int altura) {
    int p = 0, q = datos.size() - 1;
    while(p <= q){
        if(datos[p].altura <= altura) p++;
        else if(datos[q].altura > altura) q--;
        else{
            swap(datos[p], datos[q]);
            p++;
            q--;
        }
    }
    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, altura;
    cin >> n;
    if (! std::cin)
        return false;

    cin >> altura;
    vector<tStruct> datos(n);

    for(int i = 0; i < n; i++){
        cin >> datos[i].nombre >> datos[i].altura;
    }
    
    int p = resolver(datos, altura);
    
    sort(datos.begin(), datos.begin() + p);
    cout << "Bajos: ";

    for(int i = 0; i < p; i++){
        cout << datos[i].nombre << " ";
    }
    
    sort(datos.begin() + p, datos.end());
    cout << "\nAltos: ";

    for(int i = p; i < datos.size(); i++){
        cout << datos[i].nombre << " ";
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
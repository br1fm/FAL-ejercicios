// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
bool resolver(const vector<int> & datos, int p) {
    
    int ult_valor = datos[0], cota_baja = datos[0], i = 0;
    bool apto = true;
    while(i < int(datos.size()) && apto){
        if(ult_valor >= datos[i]){
            if((ult_valor - cota_baja) > p)
                apto = false;
            cota_baja = datos[i];
        }
        ult_valor = datos[i];
        i++;
    }

    if ((ult_valor - cota_baja) > p)
        apto = false;

    return apto;
}
    

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int n, p, elem;

    cin >> p;

    if (!cin)
        return false;
    else
    {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        // Procesa un único caso.
        // Evita el uso de endl.
        cin >> n;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            cin >> elem;
            v.push_back(elem);
        }

        bool sol = resolver(v,p);

        sol ? cout << "APTA\n" : cout << "NO APTA\n";

    }

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

// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

using TipoDatos = unsigned long long;
using TipoSolucion = bool;

// Calcula recursivamente la suma de los dígitos
int sumaDigitos(TipoDatos n) {
    if (n == 0)
        return 0;

    return n % 10 + sumaDigitos(n / 10);
}

// Comprueba recursivamente si el número es interesante
bool interesante(TipoDatos n, int sumaIzq, int sumaDer) {

    // Caso base: hemos comprobado todos los dígitos
    if (n == 0)
        return true;

    // Obtenemos el último dígito
    int digito = n % 10;

    // Quitamos el dígito de la suma izquierda
    sumaIzq -= digito;

    // Comprobamos las condiciones
    if (digito == 0 ||
        sumaIzq % digito != 0 ||
        sumaDer % digito != 0) {
        return false;
    }

    // Llamada recursiva con el resto del número
    return interesante(n / 10, sumaIzq, sumaDer + digito);
}

// Función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {

    if (datos == 0)
        return false;

    int sumaTotal = sumaDigitos(datos);

    return interesante(datos, sumaTotal, 0);
}

// Resuelve un caso de prueba
void resuelveCaso() {

    TipoDatos datos;
    cin >> datos;

    TipoSolucion sol = resolver(datos);

    if (sol)
        cout << "SI\n";
    else
        cout << "NO\n";
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // Para restablecer entrada
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
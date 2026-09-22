// Esquema de la entrada: fin de la entrada
#include <iostream>
#include <vector>
using namespace std;


/*

    Todos los elementos del vector se recorren una única vez, tanto en el mejor como en el peor
    de los casos, por lo que tendrá una complejidad de O(n).

*/
bool resolver(const vector<int> & datos, int p){
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

bool casoDePrueba()
{

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

        return true;
    }

} // casoDePrueba

int main()
{

    while (casoDePrueba())
        ;

    return 0;

} // main

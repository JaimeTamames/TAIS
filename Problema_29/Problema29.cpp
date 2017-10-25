// Grupo TAIS36, Ruben y Jaime
// Ejercicio 29
// Almacenamos las posibles puntuaciones en un array, despues usamos el algoritmo explicado en las diapositivas con el ejercicio del cambio, el
// cual muestra el numero de disparos necesarios, despues hacemos uso del otro algoritmo del mismo ejercicio para mostrar exactamente que disparos
// nos dan la puntuacion indicada. Si no se puede llegar a la puntuacion indicada el resultado sera inalcanzable.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void puntuacion_disparos(vector<int> const& vPuntuacionSector, int puntuacion, vector<int> const& vDisparos) {
    
    size_t n = vPuntuacionSector.size() - 1;
    vector<int> vCuantas(n + 1, 0);
    
    size_t i = n;
    int j = puntuacion;
    
    while(j > 0){ //No se ha llegado a la puntuacion
        if (vPuntuacionSector[i] <= j && vDisparos[j] == vDisparos[j - vPuntuacionSector[i]] + 1) {
            
            // Disparamos al sector i
            vCuantas[i]++;
            
            j = j - vPuntuacionSector[i];
            
        } else // No disparamos mas a ese sector
            i--;
    }
    
    // Imprime los disparos necesarios para alcanzar la puntuacion
    for(size_t f = vCuantas.size() - 1; f > 0; f--){
    
        if(vCuantas[f - 1] != 0){
        
            int aux = vCuantas[f - 1];
            
            for(int g = 0; g < aux; g++)
                cout << vPuntuacionSector[f - 1] << " ";
        }
    }
}

// O(nC)
void resuelve(vector<int> const& vPuntuacionSector, int puntuacion){

    size_t n = vPuntuacionSector.size() - 1;
    vector<int> vDisparos(puntuacion + 1, 999999999);
    vDisparos[0] = 0;
    
    // Rellenar la matriz
    for (size_t i = 1; i <= n; ++i) {
        for (int j = vPuntuacionSector[i - 1]; j <= puntuacion; ++j) {
            
            vDisparos[j] = min(vDisparos[j], vDisparos[j - vPuntuacionSector[i - 1]] + 1);
        }
    }
    
    // Imprime el numero de disparos necesarios para alcanzar la puntuacion si fuera posible, si no imprime Imposible
    if(vDisparos[puntuacion] != 999999999){
    
        cout << vDisparos[puntuacion] << ": ";
        
        puntuacion_disparos(vPuntuacionSector, puntuacion, vDisparos);
        
    }
    else{
    
        cout << "Imposible";
    }
}

//
bool resuelveCaso() {
    
    int puntuacion, nSectores;
    
    cin >> puntuacion;
    cin >> nSectores;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<int> vPuntuacionSector(nSectores + 1);
        
        for(int i = 0; i < nSectores; i++){
        
            cin >> vPuntuacionSector[i];
        }
        
        resuelve(vPuntuacionSector, puntuacion);
        
        cout << "\n";
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
        
    while (resuelveCaso());
    
    return 0;
}

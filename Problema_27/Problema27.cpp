// Grupo TAIS36, Jaime
// Ejercicio 27

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "Matriz.h"
#define MAX_LONG  10001

using namespace std;

bool sepude(vector<int> vLongitud, vector<int> vCoste, int nVarillas, int lVarilla) {
    
    Matriz<bool> varillas(nVarillas + 1, lVarilla + 1, false);
    
    varillas[0][0] = true;
    for (int i = 1; i <= nVarillas; i++)
    {
        varillas[i][0] = true;
        for (int j = 1; j <= lVarilla; j++)
        {
            if (vLongitud[i] > j)
                varillas[i][j] = varillas[i - 1][j];
            else if (vLongitud[i] == j)
                varillas[i][j] = true;
            else {
                varillas[i][j] = varillas[i - 1][j] || varillas[i - 1][j-vLongitud[i]];
            }
        }
        
    }
    
    return varillas[nVarillas][lVarilla];
    
}

int numManeras(int nVarillas,int lVarilla, vector<int> vLongitud){
    
    Matriz <int> varillas(nVarillas + 1,lVarilla + 1, 0);
    
    for (int i = 1; i <= nVarillas; i++)
    {
        for (int j = 1; j <= lVarilla; j++)
        {
            if (vLongitud[i] > j) varillas[i][j] = varillas[i - 1][j];
            else if (vLongitud[i] == j) varillas[i][j] = varillas[i - 1][j] + 1;
            else varillas[i][j] = varillas[i-1][j] + varillas[i - 1][j - vLongitud[i]];
            
        }
        
    }
    
    
    return varillas[nVarillas][lVarilla];
}

int numMinimo(int nVarillas, int lVarilla, vector<int>vLongitud) {
    
    Matriz<int> varillas(nVarillas + 1,lVarilla + 1, MAX_LONG);
    
    varillas[0][0] = 0;
    for (int i = 1; i <= nVarillas; i++)
    {
        varillas[i][0]=0;
        for (int j = 1; j <= lVarilla; j++)
        {
            if (vLongitud[i] > j) varillas[i][j] = varillas[i - 1][j];
            else if (vLongitud[i] == j) varillas[i][j] = 1;
            else
                varillas[i][j] = min(varillas[i -1 ][j], varillas[i - 1][j - vLongitud[i]] + 1);
            
        }
        
    }
    
    return varillas[nVarillas][lVarilla];
}

int minCoste(int nVarillas, int lVarilla, vector<int> vLongitud, vector<int> vCoste) {
    
    Matriz<int> varillas(nVarillas + 1, lVarilla + 1, MAX_LONG);
    varillas[0][0] = 0;
    
    for (int i = 1; i <= nVarillas; i++)
    {
        varillas[i][0] = 0;
        for (int j = 1; j <= lVarilla; j++)
        {
            
            if (vLongitud[i] > j) {
                varillas[i][j] = varillas[i - 1][j];
                
            }
            else
                varillas[i][j] = min(varillas [i - 1][j], varillas[i - 1][j - vLongitud[i]] + vCoste[i]);
        
        }
        
    }
    
    return varillas[nVarillas][lVarilla];
}

void resuelve(int nVarillas, int lVarilla, vector<int> vLongitud, vector<int> vCoste){

    if (nVarillas == 0 || lVarilla == 0){
    
        cout<< "NO" << endl;
    }
    else if (sepude(vLongitud, vCoste, nVarillas, lVarilla)) {
        
        int numMane = numManeras(nVarillas, lVarilla, vLongitud);
        int numMin = numMinimo(nVarillas, lVarilla, vLongitud);
        int minC = minCoste(nVarillas, lVarilla, vLongitud, vCoste);
        
        cout << "SI" << " " << numMane << " " << numMin << " " << minC << endl;
    }
    else
        cout << "NO" << endl;
}

//
bool resuelveCaso() {
    
    int nVarillas, lVarilla;
    
    cin >> nVarillas;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        cin >> lVarilla;
        
        vector<int> vLongitud(lVarilla + 1);
        vector<int> vCoste(lVarilla + 1);
        
        for(int i = 1; i <= nVarillas; i++){
            
            cin >> vLongitud[i];
            cin >> vCoste[i];
        }
        
        resuelve(nVarillas, lVarilla, vLongitud, vCoste);
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    while (resuelveCaso());
    
    return 0;
}

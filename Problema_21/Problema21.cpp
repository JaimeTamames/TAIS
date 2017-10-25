// Grupo TAIS36, Jaime
// Problema 21

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

//Resuelve cada caso de prueba

int resuelve(vector<int> const &listaEsquis, vector<int> const &listaEsquiadores) {
    
    int sol = 0;
    
    for(int i = 0; i < listaEsquis.size(); i++){
    
       sol = sol + abs(listaEsquis[i] - listaEsquiadores[i]);
    }
    
    return sol;
}

bool resuelveCaso(){

    int numEsqu;
    
    cin >> numEsqu;
    
    //Fin de entrada de casos
    if(numEsqu == 0){
        
        return false;
    }
    //Para el resto de casos
    else{
    
        vector<int> listaEsquis = vector<int>(numEsqu);
        vector<int> listaEsquiadores = vector<int>(numEsqu);
        
        for(int i = 0; i < numEsqu; i++){
            
            cin >> listaEsquiadores[i];
        }
        
        for(int i = 0; i < numEsqu; i++){
            
            cin >> listaEsquis[i];
        }
        
        sort(listaEsquiadores.begin(), listaEsquiadores.end(), less<int>());
        sort(listaEsquis.begin(), listaEsquis.end(), less<int>());
        
        cout << resuelve(listaEsquis, listaEsquiadores)  << '\n';
        
        return true;
    }
        
}

int main() {
    
    while (resuelveCaso());
    
    return 0;
}

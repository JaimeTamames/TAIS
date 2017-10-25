// Grupo TAIS36, Jaime
// Problema 23

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

//Resuelve cada caso de prueba

int resuelve(vector<int> const &listaPilas, int voltaje) {
    
    int sol = 0, i = 0;
    size_t ultimo = listaPilas.size() - 1;
    bool ok = true;

    do{
        
        if (i <= ultimo && i != ultimo){
        
            if((listaPilas[i] + listaPilas[ultimo]) >= voltaje){
                
                sol++;
                ultimo--;
            }

            i++;
        }
        else{
        
            ok = false;
        }
        
    }while(ok);
    
    return sol;
}

void resuelveCaso(){
    
    int numPilas, voltaje;
    
    cin >> numPilas;
    cin >> voltaje;
    
    vector<int> listaPilas = vector<int>(numPilas);
    
    for(int i = 0; i < numPilas; i++){
        
        cin >> listaPilas[i];
    }

    sort(listaPilas.begin(), listaPilas.end(), less<int>());

    cout << resuelve(listaPilas, voltaje)  << '\n';
    
}

int main() {
    
    int nCasos;
    
    cin >> nCasos;
    
    for(int i = 0; i < nCasos; i++){
        
        resuelveCaso();
        
    }
    
    return 0;
}

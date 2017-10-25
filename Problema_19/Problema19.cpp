// Grupo TAIS36, Jaime
// Ejercicio 19

#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;


int resuelve(vector<int> const &lista, int lParche){

    int sol = 0;
    
    for(size_t i = 0; i < lista.size(); i++){
        
        bool ok = true;
        
        int cubre = lParche + lista[i];
        
        size_t j = i + 1;
        
        do{
            
            if(cubre >= lista[j] && j < lista.size()){
            
                j++;
            }
            else{
            
                i = j - 1;
                sol++;
                ok = false;
            }
        
        }while(ok);
    }
    
    return sol;
}


bool resuelveCaso() {
    
    int nAgujeros;
    int lParche;
    
    cin >> nAgujeros;
    cin >> lParche;
    
    //Fin de entrada de casos
    if (!cin){
        return false;
    }
    //Para los demas casos...
    else{
        
        vector<int> lista = vector<int>(nAgujeros);
        
        for(int i = 0; i < nAgujeros; i++){
            
            cin >> lista[i];
            
        }
        
        sort(lista.begin(), lista.end(), less<int>());
        
        cout << resuelve(lista, lParche) << '\n';
        
        return true;
    }
}

int main(int argc, const char * argv[]) {
    
    while (resuelveCaso());
    
    return 0;
}

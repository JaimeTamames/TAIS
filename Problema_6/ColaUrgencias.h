//
//  ColaUrgencias.h
//  TAIS_6
//
//  Created by Jaime Tamames on 25/8/17.
//  Copyright © 2016 Jaime Tamames. All rights reserved.
//

#ifndef ColaUrgencias_h
#define ColaUrgencias_h

#include "PriorityQueue.h"

using namespace std;

struct Tpar{
    
    string nombre;
    int gravedad;
    int llegada;
    
};

class ColaUrgencias{
    
    
public:
    
    bool operator()(Tpar t, Tpar s) const {
        
        if(t.gravedad == s.gravedad){
            
            return (t.llegada < s.llegada);
        }
        else{
            return (t.gravedad > s.gravedad);
        }
    }
    
    
private:
    
    
};

#endif /* ColaUrgencias_h */

// Grupo TAIS36, Ruben y Jaime
// Todas las personas serán representadas como vértices de un Grafo, los grupos de amigos serán relacionados entre sí
// a través de aristas entre los vértices, de manera que con un recorrido recursivo de los vértices adyacentes podremos contar
// el numero máximo de amigos.


#include <algorithm>
#include <iostream>
#include "Grafo.h"


class comprobarlibertad
{

	std::vector<bool> _marked;
	const Grafo _G;
	bool libre = true;
	int numelems = 0;

	void dfs(const Grafo &_G, int v, int i)
	{
		_marked[v] = true;

		for (int w : _G.adj(v))
			if (!_marked[w]){
				dfs(_G, w, v);
				
		}
	}

	void esConexo(std::vector<bool> mark){

		int i = 0;

		for (i; i < mark.size(); i++){

			if (!mark[i]) libre = false;

		}

	}

public:

	comprobarlibertad(const Grafo &g) : _G{ g }, _marked(g.V(), false) {
				
			dfs(_G, 0, 0);	
			esConexo(_marked);
	}

	bool getlibertad() {

		return libre;

	}
};


//Resuelve un caso de prueba

//O(V+E) V - numero de personas y E - las relaciones entre ellas
bool resuelveCaso() {

	size_t v = -1;
	int pares = -1;
	int num1 = -1;
	int num2 = -1;
	int i = 0;

	std::cin >> v;

	if (!std::cin) return false;

	std::cin >> pares;

	Grafo g = Grafo(v);

	while (i < pares){

		std::cin >> num1;
		std::cin >> num2;

		g.ponArista(num1, num2);

		i++;
	}

	if (pares >= v) std::cout << "NO" << std::endl;
	else
	{
		comprobarlibertad ca = comprobarlibertad(g);
		if (ca.getlibertad())
			std::cout << "SI" << std::endl;
		else
			std::cout << "NO" << std::endl;

	}

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}

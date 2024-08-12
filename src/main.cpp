#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "../include/dijkstraList.h"
#include "../include/starList.h"
#include "../include/dijkstraMatrix.h"
#include "../include/starMatrix.h"
#include "../include/graphList.h"
#include "../include/graphMatrix.h"

int isPossible(double distancia, double energia)
{
  if (distancia <= energia)
    return 1;
  return 0;
}

void buildGraph(GraphList *g, int clareiras, int trilhas, int portais)
{
  for (int i = 0; i < clareiras; i++)
  {
    double x, y;
    cin >> x >> y;

    g->addVertex(i, x, y);
  }
  for (int i = 0; i < trilhas; i++)
  {
    int u, v;
    cin >> u >> v;

    g->addEdge(u, v);
  }
  for (int i = 0; i < portais; i++)
  {
    int u, v;
    cin >> u >> v;

    g->addEdge(u, v, 1);
  }
}

int main()
{
  // entrada
  int clareiras, trilhas, portais, maxPortais, objetivo;
  double energia;
  cin >> clareiras >> trilhas >> portais;

  GraphList g = GraphList(clareiras);
  buildGraph(&g, clareiras, trilhas, portais);

  cin >> energia >> maxPortais;
  objetivo = clareiras - 1;

  // executa algoritmos
  DijkstraList dk = DijkstraList(&g, clareiras, trilhas + portais, maxPortais);
  StarList st = StarList(&g, clareiras, trilhas + portais, maxPortais);
  double distanciaDk = dk.run(objetivo);
  double distanciaSt = st.run(objetivo);

  // retorna se é possível para cada algoritmo
  cout << isPossible(distanciaDk, energia) << ' ' << isPossible(distanciaSt, energia) << endl;
}
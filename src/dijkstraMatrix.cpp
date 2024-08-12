#include <cmath>
using std::fabs;

#include <stdexcept>

#include "../include/dijkstraMatrix.h"
#include "../include/minHeap.h"

const int INF = 0x3f3f3f3f;

DijkstraMatrix::DijkstraMatrix(GraphMatrix *g, int numberOfVertices, int numberOfEdges, int maxPortais) : g(g), numberOfVertices(numberOfVertices), numberOfEdges(numberOfEdges), maxPortais(maxPortais)
{
  if (g == nullptr || numberOfVertices <= 0 || numberOfEdges < 0 || maxPortais < 0)
  {
    throw std::invalid_argument("Entrada inválida.");
  }
  try
  {
    dist = new double[numberOfVertices];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::runtime_error("Falha na alocação de memória.");
  }
  for (int i = 0; i < numberOfVertices; i++)
    dist[i] = INF;
}

DijkstraMatrix::~DijkstraMatrix()
{
  delete[] dist;
}

double DijkstraMatrix::run(int target)
{
  if (target < 0 || target >= numberOfVertices)
  {
    throw std::invalid_argument("Entrada inválida.");
  }
  MinHeap priority_list = MinHeap(numberOfVertices + numberOfEdges);
  priority_list.insert({0, 0, 0, 0});
  // enquanto o heap não estiver vazio, pega a tripla {distância, vértice, portais} do heap (contém alguma distância possível de se chegar ao vértice partindo do início, usando uma quantidade de portais) e compara com a menor distância gravada que vai do início ao vértice. Se a distância nova for menor que a distância gravada, armazena a nova distância.
  while (!priority_list.isEmpty())
  {
    Tuple vertex = priority_list.remove();
    int v = -vertex.v;
    double d = -vertex.d;
    int p = vertex.p;

    if (v == target)
      return d;

    if (d >= dist[v])
      continue;

    dist[v] = d;
    VertexMatrix *neighbour = g->getNeighbours(v);
    for (int j = 0; j < numberOfVertices; j++)
    {
      if (neighbour[j].isNeighbour == 0)
        continue;
      // se a distância até o vizinho for igual a zero, verifica se a quantidade de portais do caminho atual é menor que a quantidade total de portais permitida. Se for, utiliza um portal e atualiza a quantidade de portais utilizada até o vizinho (pNeighbour++). Se não for, não utiliza esse caminho (analisa o proximo vizinho).
      int pNeighbour = p;
      if (fabs(neighbour[j].weight - 0) < 1e-9)
      {
        if (p < maxPortais)
        {
          pNeighbour++;
        }
        else
        {
          continue;
        }
      }
      // para cada vizinho, se a distância do início até o vértice atual (d) mais a distância do vertice atual até o vizinho (neighbour->weight) for menor que a distância do início até o vizinho armazenada, então o caminho passando pelo vértice atual é o menor (adiciona no heap).
      double w = d + neighbour[j].weight;
      if (dist[neighbour[j].vertex] > w)
      {
        priority_list.insert({-w, -neighbour[j].vertex, pNeighbour, 0});
      }
    }
  }
  return INF;
}
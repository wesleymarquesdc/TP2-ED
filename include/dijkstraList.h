#ifndef DIJSTRALIST_H
#define DIJSTRALIST_H

#include "graphList.h"

/**
 * @class DijkstraList
 * @brief Implementa o algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo representado por uma lista de adjacência.
 */
class DijkstraList
{
private:
  GraphList *g;         ///< Grafo com vértices e arestas representado por uma lista de adjacência.
  int numberOfVertices; ///< Número de vértices no grafo.
  int numberOfEdges;    ///< Número de arestas no grafo.
  int maxPortais;       ///< Número máximo de portais que Linque pode usar.
  double *dist;         ///< Array para armazenar as distâncias mínimas de cada vértice a partir da fonte.

public:
  /**
   * @brief Construtor da classe DijkstraList.
   * @param g Grafo representado por uma lista de adjacência.
   * @param numberOfVertices Número de vértices no grafo.
   * @param numberOfEdges Número de arestas no grafo.
   * @param maxPortais Número máximo de portais que podem ser usados.
   */
  DijkstraList(GraphList *g, int numberOfVertices, int numberOfEdges, int maxPortais);

  /**
   * @brief Destrutor da classe DijkstraList.
   * Libera a memória alocada para o array de distâncias.
   */
  ~DijkstraList();

  /**
   * @brief Executa o algoritmo de Dijkstra para encontrar o caminho mais curto até o alvo.
   * @param target O vértice de destino para o qual o caminho mais curto será calculado.
   * @return A distância mínima do vértice fonte ao vértice alvo.
   */
  double run(int target);
};

#endif
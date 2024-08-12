#ifndef STARLIST_H
#define STARLIST_H

#include "graphList.h"

/**
 * @class StarList
 * @brief Implementa o algoritmo A* para encontrar o caminho mais curto em um grafo representado por listas de adjacência.
 */
class StarList
{
private:
  GraphList *g;         ///< Ponteiro para o grafo representado por listas de adjacência.
  int numberOfVertices; ///< Número de vértices no grafo.
  int numberOfEdges;    ///< Número de arestas no grafo.
  int maxPortais;       ///< Número máximo de portais que podem ser usados.
  double *dist;         ///< Array que armazena as distâncias calculadas para cada vértice.

public:
  /**
   * @brief Construtor da classe StarList.
   * @param g Ponteiro para o grafo representado por listas de adjacência.
   * @param numberOfVertices Número de vértices no grafo.
   * @param numberOfEdges Número de arestas no grafo.
   * @param maxPortais Número máximo de portais que podem ser usados.
   */
  StarList(GraphList *g, int numberOfVertices, int numberOfEdges, int maxPortais);

  /**
   * @brief Destrutor da classe StarList.
   * Libera a memória alocada para o array de distâncias.
   */
  ~StarList();

  /**
   * @brief Executa o algoritmo A* para encontrar o caminho mais curto até o vértice alvo.
   * @param target Índice do vértice alvo.
   * @return Distância do caminho mais curto até o vértice alvo.
   */
  double run(int target);
};

#endif
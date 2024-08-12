#ifndef STARMATRIX_H
#define STARMATRIX_H

#include "graphMatrix.h"

/**
 * @class StarMatrix
 * @brief Implementa o algoritmo A* para encontrar o caminho mais curto em um grafo representado por uma matriz de adjacência.
 */
class StarMatrix
{
private:
  GraphMatrix *g;       ///< Ponteiro para o grafo representado por uma matriz de adjacência.
  int numberOfVertices; ///< Número de vértices no grafo.
  int numberOfEdges;    ///< Número de arestas no grafo.
  int maxPortais;       ///< Número máximo de portais que podem ser usados.
  double *dist;         ///< Array que armazena as distâncias calculadas para cada vértice.

public:
  /**
   * @brief Construtor da classe StarMatrix.
   * @param g Ponteiro para o grafo representado por uma matriz de adjacência.
   * @param numberOfVertices Número de vértices no grafo.
   * @param numberOfEdges Número de arestas no grafo.
   * @param maxPortais Número máximo de portais que podem ser usados.
   */
  StarMatrix(GraphMatrix *g, int numberOfVertices, int numberOfEdges, int maxPortais);

  /**
   * @brief Destrutor da classe StarMatrix.
   * Libera a memória alocada para o array de distâncias.
   */
  ~StarMatrix();

  /**
   * @brief Executa o algoritmo A* para encontrar o caminho mais curto até o vértice alvo.
   * @param target Índice do vértice alvo.
   * @return Distância do caminho mais curto até o vértice alvo.
   */
  double run(int target);
};

#endif
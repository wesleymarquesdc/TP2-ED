#ifndef DIJSTRAMATRIX_H
#define DIJSTRAMATRIX_H

#include "graphMatrix.h"

/**
 * @class DijkstraMatrix
 * @brief Implementa o algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo representado por uma matriz de adjacência.
 */
class DijkstraMatrix
{
private:
  GraphMatrix *g;       ///< Grafo com vértices e arestas representado por uma matriz de adjacência.
  int numberOfVertices; ///< Número de vértices no grafo.
  int numberOfEdges;    ///< Número de arestas no grafo.
  int maxPortais;       ///< Número máximo de portais que Linque pode usar.
  double *dist;         ///< Array para armazenar as distâncias mínimas de cada vértice a partir da fonte.

public:
  /**
   * @brief Construtor da classe DijkstraMatrix.
   * @param g Grafo representado por uma matriz de adjacência.
   * @param numberOfVertices Número de vértices no grafo.
   * @param numberOfEdges Número de arestas no grafo.
   * @param maxPortais Número máximo de portais que podem ser usados.
   */
  DijkstraMatrix(GraphMatrix *g, int numberOfVertices, int numberOfEdges, int maxPortais);

  /**
   * @brief Destrutor da classe DijkstraMatrix.
   * Libera a memória alocada para o array de distâncias.
   */
  ~DijkstraMatrix();

  /**
   * @brief Executa o algoritmo de Dijkstra para encontrar o caminho mais curto até o alvo.
   * @param target O vértice de destino para o qual o caminho mais curto será calculado.
   * @return A distância mínima do vértice fonte ao vértice alvo.
   */
  double run(int target);
};

#endif
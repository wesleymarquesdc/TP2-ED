#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <cmath>
using std::pow;
using std::sqrt;

#include "graph.h"

/**
 * @struct VertexMatrix
 * @brief Estrutura que representa um vértice em uma matriz de adjacência.
 */
struct VertexMatrix
{
  int vertex;       ///< Índice do vértice.
  double x;         ///< Coordenada x do vértice.
  double y;         ///< Coordenada y do vértice.
  double weight;    ///< Peso associado ao vértice.
  bool isNeighbour; ///< Indica se o vértice é um vizinho.

  /**
   * @brief Calcula a distância euclidiana entre o vértice atual e outro vértice.
   * @param v O outro vértice.
   * @return A distância euclidiana entre os vértices.
   */
  double dist(VertexMatrix v)
  {
    return sqrt(pow(x - v.x, 2) + std::pow(y - v.y, 2));
  }
};

/**
 * @class GraphMatrix
 * @brief Implementa um grafo usando uma matriz de adjacência.
 */
class GraphMatrix : public Graph
{
private:
  VertexMatrix **matrix; ///< Matriz de adjacência que armazena as informações dos vértices e arestas.

public:
  /**
   * @brief Construtor da classe GraphMatrix.
   * @param numberOfVertices Número de vértices no grafo.
   */
  GraphMatrix(int numberOfVertices);

  /**
   * @brief Destrutor da classe GraphMatrix.
   * Libera a memória alocada para a matriz de adjacência.
   */
  ~GraphMatrix() override;

  /**
   * @brief Adiciona um vértice ao grafo.
   * @param i Índice do vértice.
   * @param x Coordenada x do vértice.
   * @param y Coordenada y do vértice.
   */
  void addVertex(int i, double x, double y) override;

  /**
   * @brief Adiciona uma aresta ao grafo.
   * @param i Índice do vértice de origem.
   * @param j Índice do vértice de destino.
   * @param isPortal Indica se a aresta é um portal (valor padrão é 0).
   */
  void addEdge(int i, int j, bool isPortal = 0) override;

  /**
   * @brief Obtém um vértice pelo seu índice.
   * @param i Índice do vértice.
   * @return O vértice correspondente ao índice.
   */
  VertexMatrix getVertex(int i);

  /**
   * @brief Obtém os vizinhos de um vértice.
   * @param i Índice do vértice.
   * @return Ponteiro para o array de vértices vizinhos.
   */
  VertexMatrix *getNeighbours(int i);

  /**
   * @brief Obtém o peso da aresta entre dois vértices.
   * @param i Índice do vértice de origem.
   * @param j Índice do vértice de destino.
   * @return O peso da aresta entre os vértices i e j.
   */
  double getWeight(int i, int j) override;

  /**
   * @brief Exibe a representação do grafo.
   */
  void display() override;
};

#endif

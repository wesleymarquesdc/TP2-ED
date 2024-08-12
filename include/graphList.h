#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <cmath>
using std::pow;
using std::sqrt;

#include "graph.h"

/**
 * @struct VertexList
 * @brief Estrutura que representa um vértice em uma lista de adjacência.
 */
struct VertexList
{
  int vertex;              ///< Índice do vértice.
  double x;                ///< Coordenada x do vértice.
  double y;                ///< Coordenada y do vértice.
  double weight;           ///< Peso do vértice.
  struct VertexList *next; ///< Ponteiro para o próximo vértice na lista de adjacência.

  /**
   * @brief Calcula a distância euclidiana para outro vértice.
   * @param v Vértice para o qual a distância será calculada.
   * @return A distância euclidiana para o vértice v.
   */
  double dist(VertexList v)
  {
    return sqrt(pow(x - v.x, 2) + std::pow(y - v.y, 2));
  }
};

/**
 * @class GraphList
 * @brief Implementa um grafo usando uma lista de adjacência.
 */
class GraphList : public Graph
{
private:
  VertexList *arr; ///< Array de listas de adjacência.

public:
  /**
   * @brief Construtor da classe GraphList.
   * @param numberOfVertices Número de vértices no grafo.
   */
  GraphList(int numberOfVertices);

  /**
   * @brief Destrutor da classe GraphList.
   */
  ~GraphList() override;

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
  VertexList getVertex(int i);

  /**
   * @brief Obtém os vizinhos de um vértice.
   * @param i Índice do vértice.
   * @return Ponteiro para a lista de vértices vizinhos.
   */
  VertexList *getNeighbours(int i);

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
#ifndef GRAPH_H
#define GRAPH_H

/**
 * @class Graph
 * @brief Classe base abstrata para representar um grafo.
 */
class Graph
{
protected:
  int numberOfVertices; ///< Número de vértices no grafo.

public:
  /**
   * @brief Construtor da classe Graph.
   * @param numberOfVertices Número de vértices no grafo.
   */
  Graph(int numberOfVertices) : numberOfVertices(numberOfVertices) {}

  /**
   * @brief Destrutor virtual da classe Graph.
   */
  virtual ~Graph() {}

  /**
   * @brief Adiciona um vértice ao grafo.
   * @param i Índice do vértice.
   * @param x Coordenada x do vértice.
   * @param y Coordenada y do vértice.
   */
  virtual void addVertex(int i, double x, double y) = 0;

  /**
   * @brief Adiciona uma aresta ao grafo.
   * @param i Índice do vértice de origem.
   * @param j Índice do vértice de destino.
   * @param isPortal Indica se a aresta é um portal (valor padrão é 0).
   */
  virtual void addEdge(int i, int j, bool isPortal = 0) = 0;

  /**
   * @brief Obtém o peso da aresta entre dois vértices.
   * @param i Índice do vértice de origem.
   * @param j Índice do vértice de destino.
   * @return O peso da aresta entre os vértices i e j.
   */
  virtual double getWeight(int i, int j) = 0;

  /**
   * @brief Exibe a representação do grafo.
   */
  virtual void display() = 0;
};

#endif
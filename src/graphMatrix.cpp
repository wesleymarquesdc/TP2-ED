#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>

#include "../include/graphMatrix.h"

GraphMatrix::GraphMatrix(int numberOfVertices) : Graph(numberOfVertices)
{
  if (numberOfVertices <= 0)
  {
    throw std::invalid_argument("Entrada inválida.");
  }
  try
  {
    matrix = new VertexMatrix *[numberOfVertices];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::runtime_error("Falha na alocação de memória.");
  }
  for (int i = 0; i < numberOfVertices; ++i)
  {
    try
    {
      matrix[i] = new VertexMatrix[numberOfVertices];
    }
    catch (const std::bad_alloc &e)
    {
      for (int k = 0; k < i; ++k)
      {
        delete[] matrix[k];
      }
      delete[] matrix;
      throw std::runtime_error("Falha na alocação de memória.");
    }
    for (int j = 0; j < numberOfVertices; ++j)
    {
      matrix[i][j].isNeighbour = 0;
    }
  }
}

GraphMatrix::~GraphMatrix()
{
  for (int i = 0; i < numberOfVertices; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void GraphMatrix::addVertex(int i, double x, double y)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  matrix[i][i].vertex = i;
  matrix[i][i].x = x;
  matrix[i][i].y = y;
  matrix[i][i].weight = 0;
}

void GraphMatrix::addEdge(int i, int j, bool isPortal)
{
  if (i < 0 || i >= numberOfVertices || j < 0 || j >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  double weight = (isPortal) ? 0 : matrix[i][i].dist(matrix[j][j]);

  VertexMatrix newVertexJ = VertexMatrix{j, matrix[j][j].x, matrix[j][j].y, weight, 1};
  matrix[i][j] = newVertexJ;
}

double GraphMatrix::getWeight(int i, int j)
{
  if (i < 0 || i >= numberOfVertices || j < 0 || j >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  return matrix[i][j].weight;
}

VertexMatrix *GraphMatrix::getNeighbours(int i)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  return matrix[i];
}

VertexMatrix GraphMatrix::getVertex(int i)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  return matrix[i][i];
}

void GraphMatrix::display()
{
  for (int i = 0; i < numberOfVertices; i++)
  {
    cout << "Vertex " << i << ":";
    for (int j = 0; j < numberOfVertices; j++)
    {
      if (matrix[i][j].isNeighbour)
      {
        cout << " -> (" << matrix[i][j].vertex << ", " << matrix[i][j].weight << ")";
      }
    }
    cout << endl;
  }
}
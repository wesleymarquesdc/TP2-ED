#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>

#include "../include/graphList.h"

GraphList::GraphList(int numberOfVertices) : Graph(numberOfVertices)
{
  if (numberOfVertices <= 0)
  {
    throw std::invalid_argument("Entrada inválida.");
  }
  try
  {
    arr = new VertexList[numberOfVertices];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::runtime_error("Falha na alocação de memória.");
  }
}

GraphList::~GraphList()
{
  for (int i = 0; i < numberOfVertices; i++)
  {
    VertexList *temp = arr[i].next, *current;
    while (temp)
    {
      current = temp;
      temp = temp->next;
      delete current;
    }
  }
  delete[] arr;
}

void GraphList::addVertex(int i, double x, double y)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  arr[i].vertex = i;
  arr[i].x = x;
  arr[i].y = y;
  arr[i].weight = 0;
  arr[i].next = nullptr;
}

void GraphList::addEdge(int i, int j, bool isPortal)
{
  if (i < 0 || i >= numberOfVertices || j < 0 || j >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  double weight = (isPortal) ? 0 : arr[i].dist(arr[j]);

  VertexList *newVertexJ = new VertexList{j, arr[j].x, arr[j].y, weight, nullptr};
  if (!arr[i].next)
    arr[i].next = newVertexJ;
  else
  {
    VertexList *current = arr[i].next;
    while (current->next)
      current = current->next;
    current->next = newVertexJ;
  }
}

double GraphList::getWeight(int i, int j)
{
  if (i < 0 || i >= numberOfVertices || j < 0 || j >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  VertexList *current = arr[i].next;
  while (current)
  {
    if (current->vertex == j)
    {
      return current->weight;
    }
    current = current->next;
  }
  return -1;
}

VertexList *GraphList::getNeighbours(int i)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  return arr[i].next;
}

VertexList GraphList::getVertex(int i)
{
  if (i < 0 || i >= numberOfVertices)
  {
    throw std::out_of_range("Entrada inválida.");
  }
  return arr[i];
}

void GraphList::display()
{
  for (int i = 0; i < numberOfVertices; i++)
  {
    cout << "Vertex " << i << ":";
    VertexList *temp = arr[i].next;
    while (temp)
    {
      cout << " -> (" << temp->vertex << ", " << temp->weight << ")";
      temp = temp->next;
    }
    cout << endl;
  }
}
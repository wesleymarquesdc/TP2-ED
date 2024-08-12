#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>

#include "../include/minHeap.h"

MinHeap::MinHeap(int maxLength) : length(0), maxLength(maxLength)
{
  if (maxLength <= 0)
  {
    throw std::invalid_argument("Entrada inválida.");
  }
  try
  {
    arr = new Tuple[maxLength];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::runtime_error("Falha na alocação de memória.");
  }
}

MinHeap::~MinHeap()
{
  delete[] arr;
}

int MinHeap::getAncestral(int i)
{
  return ((i - 1) / 2);
}

int MinHeap::getSucessorEsq(int i)
{
  return (2 * i + 1);
}

int MinHeap::getSucessorDir(int i)
{
  return (2 * i + 2);
}

void MinHeap::insert(Tuple element)
{
  if (isFull())
  {
    throw std::runtime_error("MinHeap está cheio!");
  }
  arr[length] = element;
  int i = length;
  length++;
  int p = getAncestral(i);

  while (i > 0 && greater(i, p))
  {
    swap(arr[i], arr[p]);
    i = p;
    p = getAncestral(i);
  }
}

bool MinHeap::greater(int i, int j)
{
  if (i >= length)
    return false;
  if (j >= length)
    return true;
  double distI = arr[i].d + arr[i].h;
  double distJ = arr[j].d + arr[j].h;
  if ((distI > distJ) || (distI == distJ && arr[i].v > arr[j].v))
    return true;
  return false;
}

Tuple MinHeap::remove()
{
  if (isEmpty())
  {
    throw std::runtime_error("MinHeap está vazio!");
  }
  Tuple x = arr[0];
  arr[0] = arr[length - 1];
  length--;
  int i = 0, s;
  int esq = getSucessorEsq(i), dir = getSucessorDir(i);
  s = (esq < length && greater(esq, dir) ? esq : dir);
  while (s < length && greater(s, i))
  {
    swap(arr[s], arr[i]);
    i = s;
    esq = getSucessorEsq(i);
    dir = getSucessorDir(i);
    s = (esq < length && greater(esq, dir) ? esq : dir);
  }
  return x;
}

void MinHeap::display()
{
  for (int i = 0; i < length; i++)
  {
    cout << '(' << arr[i].d << ',' << arr[i].v << ')' << endl;
  }
}

bool MinHeap::isEmpty()
{
  return length == 0;
}

bool MinHeap::isFull()
{
  return (length >= maxLength);
}

void MinHeap::swap(Tuple &i, Tuple &j)
{
  Tuple temp = i;
  i = j;
  j = temp;
}
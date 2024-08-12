#ifndef HEAP_H
#define HEAP_H

/**
 * @struct Tuple
 * @brief Estrutura que representa um elemento armazenado no heap.
 */
struct Tuple
{
  double d; ///< Distância para se chegar ao vértice.
  int v;    ///< Índice do vértice.
  int p;    ///< Quantidade de portais utilizada para se chegar ao vértice.
  double h; ///< Distância heurística para o último vértice (usada no algoritmo A*).
};

/**
 * @class MinHeap
 * @brief Implementa uma estrutura de dados heap para gerenciamento de elementos.
 */
class MinHeap
{
private:
  int length;    ///< Número atual de elementos no heap.
  int maxLength; ///< Capacidade máxima do heap.

public:
  Tuple *arr; ///< Array que armazena os elementos do heap.

  /**
   * @brief Construtor da classe Heap.
   * @param maxLength Capacidade máxima do heap.
   */
  MinHeap(int maxLength);

  /**
   * @brief Destrutor da classe Heap.
   * Libera a memória alocada para o array de elementos.
   */
  ~MinHeap();

  /**
   * @brief Obtém o índice do ancestral de um elemento.
   * @param i Índice do elemento.
   * @return Índice do ancestral do elemento.
   */
  int getAncestral(int i);

  /**
   * @brief Obtém o índice do sucessor esquerdo de um elemento.
   * @param i Índice do elemento.
   * @return Índice do sucessor esquerdo do elemento.
   */
  int getSucessorEsq(int i);

  /**
   * @brief Obtém o índice do sucessor direito de um elemento.
   * @param i Índice do elemento.
   * @return Índice do sucessor direito do elemento.
   */
  int getSucessorDir(int i);

  /**
   * @brief Insere um novo elemento no heap.
   * @param element Elemento a ser inserido.
   */
  void insert(Tuple element);

  /**
   * @brief Remove e retorna o elemento com a maior prioridade do heap.
   * @return O elemento com a maior prioridade.
   */
  Tuple remove();

  /**
   * @brief Verifica se o heap está vazio.
   * @return Verdadeiro se o heap estiver vazio, falso caso contrário.
   */
  bool isEmpty();

  /**
   * @brief Verifica se o heap está cheio.
   * @return Verdadeiro se o heap estiver cheio, falso caso contrário.
   */
  bool isFull();

  /**
   * @brief Exibe a representação dos elementos no heap.
   */
  void display();

  /**
   * @brief Compara dois elementos para verificar qual tem maior prioridade.
   * @param i Índice do primeiro elemento.
   * @param j Índice do segundo elemento.
   * @return Verdadeiro se o elemento i for maior que o elemento j, falso caso contrário.
   */
  bool greater(int i, int j);

  /**
   * @brief Troca a posição de dois elementos no heap.
   * @param i Primeiro elemento a ser trocado.
   * @param j Segundo elemento a ser trocado.
   */
  void swap(Tuple &i, Tuple &j);
};

#endif
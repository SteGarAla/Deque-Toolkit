/**
 * @file deque.h
 * @author Steven Garcia-Alamilla
 * @date 2022-11-18
 * @brief deque header file
 *
 * deque class definition
 */

#ifndef DEQUE_H
#define DEQUE_H

// T should have the = operator
template <typename T>
class Deque
{
private:
  T **blockmap;
  const static int BLOCK_SIZE = 8;
  int blockmap_size;
  int deque_size;
  int first_block;
  int first_idx;

  void resize_blockmap();
  int calc_block(int idx);
  int calc_idx(int idx);

public:
  Deque();
  ~Deque();

  void push_front(const T &obj);
  void push_back(const T &obj);
  T pop_front();
  T pop_back();
  bool empty();
  int size();
  T &operator[](int idx);
};

template <typename T>
Deque<T>::Deque()
{
  blockmap_size = 3;
  first_block = 1;
  first_idx = BLOCK_SIZE / 2;
  deque_size = 0;

  blockmap = new T *[blockmap_size];
  for (int i = 0; i < 3; i++)
  {
    blockmap[i] = new T[BLOCK_SIZE];
  }
}

template <typename T>
Deque<T>::~Deque()
{
  for (int i = 0; i < blockmap_size; i++)
  {
    delete[] blockmap[i];
  }
  delete[] blockmap;
}

template <typename T>
void Deque<T>::resize_blockmap()
{
  if (first_block == 0)
  {
    blockmap_size++;
    first_block = 1;
    T **temp = blockmap;
    blockmap = new T *[blockmap_size];
    for (int i = 0; i < blockmap_size - 1; i++)
    {
      blockmap[i + 1] = temp[i];
    }
    blockmap[0] = new T[BLOCK_SIZE];
    delete[] temp;
  }
  if (calc_block(deque_size - 1) == blockmap_size - 1)
  {
    blockmap_size++;
    T **temp = blockmap;
    blockmap = new T *[blockmap_size];
    for (int i = 0; i < blockmap_size - 1; i++)
    {
      blockmap[i] = temp[i];
    }
    blockmap[blockmap_size - 1] = new T[BLOCK_SIZE];
    delete[] temp;
  }
}

template <typename T>
int Deque<T>::calc_block(int idx)
{
  return ((first_idx + idx) / BLOCK_SIZE) + first_block;
}

template <typename T>
int Deque<T>::calc_idx(int idx)
{
  return ((first_idx + idx) % BLOCK_SIZE);
}

template <typename T>
void Deque<T>::push_front(const T &obj)
{
  resize_blockmap();
  first_idx--;
  if (first_idx < 0)
  {
    first_idx = BLOCK_SIZE - 1;
    first_block--;
  }
  (*this)[0] = obj;
  deque_size++;
}

template <typename T>
void Deque<T>::push_back(const T &obj)
{
  resize_blockmap();
  (*this)[deque_size] = obj;
  deque_size++;
}

template <typename T>
T Deque<T>::pop_front()
{
  T copyOfFirst = blockmap[first_block][first_idx];
  deque_size--;
  first_idx++;
  if (first_idx == BLOCK_SIZE)
  {
    first_idx = 0;
    first_block++;
  }
  return copyOfFirst;
}

template <typename T>
T Deque<T>::pop_back()
{
  // Calculate the location of the last element
  int last_block = calc_block(deque_size - 1);
  int last_idx = calc_idx(deque_size - 1);
  deque_size--;
  return blockmap[last_block][last_idx];
}

template <typename T>
bool Deque<T>::empty()
{
  return deque_size == 0;
}

template <typename T>
int Deque<T>::size()
{
  return deque_size;
}

template <typename T>
T &Deque<T>::operator[](int idx)
{
  int block = calc_block(idx);
  int index = calc_idx(idx);
  return blockmap[block][index];
}

#endif // DEQUE_H

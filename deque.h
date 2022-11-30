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


template <typename T>

/**
 * deque implementation
 *
 * @class Deque deque.h "Deque-Toolkit/deque.h"
 * @brief 
 *
 */
class Deque
{
private:
  T **blockmap; // 2d Array mapping to the data in the deque.
  const static int BLOCK_SIZE = 8; // Size of each block in the array. Currently very small for ease of testing.
  int blockmap_size; // The maximum # of blocks the blockmap can currently accommodate.
  int deque_size; // The number of indices currently populated in the deque.
  int first_block; // Index of the block containing the first index of the deque.
  int first_idx; // Index within first_block that contains the first index of the deque.


/**
 * resizing the deque (blockmap)
 * 
 * @pre blockmap needs to increase capacity
 * @return void 
 * @post The deque has been resized 
 * 
 */
  void resize_blockmap();

/**
 * calculates correct block given an index 
 *
 * @param int idx Index whose block is being calculated
 * @pre 
 * @return int Returns the correct block for the index
 * @post 
 * 
 */
  int calc_block(int idx);

/**
 * calculates correct index for the deque
 *
 * @param int idx index whose index is being found for the deque
 * @pre 
 * @return int returns the correct index for the deque
 * @post 
 * 
 */
  int calc_idx(int idx);

public:

/**
 * Constructor
 *
 * @pre Deque object is created
 * @post Deque has been initialized
 * 
 */
  Deque();

/**
 * Deque Destructor
 *
 * @pre Deque object is created
 * @post deque is destroyed
 * 
 */
  ~Deque();


/**
 * Adds element to the front of the deque
 *
 * @param const T &obj The element being added to the front
 * @pre Deque must be created
 * @return void 
 * @post element being passed through is added to the front
 * 
 */
  void push_front(const T &obj);

/**
 * Adds element to the end of the deque
 *
 * @param const T &obj The element being added to the back
 * @pre 
 * @return void 
 * @post element being passed through is added to the back
 * 
 */
  void push_back(const T &obj);

/**
 * Returns the element being removed from the front of the deque
 *
 * @pre Deque must be created
 * @return T element that was removed from the front of the deque
 * @post element is returned after being removed
 * 
 */
  T pop_front();

/**
 * Returns the element being removed from the end of the deque
 *
 * @pre Deque must be created
 * @return T element that was removed from the back of the deque
 * @post element is returned after being removed
 * 
 */
  T pop_back();

/**
 * returns a copy of the element at the front of the deque
 *
 * @pre Deque has been created 
 * @return T copy of the element at the front of the deque
 * @post T copy of the element at the front of the deque
 * 
 */
  T front(); 

/**
 * returns a copy of the element at the front of the deque
 *
 * @pre Deque has been created
 * @return T copy of the element at the end of the deque
 * @post 
 * 
 */
  T back();
  
/**
 * Checks if the deque is empty 
 *
 * @pre Deque must be created
 * @return bool will return true if empty, false otherwise
 * @post 
 * 
 */
  bool empty();

/**
 * method that will return the size of the deque
 *
 * @pre Deque must be created
 * @return int total amount of elements that have been added in the deque
 * @post size of the deque is returned 
 * 
 */
  int size();

/**
 * [] overload to get element at certain index
 *
 * @param int idx index whose deque index is being searched for
 * @pre Deque must be created
 * @return T 
 * @post correct index is returned for the deque
 * 
 */
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
  // Adds a new block in front of the array if it cannot expand anymore in that direction.
  if (first_block == 0 && first_idx == 0)
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

  // Adds a new block behind the array if it cannot expand anymore in that direction.
  if ((calc_block(deque_size - 1) == blockmap_size - 1) && (calc_idx(deque_size - 1) == BLOCK_SIZE - 1))
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
  T &copyOfFirst = (*this)[0];
  if (deque_size == 0)
    return copyOfFirst;
  
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
  if (deque_size == 0)
    return (*this)[0];

  deque_size--;
  return (*this)[deque_size];
}

template <typename T>
T Deque<T>::front()
{ 
  return blockmap[first_block][first_idx];
}

template <typename T>
T Deque<T>::back()
{  
  return (*this)[deque_size - 1];
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

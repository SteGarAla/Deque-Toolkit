#include <iostream>
#include "deque.h"

template <typename T> void print_deque(Deque<T> &d)
{
  for (int i = 0; i < d.size(); i++)
  {
    std::cout << d[i] << std::endl;
  }
}


int main()
{

  Deque<int> d;
  
  for (int i = 0; i < 100; i++)
  {
    d.push_back(i);
    d.push_front(-1 * i);
  }
  
  for (int i = 0; i < 10; i++)
  {
  d.pop_back();
  d.pop_front();
  }
  print_deque(d);
  return 0;
}
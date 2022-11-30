/**
 * @file main.cpp
 * @author Steven Garcia-Alamilla
 * @date 2022-11-18
 * @brief Driver/Testing File
 * 
 * Driver that organizes the operation of the program, and conducts tests
 */


#include <iostream>
#include "deque.h"
using namespace std;

template <typename T>
void testing(Deque<T> &d);

template <typename T>
void print_deque(Deque<T> &d);

int main() {
  
  Deque<char> charTest;
  char startingPoint1 = '!';
	char startingPoint2 = '~';
	for(int i = 0; i < 93; i++){
	  charTest.push_front(startingPoint1++);
	  charTest.push_back(startingPoint2--);
	}
  testing(charTest);


  Deque<int> intTest;
  for(int i = 0; i < 500; i++)
	  {
	    intTest.push_front(i * -1);
	    intTest.push_back(i);    
	  }
  testing(intTest);


  Deque<double> dTest;
  for(int i = 0; i < 500; i++){
	  dTest.push_front(i * -1.111);
	  dTest.push_back(i);
	}
  testing(dTest);  

  return 0;
}

template <typename T>
void print_deque(Deque<T> &d)
{
  for (int i = 0; i < d.size(); i++)
    {
      std::cout << d[i] << std::endl;
    }
}


template <typename T>
void testing(Deque<T> &d){
	cout << "Testing front() & back() \n";
	cout << "Front: " << d.front() << "\n";
	cout << "Back: " << d.back() << "\n";

	cout << "Testing empty() \n";
	if(d.empty()){
	  cout << "deque is empty! \n"; 
	}
	cout << "deque is not empty! \n";

	cout << "Testing size() \n";
	cout << "The size of the deque is " << d.size() << "\n";

	print_deque(d);

  cout << "Testing pop_front() & pop_back() \n";
  while(!d.empty())
  {
    cout << "Removing: " << d.pop_back() << endl;
    cout << "Removing: " << d.pop_front() << endl;
  }
}

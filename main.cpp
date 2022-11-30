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



/**
 * Function that will allow for testing of either a int,char or double deque
 *
 * @return void 
 * @post successful testing for either int,char or double deque
 * 
 */
void menu();

/**
 * displays the options for testing the deque
 *
 * @param  
 * @pre 
 * @return void 
 * @post 
 * 
 */
void displayDequeOptions();

void testingChar(Deque<char> &d);
void testingInt(Deque<int> &d);
void testingDouble(Deque<double> &d);

template <typename T>
void print_deque(Deque<T> &d)
{
  for (int i = 0; i < d.size(); i++)
    {
      std::cout << d[i] << std::endl;
    }
}


int main() {
  
    menu();


  return 0;
}

void menu (){
  
  Deque<char> charTest;
  Deque<int> intTest;
  Deque<double> dTest;
  
  while(true) {
    int choice;
    
    cout << "Enter a choice from the menu \n"
      "1. Deque<int> testing \n"
      "2. Deque<char> testing \n"
      "3. Deque<double> testing \n"
      "4. EXIT \n";
    
    cout << "Enter choice: \n";
    cin >> choice;
    
    switch (choice) {
    case 1:
      {
	cout << "Entering Deque<int> test \n";
	testingInt(intTest);
	break;
      }
    case 2:
      {
	cout << "Entering Deque<char> test \n";
	testingChar(charTest);
	break;
      }
    case 3:
      {
	cout << "Entering Deque<double> test\n";
	testingDouble(dTest);
	break;
      }
    case 4:
      {
	cout << "Exiting program! \n";
	return;
      }
    default:
      {
	cout << "Try Again,this time with a valid option! \n";
      }
    }
    cout << "Press any key to continue! \n ";
    cin.clear();
    cin.ignore(100,'\n');
    getchar();
  }
}
void displayDequeOptions()
{
  cout << "How would you like to test the Deque \n"
    "1. Insert from front & back \n"
    "2. Delete from front & back \n"
    "3. Peek at front & back \n"
    "4. Check if deque is empty \n"
    "5. Check current size of the deque \n"
    "6. operator[] \n"
    "7. Print \n"
    "8. Exit \n";
}

void testingChar(Deque<char> &d){
  
  while(true){
    int choice;
    displayDequeOptions();
    cin >> choice;
    switch (choice) {
    case 1:
      {
	cout << "Testing push_front() & push_back() \n";
	
	char startingPoint1 = '!';
	char startingPoint2 = '~';
	for(int i = 0; i < 93; i++){
	  d.push_front(startingPoint1++);
	  d.push_back(startingPoint2--);
	}
	
	break;
      }
    case 2:
      {
	cout << "Testing pop_front() & pop_back() \n";
	
	for(int i = 0; i < 93; i++){
	  cout << "Removing: " << d.pop_front() << "\n";
	  cout << "Removing: " << d.pop_back() << "\n";
	}
	
	break;
      }
    case 3:
      {
	cout << "Testing front() & back() \n";
	cout << "Front: " << d.front() << "\n";
	cout << "Back: " << d.back() << "\n";
	break;
      }
    case 4:
      {
	cout << "Testing empty() \n";
	if(d.empty()){
	  cout << "deque is empty! \n"; 
	}
	cout << "deque is not empty! \n";
	break;
      }
    case 5:
      {
	cout << "Testing size() \n";
	cout << "The size of the deque is " << d.size() << "\n";
	break;
      }
    case 6:
      {
	cout << "Testing operator[] \n";
	
	int index;
	cout << "Enter index: \n";
	cin >> index;
	
	while(index >= 0 && index < d.size() ){
	  cout << d[index] << "\n";
	  cout << "Enter index: \n";
	  cin >> index;
	}
	break;
      }
    case 7:
      {
	print_deque(d);
	break;
      }
      
    case 8:
      {
	cout << "Exiting! \n";
	return;
      }
    default:
      {
	cout << "Try Again,this time with a valid option! \n";
      }
    }
    cout << "Press any key to continue! \n ";
    cin.clear();
    cin.ignore(100,'\n');
    getchar();
  }
}


void testingInt(Deque<int> &d){
  
  while(true){
    int choice;
    displayDequeOptions();
    cin >> choice;
    switch (choice) {
    case 1:
      {
	cout << "Testing push_front() & push_back() \n";
	
	for(int i = 0; i < 500; i++)
	  {
	    d.push_front(i * -1);
	    d.push_back(i);    
	  }
	
	break;
      }
    case 2:
      {
	cout << "Testing pop_front() & pop_back() \n";
	
	for(int i = 0; i < 500; i++){
	  cout << "Removing: " << d.pop_front() << "\n";
	  cout << "Removing: " << d.pop_back() << "\n";
	}
	
	break;
      }
    case 3:
      {
	cout << "Testing front() & back() \n";
	cout << "Front: " << d.front() << "\n";
	cout << "Back: " << d.back() << "\n";
	break;
      }
    case 4:
      {
	cout << "Testing empty() \n";
	if(d.empty()){
	  cout << "deque is empty! \n"; 
	}
	cout << "deque is not empty! \n";
	break;
      }
    case 5:
      {
	cout << "Testing size() \n";
	cout << "The size of the deque is " << d.size() << "\n";
	break;
      }
    case 6:
      {
	cout << "Testing operator[] \n";
	
	int index;
	cout << "Enter index: \n";
	cin >> index;
	
	while(index >= 0 && index < d.size() ){
	  cout << d[index] << "\n";
	  cout << "Enter index: \n";
	  cin >> index;
	}
	break;
      }
    case 7:
      {
	print_deque(d);
	break;
      }
    case 8:
      {
	cout << "Exiting! \n";
	return;
      }
    default:
      {
	cout << "Try Again,this time with a valid option! \n";
      }
    }
    cout << "Press any key to continue! \n ";
    cin.clear();
    cin.ignore(100,'\n');
    getchar();
  }
}

void testingDouble(Deque<double> &d){
  
  while(true){
    int choice;
    displayDequeOptions();
    cin >> choice;
    switch (choice) {
    case 1:
      {
	cout << "Testing push_front() & push_back() \n";
	
	for(int i = 0; i < 500; i++){
	  d.push_front(i * -1.111);
	  d.push_back(i);
	}
	
	break;
      }
    case 2:
      {
	cout << "Testing pop_front() & pop_back() \n";
	
	for(int i = 0; i < 500; i++){
	  cout << "Removing: " << d.pop_front() << "\n";
	  cout << "Removing: " << d.pop_back() << "\n";
	}
	
	break;
      }
    case 3:
      {
	cout << "Testing front() & back() \n";
	cout << "Front: " << d.front() << "\n";
	cout << "Back: " << d.back() << "\n";
	break;
      }
    case 4:
      {
	cout << "Testing empty() \n";

	if(d.empty()){
	  cout << "deque is empty! \n"; 
	}
	cout << "deque is not empty! \n";
	
	break;
      }
    case 5:
      {
	cout << "Testing size() \n";
	cout << "The size of the deque is " << d.size() << "\n";
	break;
      }
    case 6:
      {
	cout << "Testing operator[] \n";
	
	int index;
	cout << "Enter index: \n";
	cin >> index;
	
	while(index >= 0 && index < d.size() ){
	  cout << d[index] << "\n";
	  cout << "Enter index: \n";
	  cin >> index;
	}
	break;
      }
    case 7:
      {
	print_deque(d);
	break;
      }
    case 8:
      {
	cout << "Exiting! \n";
	return;
      }
      
    default:
      {
	cout << "Try Again,this time with a valid option! \n";
      }
    }
    cout << "Press any key to continue! \n ";
    cin.clear();
    cin.ignore(100,'\n');
    getchar();
  }
}



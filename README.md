# Deque Toolkit
Curt Lynch && Steven Garcia-Alamilla

## Project Description
Building a deque with a Two-Dimensional dynamic array.

## TODO:
1. The deque does not shrink automatically when removing elements. There is also no way to shrink the deque manually.
2. The deque is templated, but requires the templated type to support a few different operators.  
i.e. '<<' insertion for printing to console and '==' / '!=' for comparison / testing.

## Compiling
Compile the tests using make
```sh
$ make
g++ -g -Wall -Wextra -c main.cpp
g++ -g -Wall -Wextra -o deque main.o
```

Run the tests by calling the 'deque' binary directly from the command line.
```sh
$ ./deque
Performing tests on unmodified deques.
Testing front() & back()
Done...
Testing empty()
Done...
...
...
```

## Deque methods
To use deque in other projects be sure to include it in your source files.  
```c++
#include "path_to_deque/deque.h"
```
The Following methods are available to deque's :

```c++
void push_front(T element);
void push_back(T element);
```
Adds an element to the front or back respectively. 

```c++
T pop_front();
T pop_back();
```
Removes an element from the front or back respectively, returning a copy of that element.

```c++
T front();
T back();
```
Returns a copy of the first or last element in the deque respectively. Undefined behavior if the deque is empty.

```c++
bool empty();
```
Returns true if the deque is empty, otherwise returns false.

```c++
unsigned int size();
```
Returns the current number of elements stored in the deque.

```c++
T& operator[](int index);
```
Returns a reference to the element at the given index. **Does not check for memory safety.**
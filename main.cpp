/**
 * @file main.cpp
 * @author Steven Garcia-Alamilla
 * @date 2022-11-18
 * @brief Driver/Testing File
 *
 * Driver that organizes the operation of the program, and conducts tests
 */

#include <iostream>
#include <deque>
#include "deque.h"
using namespace std;

/**
 * runs tests on the supplied deque
 *
 * @param Deque<T> &d the supplied deque
 * @param deque<T> &ref std::deque reference
 * @pre the deques should contain test data
 * @return int the number of errors encountered.
 * @post
 *
 */
template <typename T>
int testing(Deque<T> &d, deque<T> &r);

/**
 * prints the supplied deque to std out.
 *
 * @param Deque<T> &d the supplied deque
 * @pre d should contain data to print
 * @return template
 * @post
 *
 */
template <typename T>
void print_deque(Deque<T> &d);

int main()
{
	int errorCount = 0;

	Deque<char> charTest;
	deque<char> charReference;

	char startingPoint1 = '!';
	char startingPoint2 = '~';
	for (int i = 0; i < 93; i++)
	{
		charTest.push_front(startingPoint1);
		charTest.push_back(startingPoint2);
		charReference.push_front(startingPoint1);
		charReference.push_back(startingPoint2);
		startingPoint1++;
		startingPoint2--;
	}
	errorCount += testing(charTest, charReference);

	Deque<int> intTest;
	deque<int> intReference;

	for (int i = 0; i < 500; i++)
	{
		intTest.push_front(i * -1);
		intTest.push_back(i);
		intReference.push_front(i * -1);
		intReference.push_back(i);
	}
	errorCount += testing(intTest, intReference);

	Deque<double> dTest;
	deque<double> dReference;

	for (int i = 0; i < 500; i++)
	{
		dTest.push_front(i * -1.111);
		dTest.push_back(i);
		dReference.push_front(i * -1.111);
		dReference.push_back(i);
	}
	errorCount += testing(dTest, dReference);

	cout << "\nAll tests completed with " << errorCount << " total error(s).\n";

	return 0;
}

template <typename T>
void print_deque(Deque<T> &d)
{
	for (unsigned int i = 0; i < d.size(); i++)
	{
		std::cout << i << ": " << d[i] << ' ';
	}
	cout << endl;
}

template <typename T>
int testing(Deque<T> &d, deque<T> &r)
{
	int errorCount = 0;
	cout << "Performing tests on unmodified deques.\n";

	cout << "Testing front() & back()\n";
	if (d.front() != r.front())
	{
		cout << "front() fail...\n"
				 << d.front() << " " << r.front() << endl;
		errorCount++;
	}
	if (d.back() != r.back())
	{
		cout << "back() fail\n"
				 << d.back() << " " << r.back() << endl;
		;
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing empty()\n";
	if (d.empty() != r.empty())
	{
		cout << "empty() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing size()\n";
	if (d.size() != r.size())
	{
		cout << "size() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Modifying deques\n";

	for (long unsigned int i = 0; i < d.size() / 2; i++)
	{
		d.push_back(d.front());
		d.pop_front();
		d.pop_front();
		d.push_front(d.back());
		d.push_front(d.back());

		r.push_back(r.front());
		r.pop_front();
		r.pop_front();
		r.push_front(r.back());
		r.push_front(r.back());
	}
	cout << "Done...\n";

	cout << "Performing tests on modified deques.\n";

	cout << "Testing front() & back()\n";
	if (d.front() != r.front())
	{
		cout << "front() fail...\n"
				 << d.front() << " " << r.front() << endl;
		errorCount++;
	}
	if (d.back() != r.back())
	{
		cout << "back() fail\n"
				 << d.back() << " " << r.back() << endl;
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing empty()\n";
	if (d.empty() != r.empty())
	{
		cout << "empty() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing size()\n";
	if (d.size() != r.size())
	{
		cout << "size() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Emptying deques.\n";

	while (!d.empty())
	{
		d.pop_front();
		r.pop_front();
	}
	cout << "Done...\n";

	cout << "Performing tests on empty deques.\n";

	cout << "Testing front() & back()\n";
	if (d.front() != r.front())
	{
		cout << "front() fail...\n"
				 << d.front() << " " << r.front() << endl;
		errorCount++;
	}
	if (d.back() != r.back())
	{
		cout << "back() fail\n"
				 << d.back() << " " << r.back() << endl;
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing empty()\n";
	if (d.empty() != r.empty())
	{
		cout << "empty() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing size()\n";
	if (d.size() != r.size())
	{
		cout << "size() fail\n";
		errorCount++;
	}
	cout << "Done...\n";

	cout << "Testing completed with " << errorCount << " error(s).\n\n";
	return errorCount;
}

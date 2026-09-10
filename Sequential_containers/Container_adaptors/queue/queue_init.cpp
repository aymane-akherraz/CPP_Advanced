#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <vector>
using namespace std;

int main ()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//1. default constructor
	cout << "Default constructor:\n";
	queue < int >q1;
	if (q1.empty ())
	{
	 	q1.push (100);
	}
	cout << "Q1: " << q1.front() << endl;
	cout << "Size of queue: " << q1.size () << endl << endl;

	//2. copy constructor
	cout << "Copy constructor:\n";
	queue < int >q2 (q1);
	cout << "Q1: " << q1.front() << endl;
	cout << "Size of source queue: " << q1.size () << endl;
	cout << "Q2: " << q2.back() << endl;
	cout << "Size of destination queue: " << q2.size () << endl << endl;

	//3. initiilization using predefined container
	cout << "initiilization using predefined container:\n";
	deque < int >d1 (a1, a1 + 10);
	queue < int >q3 (d1);
	cout << "Size of queue: " << q3.size () << endl;
	while (!q3.empty())
	{
		cout << q3.front() << endl;
		q3.pop();
	}
	cout << endl;

	//4. using non-default storage
	queue < int, list < int >>q4;
	queue < int, vector < int >>q5;
	cout << "Using non-default storage:\n";
	q4.push(10);
	q5.push(q4.front());
	cout << "Q4: " << q4.front() << endl;
	cout << "Q5: " << q5.front() << endl;
	return 0;
}

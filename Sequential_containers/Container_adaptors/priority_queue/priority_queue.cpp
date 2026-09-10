#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main ()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//1. default constructor
	cout << "Default constructor:\n";
	priority_queue < int >q1;
	if (q1.empty ())
	{
	 	q1.push (100);
	}
	cout << "Q1: " << q1.top() << endl;
	cout << "Size of priority_queue: " << q1.size () << endl << endl;

	//2. copy constructor
	cout << "Copy constructor:\n";
	priority_queue < int >q2 (q1);
	cout << "Q1: " << q1.top() << endl;
	cout << "Size of source priority_queue: " << q1.size () << endl;
	cout << "Q2: " << q2.top() << endl;
	cout << "Size of destination priority_queue: " << q2.size () << endl << endl;

	//3. initiilization using predefined container
	cout << "initiilization using predefined container:\n";
	vector < int >v1 (a1, a1 + 10);
	priority_queue < int >q3 (v1.begin (), v1.end ());
	cout << "Size of priority_queue: " << q3.size () << endl;
	while (!q3.empty())
	{
		cout << q3.top() << endl;
		q3.pop();
	}
	cout << endl;

	//4. using non-default storage
	priority_queue < int, deque < int >>q4;
	cout << "Using non-default storage:\n";
	q4.push(10);
	cout << "Q4: " << q4.top() << endl << endl;

	//5. Providing different comparator type
	cout << "Providing different comparator type:\n";
	priority_queue < int, deque < int >, greater < int >>q5 (a1, a1 + 5);
	cout << "q5 queue top: " << q5.top () << endl;
	return 0;
}

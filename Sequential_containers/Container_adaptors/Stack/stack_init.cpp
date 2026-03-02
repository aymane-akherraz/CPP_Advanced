#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
using namespace std;

int main ()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	//1. default constructor
	cout << "Default constructor\n";
	stack < int >s1;
	s1.push(50);
	cout << "s1 size: " << s1.size() << endl;
	cout << "s1: " << s1.top() << endl << endl;

	cout << "Copy constructor\n";
	//2. copy constructor;
	stack < int >s2 (s1);
	cout << "s2 size: " << s2.size() << endl;
	cout << "s2: " << s2.top() << endl << endl;

	//3. initialization using predefined container
	cout << "Initialization using predefined container\n";
	deque < int >d1 (a1, a1 + 10);
	stack < int >s3 (d1);

	while (!s3.empty())
	{
		cout << s3.top() << endl;
		s3.pop();
	}
	cout << endl;

	//4. using nondefault storage
	stack < int, list < int >>s4;
	stack < int, vector < int >>s5;
	cout << "Using nondefault storage:\n";
	s4.push(11);
	s5.push(s4.top());
	cout << s4.top() << endl << s5.top() << endl;
	{
		int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		deque < int >d1 (a1, a1 + 10);

		stack < int >s1;

		stack < int >s2 (d1);
		//1. Correct - source and target stack are of the same type

		s1 = s2;
		cout << endl << "Copy assignement:" << endl;
		cout << "size s1:s2 - " << s1.size () << ":" << s2.size () << endl;

		stack < int, vector < int >>s3;

		//2. Incorrect - target and source stack are not of the same type

		//s3 = s2;	
	}
	return 0;
}

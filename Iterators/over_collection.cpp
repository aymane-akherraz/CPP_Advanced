#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;
	unsigned int n;
	cout << "Enter a number: ";
	if (cin >> n)
	{
		if (n % 2)
			n++;
		for (unsigned i = 1; i <= n; ++i)
		{
			if (i % 2)
				v1.push_back(i);
			else
				v2.push_back(i);
		}
	// Iterator-based nested loops (pre-C++11 style) :
	/* for (auto it1 = v1.begin(); it1 < v1.end(); ++it1)
		{
			for (auto it2 = v2.begin(); it2 < v2.end(); ++it2)
				cout << *it1 + *it2 << " ";
			cout << endl;
		} */

	// Range-based nested loops (C++11 and later) :
		for (auto x1 : v1)
		{
			for (auto x2 : v2)
				cout << x1 + x2 << " ";
			cout << endl;
		}

	// Range-based always iterates from begin to end so we can't use here in reverse
		for (auto it1 = v1.rbegin(); it1 < v1.rend(); ++it1)
		{
			for (auto it2 = v2.rbegin(); it2 < v2.rend(); ++it2)
				cout << *it1 + *it2 << " ";
			cout << endl;
		}
	}
	return 0;
}

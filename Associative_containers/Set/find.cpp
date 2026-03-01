#include <iostream>
#include <set>

using namespace std;

template <typename T>
void search(T& container, double value)
{
	typename T::iterator it = container.find(value);
	if (it != container.end())
    {
		for (; it != container.end(); ++it)
			cout << *it << " ";
		cout << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main ()
{
	set < double, greater < double >>A = { -1.1, 2.9, -2.3, 2.71 };
	set < double, greater < double >>B = { -3.14, 2.71, -3.88, 2.19 };

	double value;
	cout << "Enter value to search for: ";
	cin >> value;
	search(A, value);
	search(B, value);
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_found(T& c, int value)
{
	int count = 1;
	typename T::iterator found = search_n(c.begin(), c.end(), count, value);
	while (found != c.end())
	{
		cout << value << " found " << count << " times at: " << distance(c.begin(), found) << endl;
		found = search_n(found, c.end(), ++count, value);
	}
}

int main()
{
	vector<int> values =
		{ 11, 11, 21, 21, 30, 11, 11, 11, 17, 21, 21, 21, 11, 11, 11, 11 };
	print_found(values, 11);
	print_found(values, 21);
	return 0;
}

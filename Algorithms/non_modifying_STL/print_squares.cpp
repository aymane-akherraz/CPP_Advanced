#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_square(int & val)
{
	cout << val * val << " ";
}

int main()
{
	vector<int> v1 = { 3, 5, 6, 8, 9};
	for_each(v1.begin(), v1.end(), print_square);
	cout << endl;
	for_each(v1.rbegin(), v1.rend(), print_square);
	cout << endl;

	return 0;
}

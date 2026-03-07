#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class T>
void print(const T & value) 
{
	cout << value << " ";
}

int main()
{
	int t[]={1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4};
	vector <int> v1(t,t+18);
	for_each(v1.begin(), v1.end(), print<int>); cout << endl;

	cout << endl;
	cout << "Counting values 2:\n";
	unsigned int number = count(v1.begin(), v1.end(), 2);
	cout << "Number of items (2) found: " <<  number << endl;
	cout << endl;

	cout << "Counting values 10:\n";
	number = count(v1.begin(), v1.end(), 10);
	cout << "Number of items (10) found: " <<  number << endl;
	cout << endl;
	return 0;
}

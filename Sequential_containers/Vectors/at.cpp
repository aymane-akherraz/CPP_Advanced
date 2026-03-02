#include <vector>
#include <iostream>

using namespace std;

template < class C > void
print (const C & container)
{
	for (unsigned i = 0; i < container.size (); ++i)
	{
	  cout << container.at (i) << " ";
	}
	cout << endl;
}

int main ()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector < int >v (10);

	for (unsigned i = 0; i < 10; ++i)
	{
	  v.at (i) = a[i];
	}
	print (v);
	cout << "Accessing out of range element:\n";
	// Unlike operator[], at() throws an out_of_range exception if index is out of range
	try
	{
		cout << v.at (11) << endl;
	}
	catch (out_of_range & ex)
	{
		cout << ex.what () << endl;
	}

	return 0;
}

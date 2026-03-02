#include <deque>
#include <iostream>

using namespace std;

template < class I > void
print (const I & start, const I & end)
{
	for (I it = start; it != end; ++it)
	{
	  cout << *it << " ";
	}
	cout << endl;
}

int main ()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	deque < int >d;

	for (unsigned i = 0; i < 10; ++i)
	{
	  d.push_front (i);
	}
	cout << "Deque:  ";
	print (d.begin (), d.end ());

	for (unsigned i = 0; i < 5; ++i)
	{
	  d.pop_front ();
	}
	cout << "Deque:  ";
	print (d.begin (), d.end ());

	return 0;
}

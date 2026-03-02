#include <vector>
#include <deque>
#include <list>
#include <iostream>

using namespace std;

template < class I > void
print (const I & start, const I & end)
{
	I it;
	for (it = start; it != end; ++it)
	{
	  cout << *it << " ";
	}
	cout << endl;
}

int main ()
{
	// vector
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector < int >v (a, a + 10);

	vector < int >::iterator it = v.insert (v.begin () + 5, 100);
	print (v.begin (), v.end ());
	cout << "Inserted element: " << *it << endl;
	cout << "Size: " << v.size () << endl;

	vector < int >v2;
	v2.insert (v2.begin (), v.rbegin (), v.rend ());
	print (v2.begin (), v2.end ());

	vector < int >v3 (v.begin (), v.begin () + 5);
	v3.insert (v3.end (), 3, 100);

	print (v3.begin (), v3.end ());
	{
		// deque
		int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		deque < int >d1 (a, a + 10);

		deque < int >::iterator it = d1.insert (d1.begin () + 5, 100);
		print (d1.begin (), d1.end ());
		cout << "Inserted element: " << *it << endl;
		cout << "Size: " << d1.size () << endl;

		deque < int >d2;
		d2.insert (d2.begin (), d1.rbegin (), d1.rend ());
		print (d2.begin (), d2.end ());

		deque < int >d3 (d1.begin (), d1.begin () + 5);
		d3.insert (d3.end (), 3, 100);

		print (d3.begin (), d3.end ());
	}
	{
		// list
		int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		list < int >l1 (a, a + 10);

		list < int >::iterator it = l1.insert (l1.begin (), 100);
		print (l1.begin (), l1.end ());
		cout << "Inserted element: " << *it << endl;
		cout << "Size: " << l1.size () << endl;

		list < int >l2;
		l2.insert (l2.begin (), l1.rbegin (), l1.rend ());
		print (l2.begin (), l2.end ());

		list < int >::iterator it1 = l1.begin ();
		//shifting 5 places
		for (int i = 0; i < 5; ++i)
		{
		  ++it1;
		}
		list < int >l3 (l1.begin (), it1);
		l3.insert (l3.end (), 3, 100);

		print (l3.begin (), l3.end ());
	}
	return 0;
}

#include <set>
#include <iostream>

using namespace std;

template < class T > void
print (T start, T end)
{
	for (; start != end; ++start)
	{
	  std::cout << *start << " ";
	}
}

int main ()
{
	int t[] = { 9, 10, 8, 15, 6, 15, 3, 9, 7, 2 };
	multiset < int, greater < int >> s1 (t, t + 10);
	print (s1.begin (), s1.end ());
	cout << endl << endl;
	cout << "Removing element from a certain position (iterator):\n";
	multiset < int >::iterator it = s1.find (15);
	s1.erase (it);
	print (s1.begin (), s1.end ());
	cout << endl << endl;
	int val = 9;
	cout << "Removing all occurrences of value (" << val << ") from the multiset:\n";
	int r = s1.erase (val);
	if (r)
	{
		cout << "Found and removed " << r << " occurrences of value " << val << endl;
	}
	else
	{
		cout << "Value (" << val << ") is not in the set therefore not removed" << endl;
	}
	print (s1.begin (), s1.end ());
	cout << endl << endl;

	cout << "Removing range of iterators:\n";
	s1.erase (s1.find (6), s1.end ());
	print (s1.begin (), s1.end ());
	cout << endl << endl;

	cout << "Removing all the elements from the set\n";
	s1.clear ();
	cout << "S1 size: " << s1.size () << endl;
	return 0;
}

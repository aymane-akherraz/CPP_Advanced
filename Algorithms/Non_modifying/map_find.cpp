#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	map<string, string> capitals = { 
		{"China", "Beijing"}, 
		{"India", "New Delhi"}, 
		{"Japan", "Tokyo" },
		{"Philippines", "Manila" },
		{"Poland", "Warsaw" },
		{"Egypt", "Cairo" },
		{"Indonesia", "Jakarta" },
		{"Democratic Republic of the Congo", "Kinshasa" },
		{"South Korea", "Seoul" },
		{"Bangladesh", "Dhaka" },
		{"Iceland", "Reykjavík" }
	};
	string s;
	if (getline(cin, s))
	{
		map<string, string>::iterator it = capitals.find(s); // There is also set::find() which is similar to this one
		if (it != capitals.end())
			cout << "The capital of " << s << " is " << it->second << endl;
		else
			cout << "No country on the list" << endl;
	}
	return 0;
}

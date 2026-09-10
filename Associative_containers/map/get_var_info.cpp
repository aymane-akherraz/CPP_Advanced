#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main()
{
	
	map<string, int> vars_map = { {"x", 0}, {"y", 1}, {"z", 2}, 
			{ "xx", 3 },{ "xy", 4 },{ "xz", 5 } };
	vector<int> values = { 9, 6, 5, 7, 3, 2};
	string var_name;
	cin >> var_name;

	map<string, int>::const_iterator it = vars_map.find(var_name);
	if (it != vars_map.end())
	{
		cout << "Variable: " << it->first << " at address: "
			 << it->second << " has value: " << values[it->second]
			 << endl;
	}
	else
	{
		cout << "Variable: " << var_name << " doesn't exists!" << endl
			 << endl << "Available variables:" << endl;
		map<string, int>::const_iterator it = vars_map.begin();
		for (; it != vars_map.end(); ++it)
		{
			cout << "Variable: " << it->first << " at address: "
             << it->second << " has value: " << values[it->second]
             << endl;
		}
	}
	return 0;
}

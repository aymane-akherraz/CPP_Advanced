#include <iostream>
#include <map>
#include <string>

using namespace std;

void print(const map<string, int>& results)
{
	map<string, int>::const_iterator it = results.begin();
	for (; it != results.end(); ++it)
		cout << it->first << " result is : " << it->second << endl;
}
int main()
{
	map<string, int> results = { {"Sarah", 15 }, {"John", 12 }, {"Bart", 17} };
	print(results);
	cout << "\nErasing Bart: " << endl;
	results.erase("Bart");
	print(results);
	cout << "\nAdding Bob: " << endl;
	results["Bob"] = 16; // or: results.insert(pair <string, int>("Bob", 16));
	print(results);
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to print found pattern
void print_pattern(const vector<int>& original, const vector<int>& relations, const vector<int>& pattern)
{
	vector<int>::const_iterator it = relations.begin();
	while ((it = search(it, relations.end(), pattern.begin(), pattern.end())) != relations.end())
	{
		size_t index = distance(relations.begin(), it);
		cout << "Pattern found, values at " << index << " : ";
		for (size_t j = 0; j < pattern.size(); ++j)
    	    cout << original[index + j] << " ";
	    cout << endl;
		it++;
	}
}

int main() {
    vector<int> values = { 1, 1, 5, 3, 4, 4, 3, 2, 2, 4, 4, 5, 3, 8, 8, 1 };
    vector<int> relations;

    // Populate the relations vector based on consecutive values in the 'values' vector
    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] == values[i - 1])
            relations.push_back(0);
        else if (values[i] > values[i - 1])
            relations.push_back(1);
        else
            relations.push_back(-1);
    }

    // Define the two patterns to search for
    vector<int> pattern1 = { 0, 1, -1 };
    vector<int> pattern2 = { -1, 1, 0 };

    // Call the function to print found patterns
    print_pattern(values, relations, pattern1);
    print_pattern(values, relations, pattern2);

    return 0;
}

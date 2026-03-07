#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> original_values =
		{ 210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483 };
	vector<int> noisy_values =
		{ 211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 501 };

	pair<vector<int>::iterator, vector<int>::iterator> p = mismatch(original_values.begin(),
															original_values.end(), noisy_values.begin());
	int threshold = 14;
	while (p.first != original_values.end()
			&& p.second != noisy_values.end())
	{
		if (max(*(p.first), *(p.second)) - min(*(p.first), *(p.second))  > 15)
		{
			threshold++;	
			cout << "First difference greater than " << threshold << " is found: "
				 << *(p.first) << " - " << *(p.second) << endl;
		}
		p = mismatch(next(p.first), original_values.end(), next(p.second));
	}

	return 0;
}

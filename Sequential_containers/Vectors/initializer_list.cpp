#include <vector>
#include <iostream>

using namespace std;
int main ()
{
	float n;
	cout << "Enter a number: ";
	cin >> n;
	vector <float> v1 = {n, n + 5, n + 0.5f, n + 2.3f, n + 4.7f};
	float sum;
	for (float num : v1)
		sum += num;
	cout << "Sum: " << sum << endl;
	cout << "Avg: " << sum / v1.size() << endl;
	return 0;
}

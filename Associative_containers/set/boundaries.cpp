#include <iostream>
#include <set>

using namespace std;

template <typename T>
void print_sum(T& container, double start_value, double stop_value)
{
	typename T::iterator it1 = container.lower_bound(start_value);
	typename T::iterator it2 = container.upper_bound(stop_value);

	if (it1 == container.end() || it2 == container.end())
        cout << "Not found" << endl;
    else
	{
		double sum = 0.0;
		for (; it1 != it2; ++it1)
			sum += *it1;
		cout << sum << endl;
    }
}

int main ()
{
	set <double> A = { 1.1, 2.3, 2.7, 2.9, 3.5 };
	set <double> B = { 2.5, 2.7, 3.14, 3.5, 4.5 };
	double start_value;
	cout << "Enter start value: ";
	cin >> start_value;
	cout << "Enter stop value: ";
	double stop_value;
	cin >> stop_value;
	print_sum(A, start_value, stop_value);
	print_sum(B, start_value, stop_value);
	return 0;
}

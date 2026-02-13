#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
int signum(T x)
{
	if (x < 0)
		return -1;
	else if (x == 0)
		return 0;
	else
		return 1;
}

template <typename T>
void toString(T x, int r)
{
	ostringstream oss;
	if (oss << r)
		cout << "sgn(" << x << ") = " << oss.str() << endl;
}

int main() {
	
	int i;
	double d;
	string line;

	cout << "Enter a number: ";
	if (getline(cin, line))
	{
		istringstream iss(line);
		if (iss >> d)
			toString(d, signum(d));
		else if (iss >> i)
			toString(i, signum(i));
		else
			cerr << "Invalid number!" << endl;
	}
	return 0;
}

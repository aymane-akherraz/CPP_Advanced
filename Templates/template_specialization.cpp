#include <iostream>
#include <vector>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	int getX() const { return x; }
	int getY() const { return y; }
	Point(int x, int y) : x(x), y(y) {}
};

template <typename T>
int signum(T x) // Template function
{
	if (x < 0)
		return -1;
	else if (x == 0)
		return 0;
	else
		return 1;
}
template <> int signum(Point a) // full specialization of signum
{
	if (signum(a.getX()) == -1 && signum(a.getY()) == -1)
		return -1;
	if (signum(a.getX()) == 1 && signum(a.getY()) == 1)
		return 1;
	return 0;
}

/*
	Note that if a matching non-template function and a matching template
	function specialization both exist, the non-template function will take
	precedence.
*/

int signum(Point value) // This non-template function will take precedence
{
	if (signum(value.getX())< 0 && signum(value.getY())< 0)
			return -1;
	if (signum(value.getX())> 0 && signum(value.getY())> 0)
		return 1;
	return 0;
}
int main() {
	
	int valuei = -5;
	vector <Point> points = { { -1, 2 },{ -3, -5 },{ 2, 2 } };

	cout << "Value: " << valuei << " sgn: " << signum(valuei) << endl;
	for(auto point: points)
		cout << "Point: " << point.getX() << ", " << point.getY() << " sgn:" << signum(point) << endl;

	return 0;
}

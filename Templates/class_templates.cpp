#include <iostream>

using namespace std;

template <typename T, typename U>
class Point
{
public:
	T x;
	U y;
	Point(const T& x, const U& y)
		: x(x), y(y)
	{
	}
	template <typename A, typename B>
	void add_point(const Point<A, B>& point);
	void add_point(U val);
};


template <typename T, typename U>
template <typename A, typename B>
void Point<T,U>::add_point(const Point<A, B>& point)
{
    x += point.x;
    y += point.y;
}

template <typename T, typename U>
void Point<T,U>::add_point(U val)
{
    x += val;
    y += val;
}


int main()
{
	Point p1(1, 1);
	Point p2(2.1, 2.3);
	cout << "P1: " << p1.x << ":" << p1.y << endl;
	cout << "P2: " << p2.x << ":" << p2.y << endl;
	Point p3(1, 1);
	p1.add_point(p2);
	p2.add_point(1);
	cout << "P1: " << p1.x << ":" << p1.y << endl;
	cout << "P2: " << p2.x << ":" << p2.y << endl;
	return 0;
}

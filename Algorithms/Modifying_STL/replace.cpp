#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int> &v)
{
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";
}

bool is_even(int x)
{
    return x % 2 == 0;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 2, 4, 5, 6};

    std::cout << "Original: ";
    print(v);

    // Replace every 2 with 99
    std::replace(v.begin(), v.end(), 2, 99);

    std::cout << "After replace: ";
    print(v);

    // Replace every even number with 0
    std::replace_if(v.begin(), v.end(), is_even, 0);

    std::cout << "After replace_if: ";
    print(v);

    return 0;
}
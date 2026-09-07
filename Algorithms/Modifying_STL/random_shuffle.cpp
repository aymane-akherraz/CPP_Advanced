#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void print(const std::vector<int>& v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    std::cout << "Original: ";
    print(v);

    std::srand(std::time(0));

    std::random_shuffle(v.begin(), v.end());

    std::cout << "Shuffled: ";
    print(v);

    return 0;
}
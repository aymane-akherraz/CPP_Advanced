#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<int>& v)
{
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v = {1, 1, 2, 2, 2, 3, 3, 4, 1};

    std::cout << "Original: ";
    print(v);

    // unique modifies the original vector
    std::vector<int>::iterator it;
    it = std::unique(v.begin(), v.end());

    std::cout << "After unique: ";
    print(v);

    std::cout << "Unique part: ";
    for (std::vector<int>::iterator i = v.begin(); i != it; ++i)
        std::cout << *i << " ";
    std::cout << "\n";


    // unique_copy copies the unique elements into another container
    std::vector<int> result;

    std::unique_copy(v.begin(), v.end(), std::back_inserter(result));

    std::cout << "After unique_copy: ";
    print(result);

    return 0;
}
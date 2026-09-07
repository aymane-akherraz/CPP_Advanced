#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> scores;

    // Group 1: already sorted
    scores.push_back(10);
    scores.push_back(30);
    scores.push_back(50);
    scores.push_back(70);

    // Group 2: already sorted
    scores.push_back(20);
    scores.push_back(40);
    scores.push_back(60);
    scores.push_back(80);

    cout << "Before inplace_merge: ";

    for (vector<int>::iterator it = scores.begin();
         it != scores.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    inplace_merge(scores.begin(),
                  scores.begin() + 4,
                  scores.end());

    cout << "After inplace_merge:  ";

    for (vector<int>::iterator it = scores.begin();
         it != scores.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "Hello world!";
    for (int i = 0; i < s.size(); ++i)
    {
        cout.put(s[i]);
    }
    cout.put('\n');

    return 0;
}
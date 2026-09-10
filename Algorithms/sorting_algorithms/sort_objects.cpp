#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person
{
public:
    int age;
    int score;
    string name;

    Person(int age, int score, string name)
        : age(age), score(score), name(name)
    {
    }

    Person()
    {
    }
};

void print(const Person& p)
{
    cout << p.name << " ";
}

bool ascending_age(const Person& a, const Person& b)
{
    return a.age < b.age;
}

bool ascending_age_score(const Person& a, const Person& b)
{
    return a.age + a.score < b.age + b.score;
}

int main()
{
    vector<Person> v;

    v.push_back(Person(20, 10, "John"));
    v.push_back(Person(18, 30, "Alice"));
    v.push_back(Person(25, 5, "Bob"));
    v.push_back(Person(22, 15, "Charlie"));
    v.push_back(Person(30, 20, "David"));

    cout << "Source collection:\n";
    cout << "v: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;

    cout << "Sorting by age:\n";

    stable_sort(v.begin(), v.end(), ascending_age);

    cout << "v: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;

    cout << "Sorting by age + score:\n";

    sort(v.begin(), v.end(), ascending_age_score);

    cout << "v: ";
    for_each(v.begin(), v.end(), print);
    cout << endl;

    return 0;
}
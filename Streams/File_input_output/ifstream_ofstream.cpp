#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
string getStatus(const T &stream)
{
    ostringstream s;

    if (stream.is_open())
        s << "Stream is open";
    else
        s << "Stream is closed";

    return s.str();
}

string getFlags(const ios &stream)
{
    ostringstream s;

    s << boolalpha
      << "G:" << setw(5) << left << stream.good()
      << " E:" << setw(5) << left << stream.eof()
      << " F:" << setw(5) << left << stream.fail()
      << " B:" << setw(5) << left << stream.bad();

    return s.str();
}

int main()
{
    const char *firstFile = "badfilename.txt";
    const char *dataFile = "inputfile03.txt";

    // Create an empty file.
    ofstream badFile(firstFile);
    badFile.close();

    // Create a file containing integers.
    ofstream goodFile(dataFile);
    goodFile << "10 20 30 40 50";
    goodFile.close();

    cout << "Opening an existing file: " << firstFile << '\n';

    ifstream file(firstFile);

    cout << "Status: " << getStatus(file) << '\n';
    cout << "Flags: " << getFlags(file) << "\n\n";

    cout << "Reusing the same stream to open another file: "
         << dataFile << '\n';

    file.close(); // Must close the current file before reusing the stream; otherwise, open() will fail.
    file.open(dataFile);

    cout << "Status: " << getStatus(file) << '\n';
    cout << "Flags: " << getFlags(file) << "\n\n";

    cout << "Reading with: while (file >> v)\n";

    int v;

    while (file >> v)
        cout << v << ": flags: " << getFlags(file) << '\n';

    cout << "After failed read:\n";
    cout << "Flags: " << getFlags(file) << "\n\n";

    file.close();

    cout << "Reading with: while (file.good())\n";
    cout << "(Demonstrates why this is not the preferred pattern.)\n";

    file.open(dataFile);

    while (file.good())
    {
        file >> v;
        cout << v << ": flags: " << getFlags(file) << '\n';
    }

    cout << "After failed read:\n";
    cout << "Flags: " << getFlags(file) << '\n';

    file.close();

    return 0;
}
